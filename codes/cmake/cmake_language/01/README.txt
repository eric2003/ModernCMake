cmake ..
cmake -D CMAKE_BUILD_TYPE=Debug ..
cmake -D CMAKE_BUILD_TYPE=Release ..
cmake -D CMAKE_CONFIGURATION_TYPES="Debug;Release" ..

cmake --build . --target print

cmake --build . --config Debug --target print

cmake --build . --config Release --target print

PS D:\work\modern_cmake_work\ModernCMake\codes\cmake\cmake_language\01\build> cmake ..
-- Building for: Visual Studio 17 2022
-- Selecting Windows SDK version 10.0.19041.0 to target Windows 10.0.22000.
-- The C compiler identification is MSVC 19.33.31629.0
-- The CXX compiler identification is MSVC 19.33.31629.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.33.31629/bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.33.31629/bin/Hostx64/x64/cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Hello World!
-- Configuring done
-- Generating done
-- Build files have been written to: D:/work/modern_cmake_work/ModernCMake/codes/cmake/cmake_language/01/build
PS D:\work\modern_cmake_work\ModernCMake\codes\cmake\cmake_language\01\build> cd d:\work\modern_cmake_work\ModernCMake\codes\cmake\cmake_language\02\build\
PS D:\work\modern_cmake_work\ModernCMake\codes\cmake\cmake_language\02\build>