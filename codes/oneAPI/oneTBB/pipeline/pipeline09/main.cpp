#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <tbb/tick_count.h>
#include <tbb/parallel_pipeline.h>
#include <tbb/concurrent_queue.h>
#include <tbb/parallel_for.h>

using shared_string = std::shared_ptr<std::string>;
shared_string GenerateString(std::ofstream& file); 
void WriteFile(std::ofstream& file, shared_string sstr);

static tbb::concurrent_queue<shared_string> shared_string_list;
static int numInputStrings = 0;

char trans_char( char c )
{
    if ( std::islower( c ) )
    {
        return std::toupper( c );
    }
    else if ( std::isupper( c ) )
    {
        return std::tolower( c );
    }
    else
    {
        return c;
    }
}

void serial_transform( std::ofstream& originalFile, std::ofstream& resultFile )
{
    while ( shared_string sstr = GenerateString(originalFile) )
    {
        std::transform( sstr->begin(), sstr->end(), sstr->begin(), trans_char );
        WriteFile( resultFile, sstr );
    }
}

void parallel_transform(int num_tokens, std::ofstream& originalFile, std::ofstream& resultFile)
{
    tbb::parallel_pipeline(num_tokens,
        tbb::make_filter<void, shared_string>(tbb::filter_mode::serial_in_order,
        [&](tbb::flow_control& fc) -> shared_string {
            shared_string sstr = GenerateString(originalFile);
            if ( !sstr ) 
                fc.stop();
            return sstr; 
        }) & 
        tbb::make_filter<shared_string, shared_string>(tbb::filter_mode::parallel,
        []( shared_string sstr ) -> shared_string {
            std::transform(sstr->begin(), sstr->end(), sstr->begin(), trans_char );
            return sstr;
        }) & 
        tbb::make_filter<shared_string, void>( tbb::filter_mode::serial_in_order,
        [&]( shared_string sstr ) -> void {
            WriteFile( resultFile, sstr );
        }) 
    );
}

void initialize( int num_strings, int string_len, int free_list_size )
{
    numInputStrings = num_strings;
    shared_string_list.clear();
    for ( int i = 0; i < free_list_size; ++ i )
    {
        shared_string_list.push( std::make_shared<std::string>(string_len, ' ') );
    }
}

shared_string GenerateString( std::ofstream& file )
{
    std::shared_ptr<std::string> sstr;
    if ( numInputStrings > 0 )
    {
        if ( !shared_string_list.try_pop(sstr) || !sstr )
        {
            std::cerr << "Error: Ran out of elements in free list!" << std::endl;
            return shared_string{};
        }
        int ascii_range = 'z' - 'A' + 2;
        for ( int i = 0; i < sstr->size(); ++ i )
        {
            int offset = i % ascii_range;
            if ( offset )
            {
                (*sstr)[ i ] = 'A' + offset - 1; 
            }
            else
            {
                (*sstr)[ i ] = '\n';
            }
        }

        if ( file.good() )
        {
            file << *sstr;
        }
        -- numInputStrings;
    }
    return sstr;
}

void WriteFile( std::ofstream& file, shared_string sstr )
{
    if ( file.good() )
    {
        file << *sstr;
    }
    shared_string_list.push( sstr );
}

int main( int argc, char **argv )
{
    int num_strings = 100; 
    int string_len = 100000;
    {
        int free_list_size = 1;
        std::ofstream originalFile("serial_original.txt");
        std::ofstream resultFile("serial_result.txt");
        initialize( num_strings, string_len, free_list_size );
        double serial_time = 0.0;
        {
            tbb::tick_count t0 = tbb::tick_count::now();
            serial_transform(originalFile, resultFile);
            serial_time = (tbb::tick_count::now() - t0).seconds();
        }
        std::cout << "serial_time == " << serial_time << " seconds" << std::endl;
    }
    {
        int num_tokens = oneapi::tbb::info::default_concurrency();
        int free_list_size = num_tokens;
        
        std::ofstream originalFile("parallel_original.txt");
        std::ofstream resultFile("parallel_result.txt");
        initialize( num_strings, string_len, free_list_size );
        
        double parallel_time = 0.0;
        {
            tbb::tick_count t0 = tbb::tick_count::now();
            parallel_transform( num_tokens, originalFile, resultFile );
            parallel_time = (tbb::tick_count::now() - t0).seconds();
        }
        std::cout << "parallel_time == " << parallel_time << " seconds" << std::endl;
    }

    return 0;
}

