#! /usr/bin/ruby -w

# Parameters
N = 10000;          # count of samples
RATIO = 1.1;        # population increasing in a generation
MAX_LIMIT = 4.0;    # the max ratio of population
GEN = 400;          # count of generation
MAX_COUNT = 10;     # super ancient sample count

print("Extinction between generation.\n");

sample = Array.new(N) {|i| i;};
sum = N;
sum_last = N;
count = Array.new(N, 0);
survive = 0;        # survived count of initial person
ratio_10 = 0.0;     # percent of the top 10
record_file = File.open("extinct.csv", "w");

# random born between generation
GEN.times { |gen|
    sum = (sum_last * RATIO).to_i;  # population increase
    # population decrease to initial value when > the population limit
    sum = N if((sum > N * MAX_LIMIT) || (gen == GEN - 1));
    sample_next = Array.new(sum, 0);
    survive = 0;
    N.times {|i|
        count[i] = 0;
    }
    sum.times {|i|
        pos = (rand() * sum_last).to_i;
        sample_next[i] = sample[pos];
    }
    sum.times {|i|
        count[sample_next[i]] += 1;
    }
    N.times {|i|
        survive += 1 if(count[i] > 0);
    }
    sample = sample_next;
    sum_last = sum;
    # record the data in every generation
    ratio_10 = (count.sort)[N - MAX_COUNT, MAX_COUNT].sum * 100.0 / sum;
    record_file.print("#{gen},#{sum},#{survive},#{ratio_10}\n");
}

record_file.close;
print("total = #{sum}, survive = #{survive}\n");
printf("sum of top 10: %.2f\%\n", ratio_10);
print((count.sort)[N - MAX_COUNT, MAX_COUNT], "\n");

