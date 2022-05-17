#!/bin/sh
# the next line restarts using wish \
exec cgiowish -f "$0" "$@"
#exec notepad myfile.txt &
if {[catch {package require Tk 8.0} msg]} {
  error_exit $msg
}

#---------- get platform

set platform $tcl_platform(platform)
puts $platform
grid [label .myLabel -background red -foreground white -text "Hello World" \
-relief ridge -borderwidth 8 -padx 10 -pady 10 -font {Helvetica -18 bold} \
-height 10 -width 35 -textvariable myvariable -justify left -underline 1]
set myvariable $platform