cmake ..
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug

cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release

cmake .. -D CMAKE_BUILD_TYPE=Debug -D CMAKE_DEBUG_POSTFIX=d
cmake --build . --config Debug
cmake .. -D CMAKE_BUILD_TYPE=Release
cmake --build . --config Release

cmake --build . --target print

cmake --build . --config Debug --target print

cmake --build . --config Release --target print