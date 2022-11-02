cmake ..
cmake -D CMAKE_BUILD_TYPE=Debug ..
cmake -D CMAKE_BUILD_TYPE=Release ..
cmake -D CMAKE_CONFIGURATION_TYPES="Debug;Release" ..

cmake --build . --target print

cmake --build . --config Debug --target print

cmake --build . --config Release --target print