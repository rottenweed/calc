#! /usr/bin/ruby -w

print("Calculate musical scale\n");

SCALE_CNT = 12;
average12 = Array.new(12, 1.0);
step5 = Array.new(12, 1.0);
pure7 = Array.new(12, 1.0);

# generate 12-scale average
SCALE_CNT.times {|i|
    average12[i] = Math.exp(i * Math.log(2) / 12);
}
# generate 5-step scale
step5[7] = step5[0] * 1.5;
step5[2] = step5[7] * 1.5 / 2.0;
step5[9] = step5[2] * 1.5;
step5[4] = step5[9] * 1.5 / 2.0;
# generate pure scale
pure7[4] = 5.0 / 4.0;
pure7[7] = 6.0 / 4.0;

SCALE_CNT.times {|i|
    printf("%2d: %1.7f, %1.7f, %1.7f\n", i, average12[i], step5[i], pure7[i]);
}
