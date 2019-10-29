1. Compile only RosenBrock_Optimization.cpp with following command.

g++ -std=c++11 -o Rosenbrock_Optimizer.o Rosenbrock_Optimization.cpp

2. Run the object file by giving the following command.

./Rosenbrock_Optimizer.o

(For Windows machines, follow the instructions for running g++ compiler through mingw.)


3. Example Start points are given in the file named Start_Points.txt. Dimensions for corresponding start points are mentioned. Please input the start points as shown in the file. A screen shot is given along with the files as a sample for user input.

It will give a choice for Algorithm to use and line search to use. Any data or Iteration number during optimization is not being printed to save time. It can be printed by modifying the codes for the algorithms and introducing print commands or writing the data to a file. The excel file contains readings by running algortihms over a wide range of start points and parameters alpha.
