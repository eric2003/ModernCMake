#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

template <class T>
class MutexQueue
{
private:
    std::condition_variable cv;
    std::mutex mtx;
    std::vector<T> data;
public:
    T pop()
    {
        std::unique_lock lck(mtx);
        cv.wait(lck, [this] { return !data.empty(); });
        T ret = std::move(data.back());
        data.pop_back();
        return ret;
    }

    auto pop_hold()
    {
        std::unique_lock lck(mtx);
        cv.wait(lck, [this] { return !data.empty(); });
        T ret = std::move(data.back());
        data.pop_back();
        return std::pair(std::move(ret), std::move(lck));
    }

    void push(T val) {
        std::unique_lock lck(mtx);
        data.push_back(std::move(val));
        cv.notify_one();
    }

    void push_many(std::initializer_list<T> vals)
    {
        std::unique_lock lck(mtx);
        std::copy(
                 std::move_iterator(vals.begin()),
                 std::move_iterator(vals.end()),
                 std::back_insert_iterator(data));
        cv.notify_all();
    }
};

MutexQueue<int> foods;
void customer( int id )
{
    for (int i = 0; i < 2; i++) {
        auto food = foods.pop();
        std::cout << "th" << id + 1 <<  " got food:" << food << std::endl;
    }
}

int main() {
    std::thread th1( customer, 0 );
    std::thread th2( customer, 1 );
    foods.push(1);
    foods.push(2);
    foods.push_many({4, 5});
    th1.join();
    th2.join();

    return 0;
}

