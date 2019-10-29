/* This code is the Main script for Steepest Descent Algorithm for Optimization in ND. */ 
/* Author- Rishi Malhan. */ 

#ifndef Gradient_Descent_H
#define Gradient_Descent_H
#include <iostream>
#include <cmath>
#include "eigen-eigen-5a0156e40feb/Eigen/Core"
#include "eigen-eigen-5a0156e40feb/Eigen/Dense"
#include "eigen-eigen-5a0156e40feb/Eigen/Geometry"
#include "fgh_def.h"
#include "armijo.h"
#include "golden_section.h"
#include "bisection.h"
#include <ctime>

class Gradient_Descent
{
	private:
		Eigen::VectorXd x_c;
		int type_search,dimension,iter,count;
		double tol,alpha;
	public:

		Eigen::VectorXd optimize( int _dimension, double _alpha, Eigen::VectorXd _x_c, double _tol, int _type_search )	
		{
			tol = _tol;
			dimension = _dimension;
			type_search = _type_search;
			alpha = _alpha;

			//*****************************************************DECLARATIONS******************************************************//
			Eigen::VectorXd dir_vec(dimension);
			Eigen::VectorXd x_c(dimension);
			Eigen::VectorXd grad_vec(dimension);
			int iter_count = 0;				//Counter for iterations
			int iter = 5e4;					//Restriction on Maximum Number of Iterations Permissible
			double step_size;				//Step Size to be taken
			fgh_def evaluator( dimension,alpha );

			//*****************************************************INITIALIZE********************************************************//			
			x_c = _x_c;
			grad_vec = evaluator.grad_eval(x_c);
			if (type_search==1) { std::cout<< "Initializing Armijo Search......................\n"  << std::endl; }
			if (type_search==2) { std::cout<< "Initializing Golden Section Search................\n"  << std::endl; }
			if (type_search==3) { std::cout<< "Initializing BiSection Search.....................\n"  << std::endl; }

			//*************************************************STEEPEST DESCENT*******************************************************//
			while ( grad_vec.norm() > tol && iter_count < iter )
			{
				iter_count += 1;
				dir_vec = -grad_vec;
				dir_vec = dir_vec / dir_vec.norm();
				if (type_search==1) { step_size = armijo::line_search( x_c, dir_vec,&evaluator ); }
				if (type_search==2) { step_size = goldensection::line_search(x_c, dir_vec,&evaluator); }
				if (type_search==3) { step_size = bisection::line_search(x_c, dir_vec,&evaluator); }
				x_c = x_c + step_size*dir_vec;
				grad_vec = evaluator.grad_eval(x_c);
				// std::cout<< "\nX value:\n"<< x_c <<"Gradient Value at X:\n" <<grad_vec.norm() <<"\nFunction Value at X:\n"<<evaluator.func_eval(x_c)<<std::endl; 	
			}
			std::cout<< "Gradient Descent Completed. Number of Iterations:  " << iter_count << "\n" << std::endl;
			return x_c;
		}
};

#endif