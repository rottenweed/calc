#! /usr/bin/ruby -w
# Calculate the diffraction after a round aperture, a second mirror,
# and mirror support

print("Circle + support diffraction\n");

# light wavelength
WaveLength = 0.55e-3;   # green light, 0.55um
# the diameter of the main mirror
D = 80.0;   # mm
# the diameter of the second mirror
D2 = 24.0;  # mm
# the width of the support
W = 6.4;    # mm
# step of diffraction angle, count as arc-second
Theta_step = 0.05 * (2 * Math::PI) / (360 * 3600);
# step of lens sub-area
Len_step = D / 100.0;
CSV = File.open("support_diffraction.csv", "w");

# total points in the full round
point_cnt = 10000 * Math::PI / 4;
# angle are signed as (i, j) * Theta_step
150.downto(0) {|i|
    150.downto(0) {|j|
        # the amplitudes of sin(wt) & cos(wt)
        a_s = 0.0;
        a_c = 0.0;
        theta_cnt = Math.sqrt(i * i + j * j);
        sin_theta = Math.sin(theta_cnt * Theta_step);
        (-0.5 * D).step((0.5 * D), Len_step) {|y|
            (-0.5 * D).step((0.5 * D), Len_step) {|x|
                if((x * x + y * y <= 0.25 * D * D) && (x * x + y * y >= 0.25 * D2 * D2) && (x.abs >= W / 2) &&(y.abs >= W / 2))   # point is in the circle, and out of the supports
                    # distance to cross-line
                    d = (theta_cnt == 0) ? 0.0 : ((i * x + j * y) / theta_cnt);
                    a_s += Math.cos(2 * Math::PI * sin_theta * d / WaveLength);
                    a_c += Math.sin(2 * Math::PI * sin_theta * d / WaveLength);
                end
            }
        }
        light_intensity = Math.sqrt(a_s * a_s + a_c * a_c);
        CSV.print(light_intensity / point_cnt, ",");
    }
    CSV.print("\n");
}

CSV.close;

