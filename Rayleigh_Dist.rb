#! /usr/bin/ruby -w
# Rayleigh Distribution Calculation
# Mid_number ~ 1.178 * omicron
def r_dis(x, omicron)
    x * Math.exp(-0.5 * x ** 2 / omicron ** 2) / omicron ** 2;
end

def r_dis_avg(omicron)
    Math.sqrt(Math::PI / 2.0) * omicron;
end

# E(x**2) - E(x)**2
def r_dis_dx(omicron)
    (4.0 - Math::PI) / 2.0 * omicron ** 2;
end

=begin
# test for Rayleigh Distribution
def r_dis_1(x)
    r_dis(x, 1.0);
end

require "./integration.rb"
CSV = File.open("r_dis.csv", "w");
0.step(5.0, 0.01) {|x|
    CSV.print("#{x},");
    CSV.print(r_dis_1(x), ",");
    CSV.print(Simpson(0, x, 1000, :r_dis_1), "\n");
}
CSV.print(r_dis_avg(1.0), "\n");
CSV.close;
=end
