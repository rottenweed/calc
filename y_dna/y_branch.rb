#! /usr/bin/ruby -w

SIZE = 20;
N = 10;
PROB = 0.01;
TIME = 10;

print("Y branch\n");

origin = Array.new(SIZE) {(rand() * 4).to_i};
sample_last = Array.new(N) {Array.new(SIZE, 0)};
N.times {|i|
    SIZE.times {|j|
        sample_last[i][j] = origin[j];
    }
}
sample = Array.new(N) {Array.new(SIZE, 0)};

TIME.times {|gen|
    N.times {|i|
        # select a father from the last generation
        father = (rand() * N).to_i;
        SIZE.times {|pos|
            if(rand() > 1 - PROB)   # exchange on SNP
                print("Generation: #{gen}, SNP: #{pos}\n");
                sample[i][pos] = (rand() * 4).to_i;
            else
                sample[i][pos] = sample_last[father][pos];
            end
        }
    }
    # save the data for the next generation
    N.times {|i|
        SIZE.times {|j|
            sample_last[i][j] = sample[i][j];
        }
    }
}

print(origin, "\n\n");
N.times {|i|
    print(sample_last[i], "\n");
}

