#! /usr/bin/ruby -w

print("Cal CRC function.\n");
crc_code = 0x8005;
crc_len = 16;
crc_bit_cnt = 8;

crc_msb = 1 << crc_len;
crc_mask = crc_msb - 1;
crc_bit_result = Array.new(crc_len, 0);

crc_len.times {|i|
    crc_value = 1 << i;
    crc_bit_cnt.times {|j|
        crc_value <<= 1;
        if((crc_value & crc_msb) == crc_msb)
            crc_value ^= crc_code;
        end
        crc_value &= crc_mask;
    }
    crc_bit_result[i] = crc_value;
}

crc_bit_result.each {|i|
    printf("%04x\n", i);
}

print("Corresponding bits as:\n");
(crc_len - 1).downto(0) {|i|
    printf("bit[%d]: ", i);
    (crc_len - 1).downto(0) {|j|
        if(crc_bit_result[j] & (1 << i) == (1 << i))
            printf("%d, ", j);
        end
    }
    print("\n");
}

