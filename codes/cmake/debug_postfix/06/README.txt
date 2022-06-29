cmake ..
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug

cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release

cmake .. -D CMAKE_BUILD_TYPE=Debug -D CMAKE_DEBUG_POSTFIX=d
cmake --build . --config Debug
cmake .. -D CMAKE_BUILD_TYPE=Release
cmake --build . --config Release

cmake --install . --config Debug --prefix "C:/local/MyTmp/testprj"
cmake --install . --config Release --prefix "C:/local/MyTmp/testprj"

cmake .. -D CMAKE_BUILD_TYPE=Release --target clean

cmake --build . --target clean
cmake --build . --config Release --target clean

cmake --build . --target print

cmake --build . --config Debug --target print

cmake --build . --config Release --target print