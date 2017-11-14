#! /usr/bin/ruby -w

def Simpson(x_start, x_end, div_cnt, func)
    if((div_cnt.class != Integer) || (div_cnt <= 0))
        raise "div_cnt should be an integer more than 0!"
    end
    x_step = 1.0 * (x_end - x_start) / div_cnt;
    div_start = x_start;
    func_start = send(func, x_start);
    sum = 0.0;
    div_cnt.times {|i|
        func_mid = send(func, div_start + x_step / 2.0);
        func_end = send(func, div_start + x_step);
        sum += x_step * (func_start + 4 * func_mid + func_end) / 6.0;
        func_start = func_end;
        div_start += x_step;
    }
    return sum;
end

# test for Simpson
=begin
def linear_x(x)
    x;
end

require 'test/unit'
class Test_integration < Test::Unit::TestCase
    def test_Simpson
        sum = Simpson(0, 1, 10, :linear_x);
        assert_in_delta(0.5, sum, 1e-8, "Simpson integration error!");
        print("Simpson integration = #{sum}\n");
        print("Error = #{sum - 0.5}\n");
    end
end
=end
