#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::condition_variable cv;
std::mutex mtx;

std::vector<int> foods;
void customer( int id )
{
    for (int i = 0; i < 2; i++) {
        std::unique_lock lck(mtx);
        cv.wait(lck, [&] {
            return foods.size() != 0;
        });
        auto food = foods.back();
        foods.pop_back();
        lck.unlock();

        std::cout << "th" << id + 1 <<  " got food:" << food << std::endl;
    }
}
int main() {
    std::thread th1( customer, 0 );
    std::thread th2( customer, 1 );

    foods.push_back(1);
    foods.push_back(2);
    foods.push_back(3);
    cv.notify_one();

    foods.push_back(4);
    foods.push_back(5);
    cv.notify_all();
    std::cout << "foods.size() = " << foods.size() << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    std::cout << "wait a minute foods.size() = " << foods.size() << std::endl;
    foods.push_back(6);
    foods.push_back(7);
    foods.push_back(8);
    cv.notify_one();
    std::cout << "now foods.size() = " << foods.size() << std::endl;

    th1.join();
    th2.join();

    return 0;
}

