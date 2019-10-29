
 // main.cpp
 // QPsolve

 // Created by Semih Atakan on 11/20/17.
 // Copyright © 2017 Semih Atakan. All rights reserved.

	// Adapted from CPLEX example iloqpex1.cpp

 //   Maximize
 //    obj: x1 + 2 x2 + 3 x3
 //           - 0.5 ( 33*x1*x1 + 22*x2*x2 + 11*x3*x3
 //                            - 12*x1*x2 - 23*x2*x3 )
 //   Subject To
 //    c1: - x1 + x2 + x3 <= 20
 //    c2: x1 - 3 x2 + x3 <= 30
 //   Bounds
 //    0 <= x1 <= 40
 //   End


#include <iostream>
#include "ilcplex/ilocplex.h"

using namespace std;

int main(int argc, const char * argv[]) {

    IloEnv      env;
    IloModel    mod (env);

    IloNumVarArray x (env, 3, 0, IloInfinity, ILOFLOAT);
    
    x.setNames("x");
    
    // Constraint 1
    // Option 1
    mod.add( -x[0] + x[1] + x[2] <= 20 );
    
    // Option 2
    IloExpr     expr (env);
    expr += ( -x[0] + x[1] + x[2] );

    //IloRange con (env, -IloInfinity, expr, 20);
    //expr.end();
    //mod.add( con );

    
    // Constraint 2
    mod.add( x[0] - 3 * x[1] + x[2] <= 30 );
    
    // Objective Function
    // x1 + 2 x2 + 3 x3
    //            - 0.5 ( 33*x1*x1 + 22*x2*x2 + 11*x3*x3
    //                             - 12*x1*x2 - 23*x2*x3 )
    IloExpr obj (env);
    obj += x[0] + 2 * x[1] + 3 * x[2];
    obj -= 0.5 * ( 33 * x[0] * x[0] + 22 * x[1] * x[1] + 11 * x[2] * x[2] - 12 * x[0] * x[1] - 23 * x[1] * x[2]);
    
    mod.add( IloMaximize(env, obj) );

    // Upper bound x1
    x[0].setUB( 40 );
    
    
    IloCplex cpx (env);
    cpx.extract( mod );

    //cpx.setOut( env.getNullStream() );    // no output
    
    cpx.exportModel("QP.lp");
    
    cpx.solve();
    
    cout << cpx.getObjValue() << endl;
    for (int i=0; i<3; i++) {
        cout << cpx.getValue( x[i] ) << "\t";
    }
    cout << endl;
    
    cout << cpx.getValue( expr ) << endl;
    
    env.end();
    
    return 0;
}

// #include <ilcplex/ilocplex.h>
// ILOSTLBEGIN
// int main (int argc, char **argv)
// {
//     IloEnv env;
//     try {
//     IloModel model(env);
//     IloNumVarArray vars(env);
//     vars.add(IloNumVar(env, 0.0, 40.0));
//     vars.add(IloNumVar(env));
//     vars.add(IloNumVar(env));
//     model.add(IloMaximize(env, vars[0] + 2 * vars[1] + 3 * vars[2]));
//     model.add( - vars[0] + vars[1] + vars[2] <= 20);
//     model.add( vars[0] - 3 * vars[1] + vars[2] <= 30);
//     IloCplex cplex(model);
//     if ( !cplex.solve() ) {
//     env.error() << "Failed to optimize LP." << endl;
//     throw(-1);
//     }
//     IloNumArray vals(env);
//     env.out() << "Solution status = " << cplex.getStatus() << endl;
//     env.out() << "Solution value = " << cplex.getObjValue() << endl;
//     cplex.getValues(vals, vars);
//     env.out() << "Values = " << vals << endl;
//     }
//     catch (IloException& e) {
//     cerr << "Concert exception caught: " << e << endl;
//     }
//     catch (...) {
//     cerr << "Unknown exception caught" << endl;
//     }

//     env.end();
//     return 0;
// }