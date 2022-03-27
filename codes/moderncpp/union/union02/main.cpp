#include <iostream>
 
class VECTOR3D
{
public:
    // operations, etc...

    union
    {
        float m[3];

        struct
        {
            float x, y, z;
        };
    }; 
};


int main( int argc, char **argv )
{
    {
        VECTOR3D v;
        // same effect
        v.m[0] = 1.0f;
        v.m[1] = 2.0f;
        v.m[2] = 3.0f;
        v.x = 1.0f;
        std::cout << " v.m[0] = " << v.m[0] << std::endl;
        std::cout << " v.m[1] = " << v.m[1] << std::endl;
        std::cout << " v.m[2] = " << v.m[2] << std::endl;
        std::cout << " v.x = " << v.x << std::endl;
        std::cout << " v.y = " << v.y << std::endl;
        std::cout << " v.z = " << v.z << std::endl;
    }

    return 0;
}
