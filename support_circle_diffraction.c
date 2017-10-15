// modified from support_circle_diffraction.c
// Calculate the diffraction after a round aperture, a second mirror,
// and mirror support

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI	3.14159265358979323846
// light wavelength
const double WaveLength	= 0.55e-3;   // green light at 0.55um, count as mm
// the diameter of the main mirror
const double D = 80.0;   // mm
// the diameter of the second mirror
const double D2 = 24.0;  // mm
// the width of the support
const double W = 6.4;    // mm
// division number
const int N = 100;

int main(void)
{
	FILE *fp_csv;	//CSV file
	
	// step of diffraction angle, count as arc-second
	const double Theta_step = 0.05 * (2 * PI) / (360 * 3600);
	// step of lens sub-area
	const double Len_step = D / N;
	// total points in the full round
	const double point_cnt = N * N * PI / 4;
	
	int i, j;
	double a_s, a_c;
	double theta_cnt, sin_theta;	//cal for the angle value
	double x, y;	//point pos in the mirror
	double d;		//used to cal the distance from the current point to the zero-phase plane
	double light_intensity;
	
	printf("Circle + support diffraction\n");
	
	if((fp_csv = fopen("support_diffraction.csv", "w")) == NULL) {
		printf("File support_diffraction.csv open failed!\n");
		exit(1);
	}
	
	// angle are signed as (i, j) * Theta_step
	for(i = 0; i <= 150; i ++) {
		for(j = 0; j <= 150; j ++) {
        	// the amplitudes of sin(wt) & cos(wt)
        	a_s = 0.0;
        	a_c = 0.0;
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
			light_intensity = sqrt(a_s * a_s + a_c * a_c);
        	fprintf(fp_csv, "%1.15f,", light_intensity / point_cnt);
		}
		fprintf(fp_csv, "\n");
	}

	fclose(fp_csv);
	return 0;
}


