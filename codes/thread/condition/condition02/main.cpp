#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

int main( int argc, char **argv )
{
    std::condition_variable cv;
    std::mutex mtx;
    bool ready = false;

    std::thread th1([&] {
        std::unique_lock lck(mtx);
        cv.wait(lck, [&] { return ready; });

        std::cout << "th1 is awake" << std::endl;
    });

    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    std::cout << "notifying not ready" << std::endl;
    cv.notify_one();  // useless now, since ready = false

    ready = true;
    std::cout << "notifying ready" << std::endl;
    cv.notify_one();  // awakening th1, since ready = true

    th1.join();
    return 0;
}
