// Header file for BiSection Search
/* Author- Rishi Malhan. */  

#ifndef bisection_H
#define bisection_H
#include <iostream>
#include <cmath>
#include "eigen-eigen-5a0156e40feb/Eigen/Core"
#include "eigen-eigen-5a0156e40feb/Eigen/Dense"
#include "eigen-eigen-5a0156e40feb/Eigen/Geometry"
#include "fgh_def.h"

//**********************************************************GENERIC ALGORITHM************************************************************//

/* Generic Algorithm for Golden Section Search Method. It takes in vec_x of the Point from where search starts and 
    dir_vec or the direction of search in a space with n dimensions. */

namespace bisection
{
    int dimension,iter;
    double a,b,tol,epsilon;
    Eigen::VectorXd dir_vec , x_vec;
    fgh_def* _evaluator;

    //Function t_to_x converts the Parameter t in [0,1] to n dimension space.
    Eigen::VectorXd t_to_x (double t) {
        Eigen::VectorXd xp = x_vec + ( a + t*(b-a) ) * dir_vec;
        return xp;
    }    

    //Function evaluation at the point xp which is n dimensional point. It is passed to function equation
    double func_eval (double t) {
        Eigen::VectorXd xp = t_to_x (t);
        return _evaluator->func_eval(xp);
    }

    double line_search( Eigen::VectorXd  _x_vec, Eigen::VectorXd _dir_vec, fgh_def* eval )
    {
        //********************DEFINITIONS*************************//
        
        _evaluator = eval;
        dimension = _evaluator->dimension;;
        iter = 1e5;
        epsilon = 1e-5;

        //*********************DETERMINE INTERVAL******************//
        dir_vec = _dir_vec;
        x_vec = _x_vec;
        double f_xc;
        double step = 1e-8;
        f_xc = _evaluator->func_eval(x_vec);
        double eeta = 2;
        while ( (_evaluator->func_eval(x_vec + step*dir_vec) - f_xc) <= 0.0 )
        {
            step = step*eeta;
        }
        a = 0.0;
        b = step;
        double tol = 1e-2/(b-a);   //Normalizing the tolerance to use parameter t from [0,1]


        //***********************DECLARATIONS*********************//
        double x_low = 0.0;   //Lower Bound for the Interval
        double x_high = 1.0;  //Upper Bound for the Interval
        double x_right; //Point at golden ratio r from lower bound
        double x_left;  //Point at golden ratio 1-r from lower bound
        int count=0;    //Keep a count of iterations
        double f_left;  //Function evaluation at x_left
        double f_right; //Function evaluation at x_right

        //***********************Search Algorithm******************//
        while ( fabs(x_high - x_low) > tol && (count < iter) )
        {
            x_right = (x_low + x_high)/2 + epsilon/2;
            x_left = (x_low + x_high)/2 - epsilon/2;
            f_right = func_eval(x_right);
            f_left = func_eval(x_left);
            count += 1;

            if (f_right > f_left)   //If the Right evaluation is greater than Left
            {
                x_high = x_right;
            }
            else                    //If the Right evaluation is lesser than Left
            {
                x_low = x_left;
            }
        }
        Eigen::VectorXd optima = t_to_x( (x_high + x_low)/2 );
        step = (optima-x_vec).norm()/dir_vec.norm();
        return step;
    }
}
#endif