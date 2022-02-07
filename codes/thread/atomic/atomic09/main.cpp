#include <iostream>
#include <atomic>
#include <mutex>

template <class T>
class TestAtomic
{
private:
    mutable std::mutex mtx;
    int data;
public:
    int store(int val)
    {
        std::lock_guard lk(mtx);
        data = val;
        return data;
    }

    int load() const
    {
        std::lock_guard lk(mtx);
        return data;
    }

    int fetch_add(int val)
    {
        std::lock_guard lk(mtx);
        int old_value = data;
        data += val;
        return old_value;
    }

    int exchange(int val)
    {
        std::lock_guard lk(mtx);
        int old_value = data;
        data = val;
        return old_value;
    }

    bool compare_exchange_strong(int &old_value, int val)
    {
        std::lock_guard lk(mtx);
        if ( data == old_value )
        {
            data = val;
            return true;
        }
        else
        {
            old_value = data;
            return false;
        }
    }
};


int main( int argc, char **argv )
{
    std::cout << std::boolalpha;
    TestAtomic<int> sum;

    sum.store(2);

    int v1 = 1;
    bool return_flag = sum.compare_exchange_strong(v1, 3);
    std::cout << "return_flag=" << return_flag << std::endl;
    std::cout << "v1=" << v1 << std::endl;

    int v2 = sum.load();
    std::cout << "v2=" << v2 << std::endl;

    v1 = 2;
    return_flag = sum.compare_exchange_strong(v1, 3);
    std::cout << "return_flag=" << return_flag << std::endl;
    std::cout << "v1=" << v1 << std::endl;

    v2 = sum.load();
    std::cout << "v2=" << v2 << std::endl; 

    return 0;
}