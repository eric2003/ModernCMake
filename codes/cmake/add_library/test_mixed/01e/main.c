// main.c
#include <stdio.h>

// 声明Fortran子程序
extern void __stdcall hello_fortran();

int main() {
    // 调用Fortran子程序
    hello_fortran();
    return 0;
}
