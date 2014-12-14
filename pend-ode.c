/*
 * The function provides the RHS of the following system of two
 * first order differential equations, which describe
 * the motion of a rigid inverted pendulum, stabilized by
 * vibration of the base. 
 *
 */

#include <math.h>

#include </usr/include/gsl/gsl_errno.h>
#include </usr/include/gsl/gsl_odeiv2.h>

int
func (double t, const double y[], double f[], void *params)
{
    /*
     * y[0] - phi
     */
    double omega = *(double *) params;

    f[0] = y[1];
    f[1] = -(1. - .01 * omega * omega * sin (omega * t)) * sin (y[0]);

    return GSL_SUCCESS;
}
