cd d:\work\modern_cmake_work\ModernCMake\codes\cmake\add_library\test\08a\build\
cmd.exe "/K" '"C:\Program Files (x86)\Intel\oneAPI\setvars.bat" && powershell'
------------------------------------
icx -c ../sub.c
icx -c ../main.c 
icx -o ctestprj main.obj sub.obj
------------------------------------
$ Remove-Item * -Recurse -Force
$ icx -c ../sub.c
$ ifort -c ../fmain.f90
$ ifort -o ftestprj fmain.obj sub.obj
