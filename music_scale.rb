#! /usr/bin/ruby -w

print("Calculate musical scale\n");

SCALE_CNT = 12;
LN2 = Math.log(2);
average12 = Array.new(12, 1.0);
step5 = Array.new(12, 1.0);
pure7 = Array.new(12, 1.0);

# generate 12-scale average
SCALE_CNT.times {|i|
    average12[i] = Math.exp(i * LN2 / 12);
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
    printf("%2d: %1.7f, ", i, average12[i]);
    printf("%6.1f, ", 1200.0 * Math.log(average12[i]) / LN2);
    printf("%1.7f, ", step5[i]);
    if(step5[i] != 1.0)
        printf("%6.1f, ", 1200.0 * Math.log(step5[i]) / LN2);
    else
        print(" " * 6, ", ");
    end
    printf("%1.7f", pure7[i]);
    if(pure7[i] != 1.0)
        printf("%6.1f, ", 1200.0 * Math.log(pure7[i]) / LN2);
    else
        print(" " * 6, ", ");
    end
    print("\n");
}
