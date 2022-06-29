cmake ..
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug

cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release

cmake --install . --config Debug --prefix "C:/local/MyInstall/MyExe"
cmake --install . --config Debug --prefix "C:/local/MyInstall/MathFunctions"

cmake ..
cmake --build .
cmake --install . --config Debug --prefix "C:/local/MyLibInstall/MathLib/07"


cmake --build . --target print

cmake --build . --config Debug --target print

cmake --build . --config Release --target print