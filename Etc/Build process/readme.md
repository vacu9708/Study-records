# C++ build process
The build process of a C++ program involves several steps that transform source code files into an executable program. Here is a general outline of the process:
### 1. Preprocessing
Before the actual compilation process begins, the preprocessor handles directives like #include, #define, and #if. It also expands macros and performs conditional compilation. This step is usually invoked implicitly during the compilation step.

### 2. Compilation
In this step, the preprocessed source code files (.cpp, .cc, or .cxx) are compiled into object files. The compiler translates the high-level C++ code into assembly language. This step is performed by invoking the compiler with the appropriate command-line options.

### 3. Assembly
The assembly step translates the assembly language code generated in the compilation step into machine code. This step is usually performed automatically by the compiler and results in object files (.o or .obj).

### 4. Linking
The linking step combines the object files and any necessary library files into an executable program. The linker resolves references between files (like function or variable references) to make sure everything points to the right place.

### 5. Loading
When you run the program, the loader loads the executable into memory and starts it running.

### 6. Execution
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
