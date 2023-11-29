cd d:\work\modern_cmake_work\ModernCMake\codes\cmake\add_library\test\09b\build\
cmd.exe "/K" '"C:\Program Files (x86)\Intel\oneAPI\setvars.bat" && powershell'
------------------------------------
$ icx -c ../cmain.c
$ ifort -c ../fsub.f90
$ icx -o CFPrj cmain.obj fsub.obj
$ dumpbin /symbols fsub.obj

PS D:\work\modern_cmake_work\ModernCMake\codes\cmake\add_library\test\09b\build> dumpbin /symbols fsub.obj
Microsoft (R) COFF/PE Dumper Version 14.37.32825.0
Copyright (C) Microsoft Corporation.  All rights reserved.


Dump of file fsub.obj

File Type: COFF OBJECT

COFF SYMBOL TABLE
000 00000000 SECT1  notype       Static       | .text
    Section length   50, #relocs    3, #linenums    0, checksum        0
002 00000000 SECT1  notype ()    External     | hello_print
003 00000000 SECT2  notype       Static       | .rdata
    Section length   24, #relocs    0, #linenums    0, checksum        0
005 00000008 SECT2  notype       Static       | __STRLITPACK_1
006 00000000 UNDEF  notype ()    External     | for_write_seq_lis
007 00000000 SECT3  notype       Static       | .xdata
    Section length    8, #relocs    0, #linenums    0, checksum        0
009 00000000 SECT4  notype       Static       | .pdata
    Section length    C, #relocs    3, #linenums    0, checksum        0
00B 00000000 SECT2  notype       Static       | __STRLITPACK_3.0.1
00C 00000000 UNDEF  notype ()    External     | __ImageBase
00D 00000000 SECT5  notype       Static       | .drectve
    Section length   B9, #relocs    0, #linenums    0, checksum        0

String Table Size = 0x50 bytes

  Summary

          B9 .drectve
           C .pdata
          24 .rdata
          50 .text
           8 .xdata