#! /usr/bin/ruby -w
# Calculate the diffraction after a square aperture.

print("Square diffraction\n");

# light wavelength
WaveLength = 0.55e-3;   # green light, 0.55um
# the size of the square
D = 80.0;   # mm
# step of diffraction angle, count as arc-second
Theta_step = 0.05 * (2 * Math::PI) / (360 * 3600);
# step of lens sub-area
Len_step = D / 100.0;
CSV = File.open("square_diffraction.csv", "w");

require('benchmark');
Benchmark.bm do |bm|
    bm.report("Square calc time:") do 

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
                # calc all the points in the square
                # distance to cross-line
                d = (theta_cnt == 0) ? 0.0 : ((i * x + j * y) / theta_cnt);
                a_s += Math.cos(2 * Math::PI * sin_theta * d / WaveLength);
                a_c += Math.sin(2 * Math::PI * sin_theta * d / WaveLength);
            }
        }
        light_intensity = Math.sqrt(a_s * a_s + a_c * a_c);
        CSV.print(light_intensity / point_cnt, ",");
    }
    CSV.print("\n");
}

CSV.close;

    end
end
