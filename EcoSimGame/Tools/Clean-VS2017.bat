@echo off
echo Cleaning up junk files from VS2017
cd ..

rem Cleaning up GameRoot directory
cd GameRoot
del *.pdb
del *.idb
del *.ilk
del *.iobj
del *.ipdb
del *.obj
rem del *.dll
rem del *.exe
cd ..

rem Cleaning up VS2017 directory (VS must be shutdown in order to delete)
cd Source\".vs"
rd /s /q .
md .
cd ..
rd ".vs"
cd ..

rem Cleaning up Temp directory
cd Temp
rd /s /q .
md .
cd ..
