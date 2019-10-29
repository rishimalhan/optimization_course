// This is the exmaple problem that was done in lecture.

#include <iostream>
#include "ilcplex/ilocplex.h"

using namespace std;


int main(int argc, const char *argv[])
{
	IloEnv env;
	IloModel mod(env);

	IloNumVarArray d (env, 3, -IloInfinity, IloInfinity, ILOFLOAT);
	d.setNames("d");
	IloNumVarArray x (env, 3, 0, IloInfinity, ILOFLOAT);
	x.setNames("x");
	IloNumVarArray L (env, 2, -IloInfinity, IloInfinity, ILOFLOAT);
	L.setNames("L");

	IloExpr obj(env);
	obj = x[0] + 2*x[1] + 3*x[2] - 0.5*( 33*x[0]*x[0] + 22*x[1]*x[1] + 11*x[2]*x[2] - 12*x[0]*x[1] - 23*x[1]*x[2] ) + L[0]*(- x[0] + x[1] + x[2] - 20 ) + L[1]*(x[0] - 3*x[1] + x[2] - 30);

	cout<< obj<< endl;

	return 0;
}