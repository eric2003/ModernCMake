Intel oneAPI:

cmd.exe "/K" '"C:\Program Files (x86)\Intel\oneAPI\setvars.bat" && powershell'

rm * -Recurse -Force;cmake -DCMAKE_C_COMPILER=icx -DCMAKE_CXX_COMPILER=icx -DCMAKE_BUILD_TYPE=Release -GNinja ..;cmake --build .

vs2022:

rm * -Recurse -Force;cmake ..;cmake --build . --config release

------------------------------------------------------

cmake -E rm -rf  "build";cmake -E make_directory "build";cmake -E chdir "build" cmake ..;cmake --build "build" --config Release


cmake -E rm -rf  "build";cmake -E make_directory "build";cmake -E chdir "build" cmake -DCMAKE_C_COMPILER=icx -DCMAKE_CXX_COMPILER=icx -DCMAKE_BUILD_TYPE=Release -GNinja ..;cmake --build "build"