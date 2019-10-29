/* This code is the Main Body for Rosenbrock Function Optimizers in ND. */
/* Author- Rishi Malhan. */ 

#include <iostream>
#include <cmath>
#include "eigen-eigen-5a0156e40feb/Eigen/Core"
#include "eigen-eigen-5a0156e40feb/Eigen/Dense"
#include "eigen-eigen-5a0156e40feb/Eigen/Geometry"
#include "Gradient_Descent.h"
#include "Newton_ND.h"
#include "BFGS.h"
#include "DFP.h"
#include "Pure_Newton.h"
#include <ctime>

std::clock_t strt;

int main()
{
	std::cout<< "This Program runs optimization algorithms over Rosenbrock Function.\nIt gives choices for Dimension N where modulus(N/2)==0.\n\n" <<
				"NOTE: THIS PROGRAM DOESNOT PRINT ONGOING ITERATION DATA TO OPTIMIZE SPEED. DATA CAN BE WRITTEN INTO FILES BY MAKING MODIFICATIONS IN THE CODE.\n"<<
				 "OR YOU CAN UNCOMMENT THE LINE WHERE DATA IS PRINTED ONTO THE TERMINAL IN HEADER FILES OF ALGORITHMS.\n\n"<<std::endl;
	std::cout<< "Initializing Rosenbrock Function Optimizer......................................\n" <<std::endl;

	//******************************************************USER INPUT******************************************************//
	std::cout<< "Enter the Dimension Number N" <<std::endl;
	int n;				//Dimension of Optimization
	int opt_type;		//Type of Algorithm to be used
	double alpha;		//Parameter Value alpha used in search
	int type_search;	//Type of the Line Search

	scanf("%d",&n);
	if (n%2!=0) { std::cout<< "Invalid Dimension. Terminating Program" <<std::endl; exit(0); }
	std::cout<< "\nEnter the Parameter Alpha in domain [1,100]" <<std::endl;
	scanf("%lf",&alpha);
	if (alpha<1 || alpha>100) { std::cout<< "Invalid Alpha. Terminating Program" <<std::endl; exit(0); }

	std::cout<< "\nSelect the Optimizer to be Used:" <<std::endl;
	std::cout<< "1: Steepest Descent" << "\n" << "2: Modified Newton's Method" << "\n" << "3: BFGS Method" << "\n" << "4: DFP Method" << "\n" << "5: Pure Newton Method" <<std::endl;
	std::cin>> opt_type;
	if ( (opt_type<1) || (opt_type>5) ) { std::cout<< "Invalid Selection. Terminating Program" <<std::endl; exit(0); }

	if (opt_type!=5)
	{
		std::cout<< "\nSelect the Search to be Used:" <<std::endl;
		std::cout<< "1: Armijo's Search\n" << "2: Golden Section Search\n" << "3: Bisection Search" <<std::endl;
		std::cin>> type_search;
		if ( (type_search<1) || (type_search>3) ) { std::cout<< "Invalid Selection. Terminating Program" <<std::endl; exit(0); }
	}

	Eigen::VectorXd x_int(n);	//Intial Value of the point
	std::cout<< "\nEnter the Initial Point in one line, every value separated by comma except for the last." <<std::endl;
	for( int i = 0; i < n; i++ )
	{
		// std::cin>> x_int(i);
		if(i!=(n-1)) { scanf("%lf,",&x_int[i]);	}
		else { scanf("%lf",&x_int[i]); } 
	}
	if (x_int.size()!=n) { std::cout<< "Invalid Point. Terminating Program" <<std::endl; exit(0); }

	std::cout<< "\nInitial Point:  \n" << x_int <<std::endl;
	double duration;

	//*********************************************************DECLARATIONS************************************************//
	Eigen::VectorXd xopt(n);
	double tolerance = 1e-5;
	fgh_def evaluator(n,alpha);	


	//***************************************************RUN OPTIMIZER********************************************//
	strt = std::clock();
	if ( opt_type==1 ) 
		{ 
			std::cout<< "\n\nInitializing Gradient Descent..................."  << std::endl; 
			Gradient_Descent optimizer;
			xopt = optimizer.optimize( n,alpha,x_int,tolerance,type_search ); 
		}
	if ( opt_type==2 ) 
		{ 
			std::cout<< "\n\nInitializing Newton's Method..................."  << std::endl;  
			Newton_ND optimizer;
			xopt = optimizer.optimize( n,alpha,x_int,tolerance,type_search ); 
		}
	if ( opt_type==3 ) 
		{ 
			std::cout<< "\n\nInitializing BFGS Method........................"  << std::endl;  
			BFGS optimizer;
			xopt = optimizer.optimize( n,alpha,x_int,tolerance,type_search ); 
		}
	if ( opt_type==4 ) 
		{ 
			std::cout<< "\n\nInitializing DFP Method........................"  << std::endl;  
			DFP optimizer;
			xopt = optimizer.optimize( n,alpha,x_int,tolerance,type_search ); 
		}
	if ( opt_type==5 ) 
	{ 
		std::cout<< "\n\nInitializing Pure Newton Method...................."  << std::endl;  
		Pure_Newton optimizer;
		xopt = optimizer.optimize( n,alpha,x_int,tolerance ); 
	}
	duration = ( std::clock() - strt ) / (double) CLOCKS_PER_SEC;

	std::cout<< "Optimum Point:  \n" << xopt <<std::endl;
	std::cout<< "Gradient Value:  " << evaluator.grad_eval(xopt).norm() <<std::endl;
	std::cout<< "Function Value:  " << evaluator.func_eval(xopt) <<std::endl;
	std::cout<< "Duration:  " << duration <<std::endl;

	return 0;
}