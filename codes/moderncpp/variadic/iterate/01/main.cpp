#include <iostream>

template <class... Ts>
void print_all(std::ostream& os, Ts const&... args) {
    ((os << args << "\n" ), ... );
}

int main( int argc, char **argv )
{
    {
        print_all(std::cout, 1, 2, 3);
        print_all(std::cout, 1, "Project::execute_dir", 3);
    }
    return 0;
}
