cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set(A TRUE)
set(B TRUE)
set(C TRUE)
set(condition "(A AND B) OR C")

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/eval.cmake "
  if (${condition})
    message(STATUS TRUE)
  else()
    message(STATUS FALSE)
  endif()"
)

include(${CMAKE_CURRENT_BINARY_DIR}/eval.cmake)