cmake_minimum_required ( VERSION 3.28 )

project ( testprj LANGUAGES Fortran C )

include(FortranCInterface)
FortranCInterface_VERIFY()

#add_library(fsub OBJECT fsub.f90)

add_executable ( CFPrj )

target_sources( CFPrj
  PRIVATE
    cmain.c 
    fsub.f90
)



