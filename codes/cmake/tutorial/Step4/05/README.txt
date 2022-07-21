cmake .. -D USE_MYMATH=OFF
cmake .. -D USE_MYMATH=ON
cmake --install . --prefix "C:/local/mytest/Degug/testprj"
cmake --install . --config Debug --prefix "C:/local/mytest/Debug/testprj"

ctest -C Debug -VV

PS D:\work\modern_cmake_work\ModernCMake\codes\cmake\tutorial\Step4\05\build> ctest -C Debug -VV
UpdateCTestConfiguration  from :D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/05/build/DartConfiguration.tcl
UpdateCTestConfiguration  from :D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/05/build/DartConfiguration.tcl
Test project D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/05/build
Constructing a list of tests
Done constructing a list of tests
Updating test list for fixtures
Added 0 tests to meet fixture requirements
Checking test dependency graph...
Checking test dependency graph end
test 1
    Start 1: Runs

1: Test command: D:\work\modern_cmake_work\ModernCMake\codes\cmake\tutorial\Step4\05\build\Debug\Tutorial.exe "25"
1: Working Directory: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/05/build
1: Test timeout computed to be: 10000000
1: Computing sqrt of 25 to be 13
1: Computing sqrt of 25 to be 7.46154
1: Computing sqrt of 25 to be 5.40603
1: Computing sqrt of 25 to be 5.01525
1: Computing sqrt of 25 to be 5.00002
1: Computing sqrt of 25 to be 5
1: Computing sqrt of 25 to be 5
1: Computing sqrt of 25 to be 5
1: Computing sqrt of 25 to be 5
1: Computing sqrt of 25 to be 5
1: The square root of 25 is 5
1/2 Test #1: Runs .............................   Passed    0.03 sec
test 2
    Start 2: MyRuns

2: Test command: D:\work\modern_cmake_work\ModernCMake\codes\cmake\tutorial\Step4\05\build\Debug\Tutorial.exe "3"
2: Working Directory: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/05/build
2: Test timeout computed to be: 10000000
2: Computing sqrt of 3 to be 2
2: Computing sqrt of 3 to be 1.75
2: Computing sqrt of 3 to be 1.73214
2: Computing sqrt of 3 to be 1.73205
2: Computing sqrt of 3 to be 1.73205
2: Computing sqrt of 3 to be 1.73205
2: Computing sqrt of 3 to be 1.73205
2: Computing sqrt of 3 to be 1.73205
2: Computing sqrt of 3 to be 1.73205
2: Computing sqrt of 3 to be 1.73205
2: The square root of 3 is 1.73205
2/2 Test #2: MyRuns ...........................   Passed    0.01 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.05 sec