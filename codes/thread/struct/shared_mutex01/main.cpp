#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
 
class ThreadSafeCounter
{
public:
    ThreadSafeCounter() = default;
 
    // Multiple threads/readers can read the counter's value at the same time.
    unsigned int get() const {
      std::shared_lock lock(mutex_);
      return value_;
    }
 
    // Only one thread/writer can increment/write the counter's value.
    unsigned int increment() {
      std::unique_lock lock(mutex_);
      return ++value_;
    }
 
    // Only one thread/writer can reset/write the counter's value.
    void reset() {
      std::unique_lock lock(mutex_);
      value_ = 0;
    }
 
private:
    mutable std::shared_mutex mutex_;
    unsigned int value_ = 0;
};
 
int main( int argc, char **argv )
{
    ThreadSafeCounter counter;
    
    auto increment_and_print = [&counter]() {
        for ( int i = 0; i < 3; ++ i )
        {
            std::cout << std::this_thread::get_id() << ' ' << counter.increment() << '\n';
            // Note: Writing to std::cout actually needs to be synchronized as well
            // by another std::mutex. This has been omitted to keep the example small.
        }
    };
    
    std::thread thread1(increment_and_print);
    std::thread thread2(increment_and_print);
    
    thread1.join();
    thread2.join();
    return 0;
}
 
// Explanation: The output below was generated on a single-core machine. When
// thread1 starts, it enters the loop for the first time and calls increment()
// followed by get(). However, before it can print the returned value to
// std::cout, the scheduler puts thread1 to sleep and wakes up thread2, which
// obviously has time enough to run all three loop iterations at once. Back to
// thread1, still in the first loop iteration, it finally prints its local copy
// of the counter's value, which is 1, to std::cout and then runs the remaining
// two loop iterations. On a multi-core machine, none of the threads is put to
// sleep and the output is more likely to be in ascending order.