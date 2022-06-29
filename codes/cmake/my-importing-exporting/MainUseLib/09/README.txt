cmake ..
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug

cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release

cmake --install . --config Debug --prefix "C:/local/MyInstall/MyExe"
cmake --install . --config Debug --prefix "C:/local/MyInstall/MathFunctions"

cmake -D CMAKE_PREFIX_PATH="C:/local/MyInstall/MathFunctions" ..
cmake -D CMAKE_PREFIX_PATH="C:/local/MyLibInstall/MathLib" ..

cmake ..
cmake --build .
cmake --install . --config Debug --prefix "C:/local/MyLibInstall/MathLib/03"

cmake -D CMAKE_BUILD_TYPE=Debug -D CMAKE_PREFIX_PATH="C:/local/MyLibInstall/MathLib/09" ..
cmake --build . --config Debug

cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_PREFIX_PATH="C:/local/MyLibInstall/MathLib/09" ..
cmake --build . --config Release


cmake --build . --target print

cmake --build . --config Debug --target print

cmake --build . --config Release --target print