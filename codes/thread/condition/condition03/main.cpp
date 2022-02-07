#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

int main( int argc, char **argv )
{
    std::condition_variable cv;
    std::mutex mtx;

    std::thread th1([&] {
        std::unique_lock lk(mtx);
        cv.wait(lk);
        std::cout << "th1 finished waiting" << std::endl;
    });

    std::thread th2([&] {
        std::unique_lock lk(mtx);
        cv.wait(lk);
        std::cout << "th2 finished waiting" << std::endl;
    });

    std::thread th3([&] {
        std::unique_lock lk(mtx);
        cv.wait(lk);
        std::cout << "th3 finished waiting" << std::endl;
    });

    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    std::cout << "notifying one" << std::endl;
    cv.notify_one();

    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    std::cout << "notifying all" << std::endl;
    cv.notify_all();

    th1.join();
    th2.join();
    th3.join();

    return 0;
}
