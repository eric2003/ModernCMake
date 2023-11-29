subroutine hello_print() bind(C, name='hello_print')
implicit none

    print*,"haha fortran hello_print"
    
end subroutine hello_print