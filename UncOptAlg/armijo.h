// Header file for Armijo search
/* Author- Rishi Malhan. */  

#ifndef armijo_H
#define armijo_H
#include <iostream>
#include <cmath>
#include "eigen-eigen-5a0156e40feb/Eigen/Core"
#include "eigen-eigen-5a0156e40feb/Eigen/Dense"
#include "eigen-eigen-5a0156e40feb/Eigen/Geometry"
#include "fgh_def.h"


//**********************************************************GENERIC ALGORITHM************************************************************//
/* Generic Algorithm for Armijo's Rule. It takes in vec_x of the Point from where search starts and 
    dir_vec or the direction of search in a space with n dimensions. */

namespace armijo
{
	int dimension;
    double alpha,theta,eeta;
    double a;			//Parameter for Function Evaluation
    /* alpha is the initial step length that armijo's rule starts from. theta is the parameter that controls the convex-combination
    of armijo's rule or f(x+alpha*d) <= f(x) + theta * alpha*gradient*d. eeta is the parameter that is multiplied or divided based
    on the evaluation of armijo's condition. If initial point is above the convex combination line then eeta is divided and if it
    is below then multiplied. */
    Eigen::VectorXd dir_vec , x_vec;	//These are the vectors that contain information about the initial point and search direction
    fgh_def* _evaluator;


	//Function t_to_x converts the Parameter t or step-length along unit direction to n dimension space.
    Eigen::VectorXd t_to_x (double t) {
        Eigen::VectorXd xp = x_vec + ( t ) * dir_vec;
        return xp;
    }    

	//Function evaluation at the point xp which is n dimensional point. It is passed to function equation
    double func_eval (double t) {
        Eigen::VectorXd xp = t_to_x (t);
        return _evaluator->func_eval(xp);
    }

    Eigen::VectorXd grad_eval(double t) {
    	Eigen::VectorXd xp = t_to_x (t);
        return _evaluator->grad_eval(xp);
    }


// Search based on parameter t or step-length in our case. It finds the best acceptable step length.
	double line_search(Eigen::VectorXd  _x_vec, Eigen::VectorXd _dir_vec, fgh_def* eval)
	{
        //***********************DECLARATIONS*********************//
        _evaluator = eval;
		dimension = _evaluator->dimension;
        alpha = 1e-8;
        theta = 0.1;
        eeta = 2;

        dir_vec = _dir_vec;
        x_vec = _x_vec;
		double t = 0;				//Initial Value or x_k
		Eigen::VectorXd grad_vec;	//Gradient Vector at that point
			double dir_derv;			//Directional Derivative
			Eigen::VectorXd xopt;		//Optimum x
			int iter = 1e5;
			int counter = 0;

        //************************INITIALIZE***********************//
        double step = alpha;
			double f_t = func_eval(t);	//Function Evaluation at Start Point
		dir_derv = grad_eval(t).dot(dir_vec);	//Find the Directional Derivative, a scalar Qty

		//********************ARMIJO ITERATIONS*******************//
		//Check for Armijo's Condition Being met or not.
		if (func_eval(t + step) <= f_t + theta * step * dir_derv)
		{
			while ((func_eval(t + step) <= f_t + theta * step * dir_derv) && counter < iter)
			{
				counter += 1;
				step = eeta * step;
			}
			step = step / eeta;
		}
		else if (func_eval(t + step) > f_t + theta * step * dir_derv)
		{
			while ((func_eval(t + step) > f_t + theta * step * dir_derv) && counter < iter)
			{
				counter += 1;
				step =  step / eeta;
			}
			step = step / eeta;
		}
		return step;
	}

}
#endif