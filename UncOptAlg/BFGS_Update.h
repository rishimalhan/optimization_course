/* Author- Rishi Malhan. */ 

#ifndef BFGS_Update_H
#define BFGS_Update_H
#include "Cholesky_Decomposition.h"

Eigen::MatrixXd update_B( Eigen::MatrixXd _B, Eigen::VectorXd _dx, Eigen::VectorXd _dg )
{
	int dimension = _dg.size();
	Eigen::VectorXd dx(dimension);
	Eigen::VectorXd dg(dimension);
	Eigen::MatrixXd B = Eigen::MatrixXd(dimension,dimension);
	Eigen::MatrixXd B_updated = Eigen::MatrixXd(dimension,dimension);
	B = _B;
	dx = _dx;
	dg = _dg;

	if (dg.transpose()*dx <= 0.0) { return B; }
	B_updated = ( B - ( (B*(dx*dx.transpose())*B.transpose()) / (dx.transpose()*B.transpose()*dx) ) + ( dg*dg.transpose() ) / (dg.transpose()*dx) );
	return B_updated;
}
#endif