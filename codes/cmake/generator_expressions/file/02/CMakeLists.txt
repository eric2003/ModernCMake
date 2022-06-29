cmake_minimum_required ( VERSION 3.20 )

project( testprj )

file( GENERATE OUTPUT my.log CONTENT "PLATFORM_ID = $<PLATFORM_ID>" )