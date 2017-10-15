#! /usr/bin/ruby -w

def put_bit(val)
    8.times {|i|
        print(val & 1);
        val /= 2;
    }
end

a = String.new("1ffffe");
i = a.hex;
puts(i);
h1 = i / 0x10000;
h2 = (i % 0x10000) / 0x100;
h3 = i % 0x100;
printf("%x %x %x\n", h1, h2, h3);
put_bit(h1);

