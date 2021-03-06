#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

int main( int argc, char **argv )
{
    std::condition_variable cv;
    std::mutex mtx;
    std::thread th1([&] {
        std::unique_lock lck(mtx);
        cv.wait(lck);

        std::cout << "th1 is awake" << std::endl;
    });

    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    std::cout << "notifying..." << std::endl;
    cv.notify_one();

    th1.join();
    return 0;
}
