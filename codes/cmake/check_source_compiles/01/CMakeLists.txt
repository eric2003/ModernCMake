cmake_minimum_required ( VERSION 3.25 )

project ( testprj )

include(CheckSourceCompiles)

check_source_compiles(C
"#include <stdlib.h>
#include <stdnoreturn.h>
noreturn void f(){ exit(0); }
int main(void) { f(); return 1; }"
HAVE_NORETURN)

check_source_compiles(Fortran
"program test
error stop
end program"
HAVE_ERROR_STOP)

message ( STATUS "HAVE_NORETURN=${HAVE_NORETURN}" )
