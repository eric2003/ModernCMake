cmake_minimum_required ( VERSION 3.25 )

project ( testprj )

enable_language(Fortran)

include(CheckSourceCompiles)
check_source_compiles(Fortran
"program test
error stop
end program"
HAVE_ERROR_STOP)
