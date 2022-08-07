cmd.exe "/K" '"C:\Program Files (x86)\Intel\oneAPI\setvars.bat" && powershell'
cmake -GNinja ..

PS D:\work\modern_cmake_work\ModernCMake\codes\cmake\openmp\info\02\build> cmd.exe "/K" '"C:\Program Files (x86)\Intel\oneAPI\setvars.bat" && powershell'
:: initializing oneAPI environment...
   Initializing Visual Studio command-line environment...
   Visual Studio version 17.2.1 environment configured.
   "C:\Program Files\Microsoft Visual Studio\2022\Community\"
   Visual Studio command-line environment initialized for: 'x64'
:  advisor -- latest
:  compiler -- latest
:  dal -- latest
:  debugger -- latest
:  dev-utilities -- latest
:  dnnl -- latest
:  dpcpp-ct -- latest
:  dpl -- latest
:  inspector -- latest
:  intelpython -- latest
:  ipp -- latest
:  ippcp -- latest
:  itac -- latest
:  mkl -- latest
:  mpi -- latest
:  tbb -- latest
:  vpl -- latest
:  vtune -- latest
:: oneAPI environment initialized ::
Windows PowerShell
版权所有（C） Microsoft Corporation。保留所有权利。

安装最新的 PowerShell，了解新功能和改进！https://aka.ms/PSWindows

PS D:\work\modern_cmake_work\ModernCMake\codes\cmake\openmp\info\02\build> cmake -GNinja ..
-- The C compiler identification is IntelLLVM 2022.0.0 with MSVC-like command-line
-- The CXX compiler identification is IntelLLVM 2022.0.0 with MSVC-like command-line
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/Program Files (x86)/Intel/oneAPI/compiler/latest/windows/bin/icx.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/Program Files (x86)/Intel/oneAPI/compiler/latest/windows/bin/icx.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found OpenMP_C: -Qiopenmp (found version "5.0")
-- Found OpenMP_CXX: -Qiopenmp (found version "5.0")
-- Found OpenMP: TRUE (found version "5.0")
-- FIND_PACKAGE_MESSAGE_DETAILS_OpenMP=[TRUE][TRUE][c ][v5.0()]
-- FIND_PACKAGE_MESSAGE_DETAILS_OpenMP_C=[-Qiopenmp][v5.0()]
-- FIND_PACKAGE_MESSAGE_DETAILS_OpenMP_CXX=[-Qiopenmp][v5.0()]
-- OPENMP_CXX_FOUND=TRUE
-- OPENMP_C_FOUND=TRUE
-- OPENMP_FOUND=TRUE
-- OpenMP_COMPILE_RESULT_CXX_Qiopenmp=TRUE
-- OpenMP_COMPILE_RESULT_C_Qiopenmp=TRUE
-- OpenMP_CXX_FLAGS=-Qiopenmp
-- OpenMP_CXX_FLAGS_WORK=-Qiopenmp
-- OpenMP_CXX_FOUND=TRUE
-- OpenMP_CXX_INCLUDE_DIRS=
-- OpenMP_CXX_LIBRARIES=
-- OpenMP_CXX_LIB_NAMES=
-- OpenMP_CXX_LIB_NAMES_WORK=
-- OpenMP_CXX_SPEC_DATE=201811
-- OpenMP_CXX_SPEC_DATE_INTERNAL=201811
-- OpenMP_CXX_VERSION=5.0
-- OpenMP_CXX_VERSION_MAJOR=5
-- OpenMP_CXX_VERSION_MINOR=0
-- OpenMP_C_FLAGS=-Qiopenmp
-- OpenMP_C_FLAGS_WORK=-Qiopenmp
-- OpenMP_C_FOUND=TRUE
-- OpenMP_C_INCLUDE_DIRS=
-- OpenMP_C_LIBRARIES=
-- OpenMP_C_LIB_NAMES=
-- OpenMP_C_LIB_NAMES_WORK=
-- OpenMP_C_SPEC_DATE=201811
-- OpenMP_C_SPEC_DATE_INTERNAL=201811
-- OpenMP_C_VERSION=5.0
-- OpenMP_C_VERSION_MAJOR=5
-- OpenMP_C_VERSION_MINOR=0
-- OpenMP_FINDLIST=C;CXX;Fortran
-- OpenMP_FOUND=TRUE
-- OpenMP_SPECTEST_CXX_=TRUE
-- OpenMP_SPECTEST_C_=TRUE
-- _OPENMP_CXX_REQUIRED_VARS=OpenMP_CXX_FLAGS
-- _OPENMP_C_REQUIRED_VARS=OpenMP_C_FLAGS
-- _OpenMP_MIN_VERSION=OpenMP_C_VERSION
-- _OpenMP_REQ_VARS=OpenMP_C_FOUND;OpenMP_CXX_FOUND
-- Configuring done
-- Generating done
-- Build files have been written to: D:/work/modern_cmake_work/ModernCMake/codes/cmake/openmp/info/02/build