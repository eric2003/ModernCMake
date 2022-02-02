#include <iostream>
#include <thread>
#include <chrono>
 
void foo()
{
    std::cout << "foo's thread id: " << std::this_thread::get_id() << std::endl;
    //std::this_thread::sleep_for(std::chrono::seconds(2));
}
 
int main()
{
    std::thread th( foo );
    std::cout << "main thread id: " << std::this_thread::get_id() << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::thread::id th_id = th.get_id();
 
    std::cout << "th's id: " << th_id << '\n';
 
    th.join();

    return 0;
}