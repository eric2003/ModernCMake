#include <iostream>
#include <vector>

template <typename F>
void foo( F const &f )
{
    for ( int i = 0; i < 4; ++ i )
    {
        f( i );
        f( i + 0.5f );
    }
}

int main( int argc, char **argv )
{
    std::vector<int> res_i;
    std::vector<float> res_f;
    foo( [&] (auto const &x) {
        using T = std::decay_t<decltype(x)>;
        if constexpr ( std::is_same_v<T, int> )
        {
            std::cout << " std::is_same_v<T, int> " << std::endl;
            res_i.push_back(x);
        }
        else if constexpr ( std::is_same_v<T, float> )
        {
            std::cout << " std::is_same_v<T, float> " << std::endl;
            res_f.push_back(x);
        }
    });
    std::cout << res_i.size() << std::endl;
    std::cout << res_f.size() << std::endl;

    return 0;
}
