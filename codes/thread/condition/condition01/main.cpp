#include <iostream>
#include <thread>
#include <vector>
#include <shared_mutex>

class MutexVector
{
public:
    class MVAccessor {
        MutexVector &mVector;
        std::unique_lock<std::shared_mutex> grd;

    public:
        MVAccessor(MutexVector &mv)
            : mVector(mv), grd(mv.mtx)
        {}

        void push_back(int val) const {
            return mVector.data.push_back(val);
        }

        size_t size() const {
            return mVector.data.size();
        }
    };
    MVAccessor access() {
        return {*this};
    }
private:
    std::vector<int> data;
    mutable std::shared_mutex mtx;
};

int main( int argc, char **argv )
{
    const int nSize = 1000;
    MutexVector myarray;
    std::thread th1([&] {
        auto accessor = myarray.access();
        for ( int i = 0; i < nSize; ++ i )
        {
            accessor.push_back( 0 );
        }
    });
    std::thread th2([&] {
        auto accessor = myarray.access();
        for ( int i = 0; i < nSize; ++ i )
        {
            accessor.push_back( 1 );
        }
    });
    th1.join();
    th2.join();
    std::cout << "myarray.access().size() = " << myarray.access().size() << std::endl;
    return 0;
}
