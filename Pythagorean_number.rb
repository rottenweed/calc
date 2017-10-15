#! /usr/bin/ruby -w
# Generate Pythagorean numbers < n

print("Input the number of c (a<b<c): ");
str = gets();
n = str.chomp!.to_i;
raise("Input a too little value of c!") if(n < 5);

cnt = 0;
5.upto(n) {|c|
    cnt_c = 0;
    1.upto(n) {|a|
        b = Math.sqrt(c * c - a * a);
        break if a > b;
        if(b.to_i == b) # integer
            cnt += 1;
            cnt_c += 1;
            print("#{cnt}, #{cnt_c}, #{a}, #{b.to_i}, #{c}\n");
        end
    }
}
