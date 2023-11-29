! my_subroutine.f90
subroutine hello_fortran() bind(C, name="hello_fortran")
  implicit none
  print *, "Hello from Fortran"
end subroutine hello_fortran