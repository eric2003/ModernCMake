cmake ..
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug

cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release

cmake --install . --config Debug --prefix "C:/local/MyInstall/MyExe"
cmake --install . --config Debug --prefix "C:/local/MyInstall/MathFunctions"

cmake --install . --config Debug --prefix "C:/local/MyTmp/hello"
cmake -D CMAKE_PREFIX_PATH="C:/local/MyTmp/hellolib/01" ..

cmake .. -D CMAKE_BUILD_TYPE=Debug -D CMAKE_DEBUG_POSTFIX=_d
cmake --build . --config Debug
cmake --install . --config Debug --prefix "C:/local/MyLibInstall/MathLib/09"

cmake .. -D CMAKE_BUILD_TYPE=Release
cmake --build . --config Release
cmake --install . --config Release --prefix "C:/local/MyLibInstall/MathLib/09"

cmake ..
cmake --build . --config Debug
cmake --install . --config Debug --prefix "C:/local/MyLibInstall/MathLib/08"

cmake ..
cmake --build . --config Release
cmake --install . --config Release --prefix "C:/local/MyLibInstall/MathLib/08"


cmake --build . --target print

cmake --build . --config Debug --target print

cmake --build . --config Release --target print