#! /usr/bin/ruby -w
# Linear Regression Analyze with Least Squares Algorithm: y = kx + b

def least_squares(x, y)
    count = [x.size, y.size].min;
    sum_x = 0.0;
    sum_y = 0.0;
    sum_xy = 0.0;   # Sigma(x*y)
    sum_xx = 0.0;   # Sigma(x^2)
    sum_yy = 0.0;   # Sigma(y^2)
    count.times {|i|
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_xx += x[i] * x[i];
        sum_yy += y[i] * y[i];
    }
    k = (count * sum_xy - sum_x * sum_y) / (count * sum_xx - sum_x * sum_x);
    b = (sum_y - k * sum_x) / count;
    r = (sum_xy - sum_x * sum_y / count) / Math.sqrt((sum_xx - sum_x * sum_x / count) * (sum_yy - sum_y * sum_y / count))
    return k, b, r;
end

#print least_squares([1, 2], [4, 5, 6]);
