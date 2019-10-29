#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>

std::ofstream file;

//Function which is written in the main script. Run only one function at a time.
double fun(double x) { 
        return pow(x,3) - 3*pow(x,2);  //Function-1 to optimize.
        // return exp(x) - 2*x;
    }

double gradient(double x) {  
        return 3*pow(x,2) - 6*x;
        // return exp(x) - 2;  
    }

double hessian(double x) {
		return 6*x - 6;
		// return exp(x);
	}



//********************************************************NEWTON'S METHOD in ID********************************************//
class newton1d
{
	private:
		double a , b;			//a is the lower and b is upper bound of interval of search
		double x_int, tol, iter;	//Initial Value to begin Search is x_int and Tolerance for gradient is _tol. Max iterations is iter.
		double alpha , theta;	//alpha is the step length in which case it is not 1. Armijo's parameter is theta.

	public:
		newton1d(double _a, double _b, double _x_int, double _tol, int _iter)
		{
			a = _a;
			b = _b;
			x_int = _x_int;
			tol = _tol;
			iter = _iter;
			theta = 0.5;
		}

		std::pair<double,int> newton_search()
		{
			//********************************DECLARATIONS********************************************************//
			double x_c;			//Current Value of X in iteration
			double x_nxt;		//Next Value of X from iteration
			double f_c;			//Current Evaluation of Function at X_C
			double f_nxt;		//Evaluation of Function at next value X_nxt
			double dir;			//Direction Value of X at x_c
			double G;			//Evaluation of Gradient at x_c
			double H;			//Evaluation of Hessian at x_c
			double counter = 0;		//Counter to restrict iterations
			alpha = 0;

			//*********************************INITIALIZATION*****************************************************//
			x_c = x_int;
			f_c = fun(x_c);
			G = gradient(x_c);
			H = hessian(x_c);
			file<< counter << "," << x_c << "," << fun(x_c) << "," << G << "," << H << "\n";
			std::cout<< counter << "\t" << x_c << "\t" << f_c << "\t" << G << "\t" << H <<std::endl;

			//********************************ALGORITHM**********************************************************//
			while (fabs(G) > tol && counter < iter)
			{
				counter += 1;
			//Inducing correction for Hessian if it is non Positive Definite
				if (H<=0.0) { dir = -G; }
				else if (H>0.0) { dir = -(G/H); }
			//Correcting for Directional Derivative being Positive
				if (dir>0.0) { alpha = std::min( 1.0 , ( b-x_c)/dir ); }
				else if (dir<=0.0) { alpha = std::min( 1.0 , ( a-x_c)/dir ); }
			//Updating new Point
				x_nxt = x_c + alpha * dir;
				f_nxt = fun(x_nxt);
			//Correction for Increase in Function value than the reduction
				while (f_nxt >= f_c)
				{
					alpha = theta * alpha;
					x_nxt = x_c + alpha * dir;
					f_nxt = fun(x_nxt);
				}
			//Updating Previoud point with new point
				x_c = x_nxt;
				f_c = f_nxt;
				G = gradient(x_c);
				H = hessian(x_c);
				std::cout<< counter << "\t" << x_c << "\t" << f_c << "\t" << G << "\t" << H <<std::endl;
				file<< counter << "," << x_c << "," << fun(x_c) << "," << G << "," << H << "\n";
			}

			return std::make_pair(x_c,counter);
		}	


};








//**********************************************************************MAIN BODY********************************************************//
//NOTE: Comment one Function here and above in Function, Gradient and Hessian Declarations and run the other
int main()
{
	//***************************************DECLARATIONS**********************************************************************//
	double a , b;				//a is the lower and b is upper bound of interval of search
	double x_int, tol, iter;	//Initial Value to begin Search is x_int and Tolerance for gradient is _tol. Max iterations is iter.



//*******************************************************************************FUNCTION-1*******************************************************************//
	//****************************************INITIALIZATION******************************************************************//
	file.open("Newton's_1D_Search_Function1.csv");
	file << "Iteration" << "," << "X_Value" << ","<<"Func_Eval"<< "," << "Gradient"<< "," << "Hessian" << "\n";
	a = 1;
	b = 4;
	x_int = 1.2;
	tol = 1e-8;
	iter = 20;

	newton1d n1d(a , b , x_int, tol, iter);
	std::pair<double,int> result = n1d.newton_search();

	std::cout << "\nNumber of Iterations Required:  " << result.second  <<std::endl;
	std::cout << "Optimum Value:  " << result.first << "\t" << "Function Value:  "<< fun(result.first) <<std::endl;




// //*******************************************************************************FUNCTION-2*******************************************************************//
// 	//****************************************INITIALIZATION******************************************************************//
// 	file.open("Newton's_1D_Search_Function2.csv");
// 	file << "Iteration"<< "," << "X_Value"<< "," <<"Func_Eval"<< "," << "Gradient"<< "," << "Hessian" << "\n";
// 	a = 0;
// 	b = 1;
// 	x_int = 0.2;
// 	tol = 1e-8;
// 	iter = 20;

// 	newton1d n1d(a , b , x_int, tol, iter);
// 	std::pair<double,int> result = n1d.newton_search();

// 	std::cout << "\nNumber of Iterations Required:  " << result.second  <<std::endl;
// 	std::cout << "Optimum Value:  " << result.first << "\t" << "Function Value:  "<< fun(result.first) <<std::endl;

	return 0;
}