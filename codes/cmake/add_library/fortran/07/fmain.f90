program main
  implicit none
  
  interface
    subroutine fortran_hello_print() bind(C,name='hello_print')
    end subroutine fortran_hello_print
  end interface  
  
  call fortran_hello_print()
  
end program main
