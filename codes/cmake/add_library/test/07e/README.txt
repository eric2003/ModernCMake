cd d:\work\modern_cmake_work\ModernCMake\codes\cmake\add_library\test\07b\build\
cmd.exe "/K" '"C:\Program Files (x86)\Intel\oneAPI\setvars.bat" && powershell'
icx -c ../sub.c
icx -c ../main.c 
icx -o testprj main.obj sub.obj 