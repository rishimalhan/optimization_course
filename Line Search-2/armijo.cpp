#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <fstream>

std::ofstream file;

//Function which is written in the main script. Run only one function at a time.
double fun(double x) { 
        return 2*pow(x,2) + 15 / x;  //Function to optimize.
    }

Eigen::VectorXd gradient(double x) {
		Eigen::VectorXd _grad_vec(1);
    	_grad_vec << 4*x - 15 / pow(x,2);	//Define the Gradient elements  
        return _grad_vec;  
    }










//**********************************************************GENERIC ALGORITHM************************************************************//
/* Generic Algorithm for Armijo's Rule. It takes in vec_x of the Point from where search starts and 
    dir_vec or the direction of search in a space with n dimensions. */

class armijo
{
	private:
		int dimension;
        double alpha,theta,eeta;
        /* alpha is the initial step length that armijo's rule starts from. theta is the parameter that controls the convex-combination
        of armijo's rule or f(x+alpha*d) <= f(x) + theta * alpha*gradient*d. eeta is the parameter that is multiplied or divided based
        on the evaluation of armijo's condition. If initial point is above the convex combination line then eeta is divided and if it
        is below then multiplied. */
        Eigen::VectorXd dir_vec , x_vec;	//These are the vectors that contain information about the initial point and search direction
    public:
    	armijo(int n, double _alpha, double _theta, double _eeta)
    	{
    		dimension = n;
            alpha = _alpha;
            theta = _theta;
            eeta = _eeta;
    	}

    	//Function t_to_x converts the Parameter t or step-length along unit direction to n dimension space.
        Eigen::VectorXd t_to_x (double t) {
            Eigen::VectorXd xp = x_vec + ( t ) * dir_vec;
            return xp;
        }    

    	//Function evaluation at the point xp which is n dimensional point. It is passed to function equation
        double func_eval (double t) {
            Eigen::VectorXd xp = t_to_x (t);
            double x = xp(0);	//It passed more arguments depending on number of dimensions. For this case n=1
            return fun(x);
        }

        Eigen::VectorXd grad_eval(double t) {
        	Eigen::VectorXd xp = t_to_x (t);
            double x = xp(0);	//It passed more arguments depending on number of dimensions. For this case n=1
            return gradient(x);
        }


// Search based on parameter t or step-length in our case. It finds the best acceptable step length.
    	Eigen::VectorXd armijo_search(Eigen::VectorXd  _x_vec, Eigen::VectorXd _dir_vec)
    	{

            //***********************DECLARATIONS*********************//
            dir_vec = _dir_vec;
            x_vec = _x_vec;
    		double t = 0;				//Initial Value or x_k
    		Eigen::VectorXd grad_vec;	//Gradient Vector at that point
   			double dir_derv;			//Directional Derivative
   			Eigen::VectorXd xopt;		//Optimum x

            //************************INITIALIZE***********************//
            double step = alpha;
   			double f_t = func_eval(t);	//Function Evaluation at Start Point
    		dir_derv = grad_eval(t).dot(dir_vec);	//Find the Directional Derivative, a scalar Qty

    		//********************ARMIJO ITERATIONS*******************//
    		//Check for Armijo's Condition Being met or not.
    		if (func_eval(t + step) <= f_t + theta * step * dir_derv)
    		{
    			while (func_eval(t + step) <= f_t + theta * step * dir_derv)
    			{
    				step = eeta * step;
    			}
    			step = step / eeta;
    		}
    		else if (func_eval(t + step) > f_t + theta * step * dir_derv)
    		{
    			while (func_eval(t + step) > f_t + theta * step * dir_derv)
    			{
    				step =  step / eeta;
				}
				step = step / eeta;
    		}

    		xopt = t_to_x(t + step);
    		return xopt;
    	}

};










//*****************************************************MAIN******************************************************************************//

//This is written separately whereever it is being called. 
int main()
{
	//Two start points for Optimizer.
	int x_start[2];
	x_start[0] = 1;
	x_start[1] = 3;
	file.open("Armijo's Search.csv");

	for (int i=0;i<2;i++)
	{
		file << "Armijo's Search for Start Point with Value:  " << x_start[i] << "\n";
	    file << "Iteration" << "," << "X_Value"<< "," <<"Func_Eval"<< "," << "Gradient" <<  "\n";
	    int n = 1;                  //Dimension in 1D
	    double _alpha = 0.01;		//Initial Step
	    double _theta = 0.5;
	    double _eeta = 2;
	    int iter = 20;				//Max number of iterations
	    double tol = 1e-5;         //Tolerance for Gradient to be within some bounds
	    Eigen::VectorXd grad_vec;	//Gradient Vector at that point
	    Eigen::VectorXd  _x_int(n);	//Initial Point
	    Eigen::VectorXd  _x_vec(n);	//New Point
	   	Eigen::VectorXd _dir_vec(n); 
	   	int counter = 0;				//To keep a count of iterations

	   	//***************************INITIALIZE***********************//
	    _x_int << x_start[i];				//Initial Point in Domain
	    grad_vec = gradient(_x_int(0));
	    _x_vec = _x_int;
	   	armijo arm(n, _alpha, _theta, _eeta);
	   	file<< counter << "," << _x_vec << "," << fun(_x_vec(0)) << "," << grad_vec << "," <<  "\n";

	    //Optimizing the Function till sufficient tolerance is reached
	    while ( grad_vec.norm() > tol && counter < iter )
	    {
	    	counter += 1;
	    	grad_vec = gradient(_x_vec(0));
	    	_dir_vec = -grad_vec;
	    	_x_vec = arm.armijo_search(_x_vec, _dir_vec);
	    	file<< counter << "," << _x_vec << "," << fun(_x_vec(0)) << "," << grad_vec << "," <<  "\n";
	    }
	    std::cout << "Search for Start Point Number:  " << i+1 <<std::endl;
	    std::cout << "Number of Iterations: \t" << counter  <<std::endl;
	    std::cout<< "Optimum Point: \t" << _x_vec << "\t" <<"Optimum Value: \t" << fun(_x_vec(0)) << "\n" <<std::endl;
	    file << "\n\n\n\n";
	}
}