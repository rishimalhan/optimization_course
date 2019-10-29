#include <iostream>
#include "ilcplex/ilocplex.h"
#include <cmath>


using namespace std;

int main(int argc, const char * argv[])
{
	int  a = 1;
	// Linear approximation of the primal. Returns d and lambda.
	IloEnv env;
	IloModel mod(env);
	IloNumVarArray d(env, 7, 0, IloInfinity, ILOFLOAT);	// d: 0-6 are: z,fx1,fx2,w1,w2,u1,u2
	d.setNames("d");


	// Inequality constraints
	mod.add( -d[0] + d[5] + d[3] - d[0] + d[5] + d[3] <= 0 );
	mod.add( -d[0] + d[6] + d[4] - d[0] + d[6] + d[4] <= 0 );
	mod.add( -d[5] <= 0 );
	mod.add( -d[6] <= 0 );
	mod.add( -d[3] <= 0 );
	mod.add( -d[4] <= 0 );

	//Equality Constraints
	mod.add( d[1] - 2.0 * d[2] + 5*d[2] - d[2] - d[5] - d[3] -13 - d[5] - d[3]  <= 0.0);
	mod.add( d[1] - 14 * d[2] + d[2]+ d[2] - d[6] - d[4] - 29 - d[6] - d[4] <=  0.0 );

	IloExpr obj (env);
    obj = d[0];
    mod.add( IloMinimize(env, obj) );

	IloCplex cpx (env);
    cpx.extract( mod );
    cpx.exportModel("QP.lp");
    cpx.solve();
    
    cout << cpx.getObjValue() << endl;
    for (int i=0; i<7; i++) {
        cout <<  cpx.getValue( d[i] ) << "\t";
    }
	
	if ( !cpx.solve() ) {
	    env.error() << "Failed to optimize LP." << endl;
	    throw(-1);
    }
    cpx.setOut( env.getNullStream() );
    IloNumArray dual_values(env);
    cpx.getDuals(dual_values,mod);
    for (int i=0; i<7; i++)
    {
    	cout<< dual_values[i] <<"\t";
    }

    env.end();

	return 0;
}