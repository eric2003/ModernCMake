cmake .. -D USE_MYMATH=OFF
cmake .. -D USE_MYMATH=ON
cmake --install . --prefix "C:/local/mytest/Degug/testprj"
cmake --install . --config Debug --prefix "C:/local/mytest/Debug/testprj"

ctest -C Debug -VV

PS D:\work\modern_cmake_work\ModernCMake\codes\cmake\tutorial\Step4\10\build> ctest -C Debug -VV
UpdateCTestConfiguration  from :D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/10/build/DartConfiguration.tcl
UpdateCTestConfiguration  from :D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/10/build/DartConfiguration.tcl
Test project D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/10/build
Constructing a list of tests
Done constructing a list of tests
Updating test list for fixtures
Added 0 tests to meet fixture requirements
Checking test dependency graph...
Checking test dependency graph end
test 1
    Start 1: Runs

1: Test command: D:\work\modern_cmake_work\ModernCMake\codes\cmake\tutorial\Step4\10\build\Debug\Tutorial.exe "25"
1: Working Directory: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/10/build
1: Test timeout computed to be: 10000000
1: The square root of 25 is 5
1/9 Test #1: Runs .............................   Passed    0.02 sec
test 2
    Start 2: Usage

2: Test command: D:\work\modern_cmake_work\ModernCMake\codes\cmake\tutorial\Step4\10\build\Debug\Tutorial.exe
2: Working Directory: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/10/build
2: Test timeout computed to be: 10000000
2: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/10/build/Debug/Tutorial.exe Version 1.0
2: Usage: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/10/build/Debug/Tutorial.exe number
2/9 Test #2: Usage ............................   Passed    0.01 sec
test 3
    Start 3: Comp4

3: Test command: D:\work\modern_cmake_work\ModernCMake\codes\cmake\tutorial\Step4\10\build\Debug\Tutorial.exe "4"
3: Working Directory: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/10/build
3: Test timeout computed to be: 10000000
3: The square root of 4 is 2
3/9 Test #3: Comp4 ............................   Passed    0.01 sec
test 4
    Start 4: Comp9

4: Test command: D:\work\modern_cmake_work\ModernCMake\codes\cmake\tutorial\Step4\10\build\Debug\Tutorial.exe "9"
4: Working Directory: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/10/build
4: Test timeout computed to be: 10000000
4: The square root of 9 is 3
4/9 Test #4: Comp9 ............................   Passed    0.01 sec
test 5
    Start 5: Comp5

5: Test command: D:\work\modern_cmake_work\ModernCMake\codes\cmake\tutorial\Step4\10\build\Debug\Tutorial.exe "5"
5: Working Directory: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/10/build
5: Test timeout computed to be: 10000000
5: The square root of 5 is 2.23607
5/9 Test #5: Comp5 ............................   Passed    0.00 sec
test 6
    Start 6: Comp7

6: Test command: D:\work\modern_cmake_work\ModernCMake\codes\cmake\tutorial\Step4\10\build\Debug\Tutorial.exe "7"
6: Working Directory: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/10/build
6: Test timeout computed to be: 10000000
6: The square root of 7 is 2.64575
6/9 Test #6: Comp7 ............................   Passed    0.00 sec
test 7
    Start 7: Comp25

7: Test command: D:\work\modern_cmake_work\ModernCMake\codes\cmake\tutorial\Step4\10\build\Debug\Tutorial.exe "25"
7: Working Directory: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/10/build
7: Test timeout computed to be: 10000000
7: The square root of 25 is 5
7/9 Test #7: Comp25 ...........................   Passed    0.00 sec
test 8
    Start 8: Comp-25

8: Test command: D:\work\modern_cmake_work\ModernCMake\codes\cmake\tutorial\Step4\10\build\Debug\Tutorial.exe "-25"
8: Working Directory: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/10/build
8: Test timeout computed to be: 10000000
8: The square root of -25 is 0
8/9 Test #8: Comp-25 ..........................   Passed    0.00 sec
test 9
    Start 9: Comp0.0001

9: Test command: D:\work\modern_cmake_work\ModernCMake\codes\cmake\tutorial\Step4\10\build\Debug\Tutorial.exe "0.0001"
9: Working Directory: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/10/build
9: Test timeout computed to be: 10000000
9: The square root of 0.0001 is 0.01
9/9 Test #9: Comp0.0001 .......................   Passed    0.01 sec

100% tests passed, 0 tests failed out of 9

Total Test time (real) =   0.10 sec