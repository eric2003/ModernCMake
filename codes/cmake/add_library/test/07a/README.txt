cmd.exe "/K" '"C:\Program Files (x86)\Intel\oneAPI\setvars.bat" && powershell'
icx -c sub.c
icx -c main.c 
icx -o testprj main.obj sub.obj 