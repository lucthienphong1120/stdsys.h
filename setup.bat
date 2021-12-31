@echo off

copy basic.h "C:\Program Files (x86)\Dev-Cpp\MinGW64\include" /A /Y

copy stdsys.h "C:\Program Files (x86)\Dev-Cpp\MinGW64\include" /A /Y

echo "#include <stdsys.h>"

echo "int main() {"

echo 	"print("hello world");"

echo 	"return 0;"

echo "}"

pause
pause