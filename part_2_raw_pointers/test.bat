@echo off
chcp 65001 >nul
setlocal enabledelayedexpansion

:: Define colors
set "RED=[91m"
set "GREEN=[92m"
set "YELLOW=[93m"
set "CYAN=[96m"
set "RESET=[0m"

echo %CYAN%=============================
echo   Choose a C++ Source File
echo =============================%RESET%

:: List all C++ files in src/
set count=0
for %%f in (src/*.cpp) do (
    set /a count+=1
    set "file[!count!]=%%f"
    echo %GREEN%!count!. %%f%RESET%
)
set exit_val=%count%
set /a exit_val+=1
echo %YELLOW%%exit_val%. Exit%RESET%

:: If no files found, exit
if %count%==0 (
    echo %RED%No C++ source files found.%RESET%
    pause
    exit /b
)

:: Get user input for file selection
echo.
set /p choice=%CYAN%Enter the number of the file to compile: %RESET%

if "%choice%" == "%exit_val%" (
    echo %YELLOW%Exiting...%RESET%
    exit /b
)

:: Validate input
if not defined file[%choice%] (
    echo %RED%Invalid choice. Exiting...%RESET%
    pause
    exit /b
)

set "filename=!file[%choice%]!"
set "basename=!filename:src/=!"  :: Extract only the file name
set "basename=!basename:.cpp=!"  :: Remove the file extension

:: Choose the build method
echo %CYAN%=============================
echo   Choose Build Method
echo =============================%RESET%
echo %GREEN%1. Build with g++%RESET%
echo %GREEN%2. Build with CMake%RESET%
echo %YELLOW%3. Exit%RESET%
echo.

set /p build_method=%CYAN%Enter choice: %RESET%

if "%build_method%" == "3" (
    echo %YELLOW%Exiting...%RESET%
    exit /b
)

if "%build_method%" == "2" goto build_cmake
if "%build_method%" == "1" goto build_gpp

:: Invalid choice
echo %RED%Invalid choice. Exiting...%RESET%
exit /b

:: ============================================================
:: Build with g++
:: ============================================================
:build_gpp
echo %CYAN%Compiling %filename% with g++...%RESET%
g++ -std=c++17 -o test_program.exe src/%basename%.cpp

if %errorlevel% neq 0 (
    echo %RED%Compilation failed.%RESET%
    pause
    exit /b
)

:: Run the program
echo %GREEN%Running %basename%.exe...%RESET%
echo %CYAN%------------------------------------------------%RESET%
test_program.exe
echo %CYAN%------------------------------------------------%RESET%

pause
exit /b

:: ============================================================
:: Build with CMake
:: ============================================================
:build_cmake
echo %CYAN%Setting up CMake build for %filename%...%RESET%

:: Ensure build directory exists
if not exist build mkdir build
cd build

:: Run CMake with the selected file
cmake .. -DSELECTED_FILE=%basename%.cpp

if %errorlevel% neq 0 (
    echo %RED%CMake configuration failed.%RESET%
    pause
    exit /b
)

cmake --build .

if %errorlevel% neq 0 (
    echo %RED%Build failed.%RESET%
    pause
    exit /b
)

:: Run the program
echo %GREEN%Running %basename%...%RESET%
echo %CYAN%------------------------------------------------%RESET%
call Debug\test_program.exe
echo %CYAN%------------------------------------------------%RESET%

pause
exit /b

cls