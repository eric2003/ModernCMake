cmake ..
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake -DCMAKE_BUILD_TYPE=Release ..

cmake --build . --target print

cmake --build . --config Debug --target print

cmake --build . --config Release --target print

cmake --build . --target ALL_BUILD
