cmake .. -D USE_MYMATH=OFF
cmake .. -D USE_MYMATH=ON
cmake --install . --prefix "C:/local/mytest/Degug/testprj"
cmake --install . --config Debug --prefix "C:/local/mytest/Debug/testprj"

ctest -C Debug -VV

PS D:\work\modern_cmake_work\ModernCMake\codes\cmake\tutorial\Step4\07\build> ctest -C Debug -VV
UpdateCTestConfiguration  from :D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/07/build/DartConfiguration.tcl
UpdateCTestConfiguration  from :D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/07/build/DartConfiguration.tcl
Test project D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/07/build
Constructing a list of tests
Done constructing a list of tests
Updating test list for fixtures
Added 0 tests to meet fixture requirements
Checking test dependency graph...
Checking test dependency graph end
test 1
    Start 1: Runs

1: Test command: D:\work\modern_cmake_work\ModernCMake\codes\cmake\tutorial\Step4\07\build\Debug\Tutorial.exe "25"
1: Working Directory: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/07/build
1: Test timeout computed to be: 10000000
1: The square root of 25 is 5
1/4 Test #1: Runs .............................   Passed    0.03 sec
test 2
    Start 2: MyRuns

2: Test command: D:\work\modern_cmake_work\ModernCMake\codes\cmake\tutorial\Step4\07\build\Debug\Tutorial.exe "3"
2: Working Directory: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/07/build
2: Test timeout computed to be: 10000000
2: The square root of 3 is 1.73205
2/4 Test #2: MyRuns ...........................   Passed    0.01 sec
test 3
    Start 3: Usage

3: Test command: D:\work\modern_cmake_work\ModernCMake\codes\cmake\tutorial\Step4\07\build\Debug\Tutorial.exe
3: Working Directory: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/07/build
3: Test timeout computed to be: 10000000
3: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/07/build/Debug/Tutorial.exe Version 1.0
3: Usage: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/07/build/Debug/Tutorial.exe number
3/4 Test #3: Usage ............................   Passed    0.01 sec
test 4
    Start 4: MyUsage

4: Test command: D:\work\modern_cmake_work\ModernCMake\codes\cmake\tutorial\Step4\07\build\Debug\Tutorial.exe
4: Working Directory: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/07/build
4: Test timeout computed to be: 10000000
4: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/07/build/Debug/Tutorial.exe Version 1.0
4: Usage: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/07/build/Debug/Tutorial.exe number
4/4 Test #4: MyUsage ..........................***Failed    0.01 sec

75% tests passed, 1 tests failed out of 4

Total Test time (real) =   0.08 sec

The following tests FAILED:
          4 - MyUsage (Failed)
Errors while running CTest
Output from these tests are in: D:/work/modern_cmake_work/ModernCMake/codes/cmake/tutorial/Step4/07/build/Testing/Temporary/LastTest.log
Use "--rerun-failed --output-on-failure" to re-run the failed cases verbosely.