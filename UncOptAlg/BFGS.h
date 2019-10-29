/* This code is the Main script for Steepest Descent Algorithm for Optimization in ND. */ 
/* Author- Rishi Malhan. */ 

#ifndef BFGS_H
#define BFGS_H
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
#include "BFGS_Update.h"
#include <ctime>
#include <tuple>

class BFGS
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
			Eigen::VectorXd x_p(dimension);			// Previous Point
			Eigen::VectorXd x_c(dimension);			// Current Point
			Eigen::VectorXd g_p(dimension);	//Gradient at Previous Point
			Eigen::VectorXd g_c(dimension);	//Gradient at Current Point
			Eigen::VectorXd dx = Eigen::VectorXd::Ones(dimension);
			Eigen::VectorXd dg = Eigen::VectorXd::Ones(dimension);
			Eigen::MatrixXd B = Eigen::MatrixXd::Identity(dimension,dimension);
			Eigen::MatrixXd L(dimension,dimension);
			Eigen::MatrixXd D(dimension,dimension);
			int iter_count = 0;				//Counter for iterations
			int iter = 5e4;					//Restriction on Maximum Number of Iterations Permissible
			double step_size;				//Step Size to be taken
			fgh_def evaluator( _dimension,alpha );	//Function, Gradient and Hessian Evaluators
			cholesky factorizer(dimension);

			//*****************************************************INITIALIZE********************************************************//			
			x_p = _x_c;
			g_p = evaluator.grad_eval(x_p);
			if (type_search==1) { std::cout<< "Initializing Armijo Search......................\n"  << std::endl; }
			if (type_search==2) { std::cout<< "Initializing Golden Section Search................\n"  << std::endl; }
			if (type_search==3) { std::cout<< "Initializing BiSection Search.....................\n"  << std::endl; }

			//*************************************************STEEPEST DESCENT*******************************************************//
			while ( g_p.norm() > tol && iter_count < iter )
			{
				iter_count += 1;
				if(iter_count!=1)	{ B = update_B( B,dx,dg ); }
				dir_vec = B.ldlt().solve(-g_p);
				dir_vec = dir_vec / dir_vec.norm();
				if (type_search==1) { step_size = armijo::line_search( x_p, dir_vec,&evaluator ); }
				if (type_search==2) { step_size = goldensection::line_search(x_p, dir_vec,&evaluator); }
				if (type_search==3) { step_size = bisection::line_search(x_p, dir_vec,&evaluator); }
				x_c = x_p + step_size*dir_vec;
				g_c = evaluator.grad_eval(x_c);
				dg = g_c - g_p;
				dx = x_c - x_p;
				x_p = x_c;
				g_p = g_c;
				// std::cout<< "\nX value:\n"<< x_p <<"Gradient Value at X:\n" <<g_p.norm() <<"\nFunction Value at X:\n"<<evaluator.func_eval(x_p)<<std::endl;
			}
			std::cout<< "Quasi Newton BFGS Completed. Number of Iterations:  " << iter_count << "\n" << std::endl;
			return x_c;
		}
};
#endif