#include <cctype>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <tbb/tick_count.h>
#include <tbb/parallel_pipeline.h>
#include <tbb/concurrent_queue.h>
#include <tbb/parallel_for.h>

using CaseStringPtr = std::shared_ptr<std::string>;
CaseStringPtr getCaseString(std::ofstream& f); 
void writeCaseString(std::ofstream& f, CaseStringPtr s);

void fig_2_24( std::ofstream& caseBeforeFile, std::ofstream& caseAfterFile )
{
    std::size_t icount = 0;
    while ( CaseStringPtr s_ptr = getCaseString(caseBeforeFile) )
    {
        std::cout << " fig_2_24 s_ptr->size() = " << s_ptr->size() << " icount = " << icount << std::endl;
        ++ icount;
        std::transform(s_ptr->begin(), s_ptr->end(), s_ptr->begin(), 
          [](char c) -> char {
            if ( std::islower(c) )
                return std::toupper(c);
            else if ( std::isupper(c) )
                return std::tolower(c);
            else
                return c;
          }
        );
        writeCaseString( caseAfterFile, s_ptr );
    }
}

void fig_2_27(int num_tokens, std::ofstream& caseBeforeFile, std::ofstream& caseAfterFile) {
  tbb::parallel_pipeline(
    /* tokens */ num_tokens,
    /* the get filter */
    tbb::make_filter<void, CaseStringPtr>(
      /* filter node */ tbb::filter_mode::serial_in_order,
      /* filter body */
      [&](tbb::flow_control& fc) -> CaseStringPtr {
        CaseStringPtr s_ptr = getCaseString(caseBeforeFile);
        if (!s_ptr) 
          fc.stop();
        return s_ptr; 
      }) & // concatenation operation
    /* make the change case filter */
    tbb::make_filter<CaseStringPtr, CaseStringPtr>(tbb::filter_mode::parallel,
      []( CaseStringPtr s_ptr ) -> CaseStringPtr {
        std::transform(s_ptr->begin(), s_ptr->end(), s_ptr->begin(), 
          [](char c) -> char {
            if (std::islower(c))
              return std::toupper(c);
            else if (std::isupper(c))
              return std::tolower(c);
            else
              return c;
          });
        return s_ptr;
      }) & // concatenation operation
    /* make the write filter */
    tbb::make_filter<CaseStringPtr, void>( tbb::filter_mode::serial_in_order,
      [&]( CaseStringPtr s_ptr ) -> void {
          writeCaseString( caseAfterFile, s_ptr );
      }) 
  );
}

using CaseStringPtr = std::shared_ptr<std::string>;
static tbb::concurrent_queue<CaseStringPtr> caseFreeList;
static int numCaseInputs = 0;

void initCaseChange( int num_strings, int string_len, int free_list_size )
{
    numCaseInputs = num_strings;
    caseFreeList.clear();
    for ( int i = 0; i < free_list_size; ++ i )
    {
        caseFreeList.push( std::make_shared<std::string>(string_len, ' ') );
    }
}

CaseStringPtr getCaseString( std::ofstream& f )
{
    std::shared_ptr<std::string> s;
    if ( numCaseInputs > 0 )
    {
        if ( !caseFreeList.try_pop(s) || !s )
        {
            std::cerr << "Error: Ran out of elements in free list!" << std::endl;
            return CaseStringPtr{};
        }
        int ascii_range = 'z' - 'A' + 2;
        for ( int i = 0; i < s->size(); ++ i )
        {
            int offset = i % ascii_range;
            if ( offset )
            {
                (*s)[ i ] = 'A' + offset - 1; 
            }
            else
            {
                (*s)[ i ] = '\n';
            }
        }

        if ( f.good() )
        {
            f << *s;
        }
        -- numCaseInputs;
    }
    return s;
}

void writeCaseString( std::ofstream& f, CaseStringPtr s )
{
    if ( f.good() )
    {
        f << *s;
    }
    caseFreeList.push( s );
}

static void warmupTBB()
{
    tbb::parallel_for( 0, oneapi::tbb::info::default_concurrency(), [](int) {
        tbb::tick_count t0 = tbb::tick_count::now();
        while ( (tbb::tick_count::now() - t0).seconds() < 0.01 );
    });
}

int main( int argc, char **argv )
{
    size_t n0 = 1 << 0;
    size_t n1 = 1 << 1;
    size_t n2 = 1 << 2;
    size_t n3 = 1 << 3;
    std::cout << " n0 = " << n0 << std::endl;
    std::cout << " n1 = " << n1 << std::endl;
    std::cout << " n2 = " << n2 << std::endl;
    std::cout << " n3 = " << n3 << std::endl;

    size_t n = 1 << 10;
    std::cout << " n  = " << n << std::endl;
    {
        int num_strings = 100; 
        int string_len = 100000;
        int free_list_size = 1;
        std::ofstream caseBeforeFile("fig_2_24_before.txt");
        std::ofstream caseAfterFile("fig_2_24_after.txt");
        initCaseChange( num_strings, string_len, free_list_size );
        double serial_time = 0.0;
        {
            tbb::tick_count t0 = tbb::tick_count::now();
            fig_2_24(caseBeforeFile, caseAfterFile);
            serial_time = (tbb::tick_count::now() - t0).seconds();
        }
        std::cout << "serial_time == " << serial_time << " seconds" << std::endl;
    }
    {
        int num_tokens = oneapi::tbb::info::default_concurrency();
        int num_strings = 100; 
        int string_len = 100000;
        int free_list_size = num_tokens;
        
        std::ofstream caseBeforeFile("fig_2_27_before.txt");
        std::ofstream caseAfterFile("fig_2_27_after.txt");
        initCaseChange( num_strings, string_len, free_list_size );
        
        warmupTBB();
        double parallel_time = 0.0;
        {
            tbb::tick_count t0 = tbb::tick_count::now();
            fig_2_27( num_tokens, caseBeforeFile, caseAfterFile );
            parallel_time = (tbb::tick_count::now() - t0).seconds();
        }
        std::cout << "parallel_time == " << parallel_time << " seconds" << std::endl;
    }

    return 0;
}

