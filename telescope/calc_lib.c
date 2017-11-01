#include <math.h>
#include "calc_lib.h"

double cal_light_intensity(int i, int j,
        double Theta_step, double Len_step,
        double D, double D2, double W, double WaveLength)
{
// the amplitudes of sin(wt) & cos(wt)
    double a_s = 0.0;
    double a_c = 0.0;
    double theta_cnt;
    double sin_theta;
    double x, y, d;

    theta_cnt = sqrt(i * i + j * j);
    sin_theta = sin(theta_cnt * Theta_step);
    for(y = -0.5 * D; y <= 0.5 * D; y += Len_step) {
        for(x = -0.5 * D; x <= 0.5 * D; x += Len_step) {
            // point is in the circle, and out of the supports
            if((x * x + y * y <= 0.25 * D * D) && (x * x + y * y >= 0.25 * D2 * D2) && (abs(x) >= W / 2) &&(abs(y) >= W / 2)) {
                // distance to cross-line
                d = (theta_cnt == 0) ? 0.0 : ((i * x + j * y) / theta_cnt);
                a_s += cos(2 * PI * sin_theta * d / WaveLength);
                a_c += sin(2 * PI * sin_theta * d / WaveLength);
			}
        }
	}
    return sqrt(a_s * a_s + a_c * a_c);    //light intensity
}
