/* This code is the Function, Gradient and Hessian Definitions of Rosenbrock Function required by the Algorithms. 
It evaluates the corresponding elements based on Generic Patterns of Gradient and Hessian */
/* Author- Rishi Malhan. */  

#ifndef fgh_def_H
#define fgh_def_H
#include <iostream>
#include <cmath>
#include "eigen-eigen-5a0156e40feb/Eigen/Core"
#include "eigen-eigen-5a0156e40feb/Eigen/Dense"
#include "eigen-eigen-5a0156e40feb/Eigen/Geometry"

class fgh_def
{
	public:
		int dimension;		//This is the Dimension of Function Evaluation
		double alpha;			//Parameter alpha for Rosenbrock Function
		Eigen::VectorXd X;	//Eigen Vector pointing to the Point of evaluation
	public:
		fgh_def(int _dimension, int _alpha)
		{
			alpha = _alpha;
			dimension = _dimension;
		}

		double func_eval(Eigen::VectorXd _X)
		{
			X = _X;
			double val = 0.0;		//Value of Function. It adds to itself after every iteration.
			for (int i = 1; i <= (dimension/2); i++)
			{
				val = val + ( alpha * pow( (X(2*i-1) - pow(X(2*i-1-1),2)), 2 ) + pow(( 1.0 - X(2*i-1-1) ),2) );
			}
			return val;

		}

		Eigen::VectorXd grad_eval(Eigen::VectorXd _X)
		{
			Eigen::VectorXd grad_vec(dimension);
			X = _X;
			for (int i = 1; i<=dimension; i+=2)
			{
				grad_vec.row(i-1) << ( -2.0*alpha*( X(i+1-1)-pow( X(i-1),2 ) ) * (2.0*X(i-1)) - 2.0*(1.0-X(i-1)) );
				grad_vec.row(i+1-1) << ( 2.0*alpha*( X(i+1-1)-pow( X(i-1),2 ) ) );
			}
			return grad_vec;
			
		}

		Eigen::MatrixXd hess_eval(Eigen::VectorXd _X)
		{
			Eigen::MatrixXd hess_mat(dimension,dimension);
			X = _X;

			for (int i = 1; i<=dimension; i++)
			{
				for (int j = 1; j<=dimension; j++)
				{
					// If row is Odd
					if ( i%2!=0 )
					{
						if( i==j ) { hess_mat(i-1,j-1) = -4.0*alpha* (X(i+1-1) - (pow( X(i-1),2 )) ) + (8.0*alpha*pow(X(i-1),2)) + 2.0; }
						if( j==(i+1) ) { hess_mat(i-1,j-1) = -4.0*alpha*X(i-1); }
						if( i!=j && j!=(i+1) ) { hess_mat(i-1,j-1) = 0.0; }
					}

					// If row is Even
					if( i%2==0 )
					{
						if( i==j ) { hess_mat(i-1,j-1) = 2.0*alpha; }
						if( j==(i-1) ) { hess_mat(i-1,j-1) = -4.0*alpha*X(i-1-1); }
						if( i!=j && j!=(i-1) ) { hess_mat(i-1,j-1) = 0.0; }
					}
				}
			}

			return hess_mat;	
		}

};

#endif