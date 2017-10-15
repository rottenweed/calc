#! /usr/bin/ruby -w

N = 100000
cnt = 0
N.times do |i|
    x, y = rand, rand
    if(x * x + y * y < 1)
        cnt += 1
    end
end
print cnt * 4.0 / N, "\n"
