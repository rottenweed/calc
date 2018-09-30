#! /usr/bin/ruby -w

print("Cal CRC parallel function.\n");
CRC_CODE = 0x8005;  #CRC-16: x^16 + x^15 + x^2 + 1
CRC_LEN = 16;
CRC_BIT_CNT = 8;

crc_msb = 1 << CRC_LEN;
crc_mask = crc_msb - 1;
crc_bit_result = Array.new(CRC_LEN, 0);

CRC_LEN.times {|i|
    crc_value = 1 << i;
    CRC_BIT_CNT.times {|j|
        crc_value <<= 1;
        if((crc_value & crc_msb) == crc_msb)
            crc_value ^= CRC_CODE;
        end
        crc_value &= crc_mask;
    }
    crc_bit_result[i] = crc_value;
}
=begin
crc_bit_result.each {|i|
    printf("%04x\n", i);
}
=end
print("Corresponding bits as:\n");
(CRC_LEN - 1).downto(0) {|i|
    printf("bit[%d]: ", i);
    (CRC_LEN - 1).downto(0) {|j|
        if(crc_bit_result[j] & (1 << i) == (1 << i))
            printf("%d, ", j);
        end
    }
    print("\n");
}

