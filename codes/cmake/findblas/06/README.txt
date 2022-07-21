cmake .. -D CMAKE_TOOLCHAIN_FILE="C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake"
cmake .. -D CMAKE_TOOLCHAIN_FILE="C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" `
-D BLA_VENDOR:STRING=OpenBLAS

cmake .. -D BLA_VENDOR:STRING=OpenBLAS

cmake -D CMAKE_FIND_DEBUG_MODE=ON

cmake .. -D CMAKE_TOOLCHAIN_FILE="C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" `
-D CMAKE_FIND_DEBUG_MODE:BOOL=ON

cmake .. -D CMAKE_TOOLCHAIN_FILE="C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" `
-D CMAKE_BUILD_TYPE=Release
