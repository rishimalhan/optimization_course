/* This code is the Main script for Steepest Descent Algorithm for Optimization in ND. */ 
/* Author- Rishi Malhan. */  

#ifndef Newton_ND_H
#define Newton_ND_H
#include <iostream>
#include <cmath>
#include "eigen-eigen-5a0156e40feb/Eigen/Core"
#include "eigen-eigen-5a0156e40feb/Eigen/Dense"
#include "eigen-eigen-5a0156e40feb/Eigen/Geometry"
#include "fgh_def.h"
#include "armijo.h"
#include "golden_section.h"
#include "bisection.h"
#include "Cholesky_Decomposition.h"
#include <ctime>
#include <tuple>

class Newton_ND
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
			Eigen::MatrixXd hessian(dimension,dimension);
			Eigen::MatrixXd L(dimension,dimension);
			Eigen::MatrixXd D(dimension,dimension);
			int iter_count = 0;				//Counter for iterations
			int iter = 5e4;					//Restriction on Maximum Number of Iterations Permissible
			double step_size;				//Step Size to be taken
			fgh_def evaluator( _dimension,alpha );	//Function, Gradient and Hessian Evaluators
			cholesky factorizer(dimension);

			//*****************************************************INITIALIZE********************************************************//			
			x_c = _x_c;
			grad_vec = evaluator.grad_eval(x_c);
			hessian = evaluator.hess_eval(x_c);
			if (type_search==1) { std::cout<< "Initializing Armijo Search......................\n"  << std::endl; }
			if (type_search==2) { std::cout<< "Initializing Golden Section Search................\n"  << std::endl; }
			if (type_search==3) { std::cout<< "Initializing BiSection Search.....................\n"  << std::endl; }
			
			//*************************************************STEEPEST DESCENT*******************************************************//
			while ( grad_vec.norm() > tol && iter_count < iter )
			{
				iter_count += 1;
				// Cholesky Factorization and Updating Hessian if not Positive Definite.
				factorizer.ldl(hessian);
				L = factorizer.getL();
				D = factorizer.getD();	
				// Check for Positive Definitiveness
				for (int k = 0; k < D.rows(); k++)	{ if(D(k,k)<=0) { D(k,k)=1.2; } }
				hessian = L*D*L.transpose();
				dir_vec = hessian.ldlt().solve(-grad_vec);
				dir_vec = dir_vec / dir_vec.norm();
				if (type_search==1) { step_size = armijo::line_search( x_c, dir_vec,&evaluator ); }
				if (type_search==2) { step_size = goldensection::line_search(x_c, dir_vec,&evaluator); }
				if (type_search==3) { step_size = bisection::line_search(x_c, dir_vec,&evaluator); }
				if (step_size > 1.0) { step_size=1.0; }
				x_c = x_c + step_size*dir_vec;
				grad_vec = evaluator.grad_eval(x_c);
				hessian = evaluator.hess_eval(x_c);
				// std::cout<< "\nX value:\n"<< x_c <<"Gradient Value at X:\n" <<grad_vec.norm() <<"\nFunction Value at X:\n"<<evaluator.func_eval(x_c)<<std::endl;
			}
			std::cout<< "Modified Newton's Method Completed. Number of Iterations:  " << iter_count << "\n" << std::endl;
			return x_c;
		}
};

#endif