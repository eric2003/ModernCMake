cmake_minimum_required ( VERSION 3.15 )

project( app )

#add_custom_target ( print ${CMAKE_COMMAND} -E echo $<1:"Hello OneFLOW CFD!"> )
add_custom_target ( print 
	${CMAKE_COMMAND} -E 
	echo
	"PLATFORM_ID = " $<PLATFORM_ID>
	"CONFIG = " $<CONFIG>
)