Both compilers and interpreters are used to translates code written in a high-level language into machine code.<br>

![Untitled](https://user-images.githubusercontent.com/67142421/176752255-e2aeb10d-087f-4f72-ab10-b9eb2f794e14.png)

# Compiler
- scans the whole program in one go. The whole code is translated into the machine code before program runs, which allows compiled programs to run faster than interpreted program once it is compiled.
- checks and fixes the inefficiency of the code being compiled(compiler optimization).

# Interpreter
- translates the program one statement at a time, which means slower speed and difficult optimization.
- If compiled program changes, it has to be compiled to see the changes. Compiling takes much more time than interpreting. If the program is big, it might even take more than an hour, which leads to difficult modification. On the other hand interpreted programs can be modified much faster.
- Designing a compiler is much more compilcated. This is why more and more interpreted languages are created

# Just In time Compile
 JIT compilers typically analyze the code in chunks or blocks to generate machine code just before it is executed. while interpreters execute code line by line.
