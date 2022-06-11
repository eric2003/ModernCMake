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

proc do_quit {} {
  destroy .
  exit 0
}

#---------- main window

wm title . OneFLOW-CGNSview
wm protocol . WM_DELETE_WINDOW do_quit

#---------- main window
set winwidth 640
set winheight 500

frame .main -width $winwidth -height $winheight
pack .main -side top -fill both -expand 1 -padx 5 -pady 5

#--- window separator
set seppos 0.4
frame .main.sep -width 6 -bd 2 -relief raised -cursor sb_h_double_arrow
place .main.sep -relx $seppos -x -3 -rely 0 -relheight 1

source  ../menubar.tcl
#---------- menu

menubar_create {File Config Tree Tools Help}

#--- file menu

set m [menubar_get File]
$m add command -label "Open..." -command file_load
$m add separator
$m add command -label "Reload" -state disabled
$m add command -label "File Info..." -state disabled

#proc file_load {} {
#
#}

proc file_load {{inpfile ""}} {
puts "inpfile=$inpfile"
  if [catch {CGNSfile $inpfile} type] {
    message_cfd $type
    return
  }
}

proc FileOpen {title defname {wref .} {types ""}} {
}