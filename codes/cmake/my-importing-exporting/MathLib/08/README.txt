cmake ..
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug

cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release

cmake --install . --config Debug --prefix "C:/local/MyInstall/MyExe"
cmake --install . --config Debug --prefix "C:/local/MyInstall/MathFunctions"

cmake ..
cmake --build . --config Debug
cmake --install . --config Debug --prefix "C:/local/MyLibInstall/MathLib/08"

cmake ..
cmake --build . --config Release
cmake --install . --config Release --prefix "C:/local/MyLibInstall/MathLib/08"


cmake --build . --target print

cmake --build . --config Debug --target print

cmake --build . --config Release --target print