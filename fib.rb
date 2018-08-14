#! /usr/bin/ruby -w

print("Calculate Fibonacci sequence.\n");

RATIO1 = (1.0 + Math.sqrt(5.0)) / 2.0;
RATIO2 = (5.0 + Math.sqrt(5.0)) / 10.0;
#RATIO2 = 0.7236068;
a0 = 1;
a1 = 1;
delta_old = 1;
print("\nTest 1:\n");
1.upto(20) {|i|
    temp = a1;
    a1 = a0 + a1;
    a0 = temp;
    delta = a0 - RATIO1 ** i * RATIO2;
    print("#{a0}: #{a0 / (RATIO1 ** i * RATIO2)}, ");
    print("#{delta}: #{delta / delta_old}\n");
    delta_old = delta;
}

RATIO3 = (1.0 - Math.sqrt(5.0)) / 2.0;
#RATIO4 = 0.2763931;
RATIO4 = (5.0 - Math.sqrt(5.0)) / 10.0;
a0 = 1;
a1 = 1;
delta_old = 1;
print("\nTest 2:\n");
1.upto(20) {|i|
    temp = a1;
    a1 = a0 + a1;
    a0 = temp;
    delta = a0 - RATIO1 ** i * RATIO2;
    print("#{a0}: #{a0 / (RATIO1 ** i * RATIO2)}, ");
    print("#{delta}: #{delta / (RATIO3 ** i * RATIO4)}\n");
    delta_old = delta;
}

print("\nEquation:\n");
1.upto(20) {|i|
    print("#{(RATIO1 ** i - RATIO3 ** i) / Math.sqrt(5.0) }\n");
}

