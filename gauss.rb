#! /usr/bin/ruby -w

# calculate Gauss distribution
# parameter omega

def gauss(x, omega = 1.0)
    Math.exp(- x * x / (2.0 * omega * omega)) / (omega * Math.sqrt(2 * Math::PI));
end

-4.0.step(4.0, 0.1) {|x|
    print("#{x}, #{gauss(x)}\n");
}

