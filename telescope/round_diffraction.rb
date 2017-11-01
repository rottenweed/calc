#! /usr/bin/ruby -w
# Calculate the diffraction after a round aperture

print("Ideal round diffraction\n");

# light wavelength
WaveLength = 0.55e-3;   # green light, 0.55um
# round diameter
D = 80.0; # mm
# step of diffraction angle, count as arc-second
Theta_step = 0.05 * (2 * Math::PI) / (360 * 3600);
# step of lens sub-area
Len_step = D / 100.0;
CSV = File.open("round_diffraction.csv", "w");

0.upto(150) {|i|
    # total point in the round in calculation
    point_cnt = 0;
    # the amplitudes of sin(wt) & cos(wt)
    a_s = 0.0;
    a_c = 0.0;
    sin_theta = Math.sin(i * Theta_step);
    (-0.5 * D).step((0.5 * D), Len_step) {|y|
        (-0.5 * D).step((0.5 * D), Len_step) {|x|
            if(x * x + y * y <= 0.25 * D * D)   # point is in the round
                point_cnt += 1;
                a_s += Math.cos(2 * Math::PI * sin_theta * y / WaveLength);
                a_c += Math.sin(2 * Math::PI * sin_theta * y / WaveLength);
            end
        }
    }
    light_intensity = Math.sqrt(a_s * a_s + a_c * a_c);
    CSV.print("#{light_intensity / point_cnt}\n");
}

CSV.close;

