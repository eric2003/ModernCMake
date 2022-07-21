cmake .. -D USE_MYMATH=OFF
cmake .. -D USE_MYMATH=ON
cmake --install . --prefix "C:/local/mytest/Degug/testprj"
cmake --install . --config Debug --prefix "C:/local/mytest/Debug/testprj"

ctest -C Debug -VV

cmake .. -D CMAKE_BUILD_TYPE=Release
cmake --build . --config Release

cmake --install . --config Debug --prefix "C:/local/MyTmp/testprj"
cmake --install . --config Release --prefix "C:/local/MyTmp/testprj"