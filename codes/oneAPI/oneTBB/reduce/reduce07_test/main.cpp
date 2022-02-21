#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <tbb/task_group.h>

int main( int argc, char **argv )
{
    //size_t n = 1 << 26;
	size_t n = 1 << 4;
    size_t n0 = 1 << 0;
    size_t n1 = 1 << 1;
    size_t n2 = 1 << 2;
    size_t n3 = 1 << 3;
    std::cout << " n = " << n << std::endl;
    std::cout << " n0 = " << n0 << std::endl;
    std::cout << " n1 = " << n1 << std::endl;
    std::cout << " n2 = " << n2 << std::endl;
    std::cout << " n3 = " << n3 << std::endl;

    std::vector<float> a(n);
    auto t0 = std::chrono::steady_clock::now();

    size_t nTask = 4;
    size_t dn = n / nTask;
	std::cout << " dn = " << dn << std::endl;
    tbb::task_group tg1;
    std::vector<float> tmp_sum(nTask);

    for ( size_t iTask = 0; iTask < nTask; ++ iTask )
    {
        size_t beg = iTask * dn;
        size_t end = std::min( n, (iTask + 1) * dn );
        std::cout << "tg1 beg,end = " << beg << " " << end << std::endl;
        tg1.run( [&, iTask, beg, end] {
            float local_sum = 0;
            for ( size_t i = beg; i < end; ++ i )
            {
                local_sum += std::sin(i);
            }
            tmp_sum[ iTask ] = local_sum;
        });
    }
    tg1.wait();

    float sum = 0;
    for ( size_t iTask = 0; iTask < nTask; ++ iTask )
    {
        tmp_sum[iTask] += sum;
        sum = tmp_sum[iTask];
    }

    tbb::task_group tg2;
    for ( size_t iTask = 1; iTask < nTask; ++ iTask )
    {
        size_t beg = iTask * dn - 1;
        size_t end = std::min( n, (iTask + 1) * dn ) - 1;
        std::cout << "tg2 beg,end = " << beg << " " << end << std::endl;
        tg2.run([&, iTask, beg, end] {
            float local_sum = tmp_sum[ iTask ];
            for ( size_t i = beg; i < end; ++ i )
            {
                local_sum += std::sin(i);
                a[i] = local_sum;
            }
        });
    }
    tg2.wait();

    std::cout << "a["<< n / 2 << "] = " << a[n / 2] << std::endl;
    std::cout << " sum = " << sum << std::endl;

    auto t1 = std::chrono::steady_clock::now();
    auto dt = t1 - t0;
    int64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(dt).count();
    std::cout << "time elapsed: " << ms << " ms" << std::endl;

    return 0;
}

