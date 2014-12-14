/*
 * The function provides the RHS of the following system of four 
 * first order differential equations, which describe 
 * the motion of a glider
 *
 *   v' = -sin(theta) - v^2 / R
 *   theta' = - cos(theta)/v + v 
 *   x' = v cos(theta)
 *   y' = v sin(theta)
 *
 * Here v is the dimensionless speed of the glider, 
 * theta is the angle that the velocity direction 
 * makes with the horizontal, x and y are
 * dimensionless cartesian coordinates of the glider.
 * 
 */

#include <stdio.h>
#include <math.h>

#include </usr/include/gsl/gsl_errno.h>
#include </usr/include/gsl/gsl_odeiv2.h>

int func (double t, const double y[], double f[], 
	  void *params) 
{
  /*
   * y[0] - phi
   */
  double omega = *(double *) params;

  f[0] = -(1.-.01*omega*omega*sin(omega*t))*sin(y[0]);
  return GSL_SUCCESS;
}

