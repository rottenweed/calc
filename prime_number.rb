#! /usr/bin/ruby -w

# Calculate prime numbers < n
BEGIN {
    print("Prime numbers limit: ");
    n = gets().to_i;
    raise "limit cannot be less than 2!" if n < 2;
    CSV = File.open("prime_number.csv", "w");
}

# initiate the list of prime number
prime_number = [2];

2.upto(n) {|i|
    not_prime_number = false;
    prime_number.each {|j|  # sift by the known prime number
        if(j * j > i)
            break;
        elsif((i % j) == 0)
            not_prime_number = true;
            break;
        end
    }
    if(!not_prime_number)
        if(i > 2)
            prime_number << i;  # add the current number to list
        end
        CSV.print("#{i}, #{prime_number.size}\n");
    end
}

END {
    CSV.close();
}
