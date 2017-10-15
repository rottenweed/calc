#! /usr/bin/ruby -w
# Calculate the diffraction after a round aperture

print("Ideal round diffraction\n");

# light wavelength
WaveLength = 0.55e-3;   # green light, 0.55um
# the diameter of the main mirror
D = 80.0;  # mm
# the diameter of the second mirror
D2 = 24.0;  # mm
# step of diffraction angle, count as arc-second
Theta_step = 0.05 * (2 * Math::PI) / (360 * 3600);
# step of lens sub-area
Len_step = D / 100.0;
CSV = File.open("circle_diffraction.csv", "w");

# total points in the full round
point_cnt = 10000 * Math::PI / 4;
0.upto(150) {|i|
    # the amplitudes of sin(wt) & cos(wt)
    a_s = 0.0;
    a_c = 0.0;
    sin_theta = Math.sin(i * Theta_step);
    (-0.5 * D).step((0.5 * D), Len_step) {|y|
        (-0.5 * D).step((0.5 * D), Len_step) {|x|
            if((x * x + y * y <= 0.25 * D * D) && (x * x + y * y > 0.25 * D2 * D2))   # point is in the circle 
                a_s += Math.cos(2 * Math::PI * sin_theta * y / WaveLength);
                a_c += Math.sin(2 * Math::PI * sin_theta * y / WaveLength);
            end
        }
    }
    light_intensity = Math.sqrt(a_s * a_s + a_c * a_c);
    CSV.print("#{light_intensity / point_cnt}\n");
}

CSV.close;

