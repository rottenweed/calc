#! /usr/bin/ruby -w

# Parameters
N = 10000;      # count of samples
GEN = 400;      # count of generation
MAX_COUNT = 10; # super ancient sample count

print("Extinction between generation.\n");

sample = Array.new(N) {|i| i;};
sample_next = Array.new(N, 0);
count = Array.new(N, 0);
survive = 0;
# random born between generation
GEN.times {
    survive = 0;
    N.times {|i|
        count[i] = 0;
    }
    N.times {|i|
        pos = (rand() * N).to_i;
        sample_next[i] = sample[pos];
    }
    N.times {|i|
        count[sample_next[i]] += 1;
    }
    N.times {|i|
        survive += 1 if(count[i] > 0);
    }
    N.times {|i|
        sample[i] = sample_next[i];
    }
}

count_sort = count.sort;
print(survive, "\n");
print(count_sort[N - MAX_COUNT, MAX_COUNT], "\n");

