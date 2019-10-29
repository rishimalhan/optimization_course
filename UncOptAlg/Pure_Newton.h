/* This code is the Main script for Steepest Descent Algorithm for Optimization in ND. */ 
/* Author- Rishi Malhan. */  

#ifndef Pure_Newton_H
#define Pure_Newton_H
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

class Pure_Newton
{
	private:
		Eigen::VectorXd x_c;
		int dimension,iter,count;
		double tol,alpha;
	public:

		Eigen::VectorXd optimize( int _dimension, double _alpha, Eigen::VectorXd _x_c, double _tol )	
		{
			tol = _tol;
			dimension = _dimension;
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
			int grad_step = 0;

			//*****************************************************INITIALIZE********************************************************//			
			x_c = _x_c;
			grad_vec = evaluator.grad_eval(x_c);
			hessian = evaluator.hess_eval(x_c);
			
			//*************************************************STEEPEST DESCENT*******************************************************//
			while ( grad_vec.norm() > tol && iter_count < iter )
			{
				grad_step = 0;
				step_size = 1.0;
				iter_count += 1;
				// Cholesky Factorization and Updating Hessian if not Positive Definite.
				factorizer.ldl(hessian);
				L = factorizer.getL();
				D = factorizer.getD();	
				// Check for Positive Definitiveness
				for (int k = 0; k < D.rows(); k++)	
				{ 
					if(D(k,k)<=0) 
					{ 
						grad_step = 1; 
					} 
				}

				if (grad_step==1)
				{
					dir_vec = (-grad_vec);
					dir_vec = dir_vec / dir_vec.norm();
					step_size = goldensection::line_search(x_c, dir_vec,&evaluator);
				}
				else
				{
					hessian = L*D*L.transpose();
					dir_vec = hessian.ldlt().solve(-grad_vec);
				}
				x_c = x_c + step_size*dir_vec;
				grad_vec = evaluator.grad_eval(x_c);
				hessian = evaluator.hess_eval(x_c);
			}
			std::cout<< "Pure Newton's Method Completed. Number of Iterations:  " << iter_count << "\n" << std::endl;
			return x_c;
		}
};

#endif