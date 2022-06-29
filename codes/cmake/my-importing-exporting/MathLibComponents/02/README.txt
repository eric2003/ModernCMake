cmake ..
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug

cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release

cmake --install . --config Debug --prefix "C:/local/MyInstall/MyExe"
cmake --install . --config Debug --prefix "C:/local/MyInstall/MathFunctions"
cmake --install . --config Debug --prefix "C:/local/MyInstall/MathFunctionsComponents"
cmake ..
cmake --build .
cmake --install . --config Debug --prefix "C:/local/MyLibInstall/MathLibComponents/02"

cmake -D CMAKE_PREFIX_PATH="C:/local/MyLibInstall/MathLibComponents/02" ..


cmake --build . --target print

cmake --build . --config Debug --target print

cmake --build . --config Release --target print