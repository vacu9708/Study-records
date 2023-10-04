# C++ build process
### Preprocessing:
The preprocessor handles directives (lines starting with #) like #include and #define.
Header files are included, macros are expanded, and comments are removed.

### Compilation:
The compiler translates the preprocessed C++ code into assembly code.
This step also involves syntax checking, error checking, and optimization.

### Assembly:
The assembler converts assembly code into machine code (object code).
Each compiled file produces an object file with a .obj or .o extension.

### Linking:
The linker combines object files into a single executable file.
It resolves references between object files (e.g., function or variable references) and links them together.
It also links the program with libraries it depends on.

### Execution
Finally, the operating system executes the program, following the instructions in the machine code contained in the executable file.

# Commands
### Single-Step Compilation and Linking
~~~
g++ -o my_program source1.cpp source2.cpp
~~~
### Multi-Step Compilation and Linking
~~~
g++ -c source1.cpp
g++ -c source2.cpp
g++ -o my_program source1.o source2.o
~~~
