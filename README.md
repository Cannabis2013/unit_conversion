# Unit Conversion
## Short description
A simple converter made in C using QtCreator and CMake.
## A short note about CMake
You probably think "Why using CMake for such a little program"? And you are right, there is no reason for using CMake.
It's just that I wrote this little program in QtCreator which is designed for Qt projects that uses QBS, CMake and QMake
to build projects. I could ditch CMake and run terminal commands in order to build and run my program, but I choose to
just press the green arrow :-D.
 
## Platform
Compiles and runs on Debian 12
## Build instructions
Run the following commands in the terminal in order to build:  
Using GCC:    
```bash
gcc -o converter *.h *.c
```  
Using CMake  
```bash
cmake . && cmake --build .
```
