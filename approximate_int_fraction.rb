#! /usr/bin/ruby -w

print("Calculate a approximate integer/integer fraction.\n");
print("Input decimal: ");
decimal = gets().chop!.to_f;
print("Maximum denominator: ");
max_denominator = gets().chop!.to_i;

delta_best = 1.0;
numerator_best = 0;
denominator_best = 0;
1.upto(max_denominator) {|denominator|
    product = denominator * decimal;
    numerator = (product + 0.5).to_i;
    delta = numerator.to_f / denominator - decimal;
    if((numerator - product).abs < 0.1)
        print("#{numerator} / #{denominator} = ", numerator.to_f / denominator, ", delta = ", delta, "\n");
    end
    if(delta.abs < delta_best)
        delta_best = delta.abs;
        numerator_best = numerator;
        denominator_best = denominator;
    end
}
print("Best faction: #{numerator_best} / #{denominator_best} = #{numerator_best.to_f / denominator_best}\n");
print("delta = #{delta_best}\n");

