Kindly Note the Following.

Armijo's Method:
To run armijo's algorithm, eigen library should be installed in /usr/local/include/eigen3/
It is available online. Armijo's code runs for both the start values mentioned in the problem statement. 
CSV file containes the iterations and respective values.
It is a generic code taking any dimension vector hence, a parameter t is used for all purposes. Alpha is added to this parameter to find
corresponding x value in n dimension. It is an approach followed for generalization.


Newton's Method:
There are two functions defined for newton's method. Both the functions' iterations have been given in csv files. 
Please comment out the function, gradient and hessian in the beginning with the corresponding main code commented out in Main body.
Thus run one function at a time.


Makefile:
There is a separate makefile provided with the submission. Comment out all lines having the name of the code that you are not running.
Only the lines having name of code you are running should be active. 