#!/bin/sh
# the next line restarts using wish \
exec cgiowish -f "$0" "$@"
proc error_exit {msg} {
  wm withdraw .
  tk_dialog .error Error $msg error 0 Exit
  exit 1
}

proc message_cfd {msg} {
  tk_dialog .cfd Info $msg questhead 0 Exit
}

if {[catch {package require Tk 8.0} msg]} {
  error_exit $msg
}

#---------- get platform

set platform $tcl_platform(platform)

puts $tcl_platform(platform)

#---------- initialize windows
if {$platform == "windows"} {
  set vers [join [split $tcl_version .] {}]
  #message_cfd [info commands CGIOversion]
  if {[info commands CGIOversion] == {}} {
    if {[catch {load cgiotcl$vers} msg]} {
      error_exit $msg
    }
  }
  catch {load tclreg$vers registry}
}

grid [label .myLabel -background red -foreground white -text "Hello World" \
-relief ridge -borderwidth 8 -padx 10 -pady 10 -font {Helvetica -18 bold} \
-height 10 -width 35 -textvariable myvariable -justify left -underline 1]
set myvariable $platform