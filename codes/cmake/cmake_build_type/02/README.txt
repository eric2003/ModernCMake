cmake ..
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake -DCMAKE_BUILD_TYPE=Release ..

cmake --build . --config Release
cmake --build . --config Debug

cmake --build . --target print

cmake --build . --config Debug --target print

cmake --build . --config Release --target print