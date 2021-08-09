How to use the program:
<<<<<<< HEAD
1) To compile the program, simply enter "make" in the command line and press enter.
2) To run the program, enter "math" followed by "-s", "-c", "-t", "-e", or "-a".
   The program will only work if you do follow this format. Example of command line
   arguments to run all of the tests: math -a

How to use the Makefile:
1) As stated above, to compile the source code, simply enter "make" in the command 
   line.
2) To rid the directory of any old/unwanted executable binaries or files generated
   from compiling the source code (math.c), simply enter "make clean" in the command
   line. This will remove files like "math", "math.o", etc.
3) To use the formatting tool, first enter "make clang" in the command line. Then you
   can enter "clang" followed by the name of the C program you are trying to format.
   Example usage: clang math.c
4) To use the infer tool, simply enter "make infer" in the command line and press
   enter. This tool analyzes the code and looks for issues. For my math.c program,
   infer found no issues.
=======
1) To compile the program, simply enter "make" in the command line and press
   enter.
2) To run the program, enter "math" followed by "-s", "-c", "-t", "-e", or "-a".
   The program will only work if you do follow this format. Example of command 
   line arguments to run all of the tests: math -a

How to use the Makefile:
1) As stated above, to compile the source code, simply enter "make" in the 
   command line.
2) To rid the directory of any old/unwanted executable binaries or files 
   generated from compiling the source code (math.c), simply enter "make clean" 
   in the command line. This will remove files like "math", "math.o", etc.
3) To use the formatting tool, first enter "make clang" in the command line. 
   Then you can enter "clang" followed by the name of the C program you are 
   trying to format. Example usage: clang math.c
4) To use the infer tool, simply enter "make infer" in the command line and
   press enter. This tool analyzes the code and looks for issues. For my math.c 
   program, infer found no issues.
>>>>>>> c97444e5849bce153f50501fe9115b48c0b8252d
