set QT=D:\Qt  
set QTSDK=%QT%\6.8.2\msvc2022_64\lib\cmake
set CMAKE=%QT%\Tools\CMake_64\bin\cmake.exe  
set OUTPATH=..\rel\msvc  

@echo cmake to Vs2022  
%CMAKE% -G "Visual Studio 17 2022" -A x64 -S . -B build -DCMAKE_PREFIX_PATH="%QT%\6.8.2\msvc2022_64\lib\cmake"  
@echo cmake build 
set(CMAKE_AUTOMOC ON)  
set(CMAKE_AUTOUIC ON)  
set(CMAKE_AUTORCC ON)   
%CMAKE% --build build --config Release  
@echo cmake install  
md %OUTPATH%  
copy ..\bin\msvc\* %OUTPATH%  
%QTSDK%\bin\windeployqt.exe "%OUTPATH%\player.exe" --qmldir .  