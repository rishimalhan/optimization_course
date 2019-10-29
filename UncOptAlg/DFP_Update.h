/* Author- Rishi Malhan. */ 

#ifndef DFP_Update_H
#define DFP_Update_H
#include "Cholesky_Decomposition.h"

Eigen::MatrixXd update_H( Eigen::MatrixXd _H, Eigen::VectorXd _dx, Eigen::VectorXd _dg )
{
	int dimension = _dg.size();
	Eigen::VectorXd dx(dimension);
	Eigen::VectorXd dg(dimension);
	Eigen::MatrixXd H = Eigen::MatrixXd(dimension,dimension);
	Eigen::MatrixXd H_updated = Eigen::MatrixXd(dimension,dimension);
	Eigen::MatrixXd eye = Eigen::MatrixXd::Identity(dimension,dimension);
	H = _H;
	dx = _dx;
	dg = _dg;
	double rho;


	rho = 1.0 / (dg.transpose()*dx);
	if (rho <= 0.0) { return H; }
	H_updated = (eye - (rho*(dx*dg.transpose()))) * H * (eye - rho*(dg*dx.transpose())) + rho*(dx*dx.transpose());
	return H_updated;
}
#endif