@echo off

setlocal enabledelayedexpansion
cls

REM ---- Enable ANSI colors ----
for /F %%a in ('echo prompt $E ^| cmd') do set "ESC=%%a"

REM ---- Color definitions ----
set "RED=%ESC%[91m"
set "GREEN=%ESC%[92m"
set "YELLOW=%ESC%[93m"
set "BLUE=%ESC%[94m"
set "WHITE=%ESC%[97m"
set "RESET=%ESC%[0m"

REM ========================================
REM Compile and Run C / C++ Programs
REM Usage:
REM     compile.bat filename.c
REM     compile.bat filename.cpp
REM ========================================

REM ---- Check input ----
if "%~1"=="" (
    echo Usage: compile.bat filename.c OR filename.cpp
    echo Example: compile.bat program.c
    pause
    exit /b 1
)

REM ---- Compiler paths (Dev-Cpp MinGW) ----
set "GCC=C:\MinGW\bin\gcc.exe"
set "GPP=C:\MinGW\bin\g++.exe"

REM ---- Input and output names ----
set "INPUT=%~1"
set "OUTPUT=%~n1"
set "EXT=%~x1"

echo.
echo %GREEN%===========================================
echo %WHITE%Welcome to the C/C++ Compile and Run Script
echo                version 2.0 
echo.
echo  %RED%          Developed by Jemx
echo %GREEN%===========================================
echo.
echo %YELLOW%Compiling %INPUT%   %RED%  


REM ---- Detect file type ----
if /I "%EXT%"==".c" (
    "%GCC%" -std=c99 "%INPUT%" -o "%OUTPUT%.exe"
) else if /I "%EXT%"==".cpp" (
    "%GPP%" "%INPUT%" -o "%OUTPUT%.exe"
) else (
    echo %RED%ERROR: Unsupported file type!
    echo Use .c or .cpp files only.
    pause
    exit /b 1
)

REM ---- Check compile result ----
if errorlevel 1 (
    echo.
    echo %RED%Compilation failed!%GREEN%
    pause
    exit /b 1
)

echo.
echo %GREEN%Compilation successful!
echo.
echo %BLUE%Running %OUTPUT%.exe ...

REM ---- Run program ----
echo.
echo %GREEN%------------------------------------------
echo %WHITE%                OUTPUT
echo %GREEN%------------------------------------------%YELLOW%
"%OUTPUT%.exe"
echo.
echo %GREEN%------------------------------------------
echo.

REM ---- Auto delete old EXE if exists ----
if exist "%OUTPUT%.exe" (
    echo.
    echo %RED%Old executable detected. 
    echo %YELLOW%Deleting %OUTPUT%.exe ...
    del /f /q "%OUTPUT%.exe"
    echo %GREEN%Old executable removed successfully!
)

pause




