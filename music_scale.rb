#! /usr/bin/ruby -w

print("Calculate musical scale\n");

SCALE_CNT = 12;
average12 = Array.new(12, 0.0);

SCALE_CNT.times {|i|
    average12[i] = Math.exp(i * Math.log(2) / 12);
}

SCALE_CNT.times {|i|
    printf("%2d: %1.7f\n", i, average12[i]);
}
