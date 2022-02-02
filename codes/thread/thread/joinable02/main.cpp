#include <iostream>
#include <thread>
#include <chrono>
 
void foo()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
 
int main()
{
    std::thread t;
    std::cout << "before starting, joinable: " << std::boolalpha << t.joinable()
              << '\n';
    std::thread::id th_id = t.get_id();
    std::cout << "th_id's id: " << th_id << std::endl;
 
    t = std::thread(foo);
    std::cout << "after starting, joinable: " << t.joinable() 
              << '\n';
    th_id = t.get_id();
    std::cout << "after starting, th_id's id: " << th_id << std::endl; 
 
    t.join();
    std::cout << "after joining, joinable: " << t.joinable() 
              << '\n';
    th_id = t.get_id();
    std::cout << "after joining, th_id's id: " << th_id << std::endl; 
}