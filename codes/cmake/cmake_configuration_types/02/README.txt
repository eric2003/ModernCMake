cmake ..
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake -DCMAKE_CONFIGURATION_TYPES="Debug;Release" ..

cmake --build . --target print

cmake --build . --config Debug --target print

cmake --build . --config Release --target print