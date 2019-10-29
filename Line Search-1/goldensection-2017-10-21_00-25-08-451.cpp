String path_to_eign = "C:/Users/Rishi Malhan/Documents/optimization/eigen-eigen-5a0156e40feb";

#include <iostream>
#include <cmath>
#include <vector>
#include path_to_eign
// #include </Eigen/Core>
// #include <C:\Users\Rishi Malhan\Documents\optimization\eigen-eigen-5a0156e40feb/Eigen/Dense>
// #include <C:\Users\Rishi Malhan\Documents\optimization\eigen-eigen-5a0156e40feb/Eigen/Geometry>
#include <fstream>

std::ofstream file;

//Function which is written in the main script. Run only one function at a time.
double fun(double x) { 
        return pow(x,3) - 3.0*pow(x,2);  //Problem-1 Function to optimize.
        // return 20 / x + pow(x,2);           //Problem-2 Function to optimize. This is reduced form of area function based on given relations.
    }



//**********************************************************GENERIC ALGORITHM************************************************************//


/* Generic Algorithm for Golden Section Search Method. It takes in vec_x of the Point from where search starts and 
    dir_vec or the direction of search in a space with n dimensions. */
class goldensection
{
    private:
        int dimension,iter;
        double golden_ratio,a,b,tol;
        Eigen::VectorXd dir_vec , x_vec;
    public:
        goldensection(int n,double _a, double _b, int _iter, double _tol, Eigen::VectorXd _dir_vec , Eigen::VectorXd  _x_vec)
        {
            dimension = n;
            iter = _iter;
            a = _a;
            b = _b;
            tol = _tol/(b-a);   //Normalizing the tolerance to use parameter t from [0,1]
            dir_vec = _dir_vec;
            x_vec = _x_vec;
            golden_ratio = 0.618;

        }

        //Function t_to_x converts the Parameter t in [0,1] to n dimension space.
        Eigen::VectorXd t_to_x (double t) {
            Eigen::VectorXd xp = x_vec + ( a + t*(b-a) ) * dir_vec;
            return xp;
        }    

        //Function evaluation at the point xp which is n dimensional point. It is passed to function equation
        double func_eval (double t) {
            Eigen::VectorXd xp = t_to_x (t);
            double x = xp(0);
            return fun(x);
        }

        void search()
        {
            //***********************DECLARATIONS*********************//
            double x_low = 0.0;   //Lower Bound for the Interval
            double x_high = 1.0;  //Upper Bound for the Interval
            double x_right; //Point at golden ratio r from lower bound
            double x_left;  //Point at golden ratio 1-r from lower bound
            int count=0;    //Keep a count of iterations
            double f;       //Evaluation at Optimum
            double xopt;    //Optimum Value
            double f_left;  //Function evaluation at x_left
            double f_right; //Function evaluation at x_right

            //************************INITIALIZE***********************//
            x_right = x_low + golden_ratio * (x_high-x_low);
            x_left = x_low + (1-golden_ratio) * (x_high-x_low);
            f_right = func_eval(x_right);
            f_left = func_eval(x_left);

            //***********************Search Algorithm******************//
            while ( fabs(x_high - x_low) > tol && (count < iter) )
            {
                count += 1;
                if (f_right > f_left)   //If the Right evaluation is greater than Left
                {
                    x_high = x_right;
                    x_right = x_left;
                    f_right = f_left; 
                    x_left = x_high - golden_ratio * (x_high-x_low);
                    f_left = func_eval(x_left);        
                    xopt = (x_high + x_low)/2;
                    f = func_eval(xopt);
                    file<< 
                                count << "\t" <<
                                x_low << "\t" <<
                                x_high << "\t" <<
                                x_left << "\t" <<
                                x_right << "\t" <<
                                t_to_x( (x_high + x_low)/2 ) << "\t" << 
                                f << "\n";
                }
                else                    //If the Right evaluation is lesser than Left
                {
                    x_low = x_left;
                    x_left = x_right;
                    f_left = f_right;
                    x_right = x_low + golden_ratio*(x_high-x_low);
                    f_right = func_eval(x_right);
                    xopt = (x_high + x_low)/2;
                    f = func_eval(xopt);
                    file<< 
                                count << "\t" <<
                                x_low << "\t" <<
                                x_high << "\t" <<
                                x_left << "\t" <<
                                x_right << "\t" <<
                                t_to_x( (x_high + x_low)/2 ) << "\t" << 
                                f << "\n";
                }
            }
            xopt = (x_high + x_low)/2; 
            f = func_eval(xopt); //Function Evaluation at Optima
            std::cout<< "Optima reached at: " << t_to_x( (x_high + x_low)/2 ) //Converting the Optima from parameter to n dimension 
            << "\n" << "Value of Function at Optima: " << f << "\n" 
            << "Number of Iterations Required: " << count << std::endl;

        }

};





//Main Body. This is written separately whereever it is being called. Comment one Problem and run other. 
int main()
{
// ***************************Problem-1******************************//
    file.open("Goldensection_Problem-1_Solution.csv");
    file<< "Iteration\t" << "Lower_Bound \t" << "Upper_Bound\t" << "X_left\t" << "X_Right\t" << "X_Optimum\t" << "Function_at_xopt\n";    
    int n = 1;                  //Dimension in 1D
    double _a = 0;
    double _b = 3;
    int _iter = 100;
    double _tol = 1e-4;         //Tolerance

    //Below is input to system as vector in n dimension
    Eigen::VectorXd _dir_vec(n); 
    _dir_vec << 1;
    Eigen::VectorXd  _x_vec(n);
    _x_vec << 0;

    goldensection gs(n, _a, _b, _iter, _tol, _dir_vec, _x_vec);
    gs.search();




//****************************Problem-2*******************************//
    // file.open("Goldensection_Problem-2_Solution.csv");
    // file<< "Iteration\t" << "Lower_Bound \t" << "Upper_Bound\t" << "X_left\t" << "X_Right\t" << "X_Optimum\t" << "Function_at_xopt\n";
    // int n = 1;                //Dimension is in 1D
    // double _a = 0;           
    // double _b = 3;  
    // int _iter = 100;
    // double _tol = 1e-4;

    // //Below is input to system as vector in n dimension
    // Eigen::VectorXd _dir_vec(n); 
    // _dir_vec << 1;
    // Eigen::VectorXd  _x_vec(n);
    // _x_vec << 0;

    // goldensection gs(n, _a, _b, _iter, _tol, _dir_vec, _x_vec);
    // gs.search();



    file.close();    
    return 0;
}