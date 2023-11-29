#include <stdio.h>

// 声明Fortran子程序的函数原型
extern void HELLO_FORTRAN();

int main() {
  printf("Hello from C!\n");

  // 调用Fortran子程序
  HELLO_FORTRAN();

  return 0;
}