#! /usr/bin/ruby -w
# Create 24-bit BMP file.

class BMP
    attr_reader :width, :height, :fileName, :FileHandle;
    def initialize(width, height, fileName = 'test.bmp')
        @width = width;
        @height = height;
        @fileName = fileName;
        @lineLength = width * 3;
        temp = @lineLength % 4;
        if(temp != 0)
            @lineLength += 4 - temp;
        end
        @pixelMapLength = @lineLength * height;
        @bmpHeader = ['B', 'M', @lineLength * height + 54, 0, 0, 54].pack('aaLS2L');
        @bitMapInfoHeader = [40, @width, @height, 1, 24, 0, @pixelMapLength, 0, 0, 0, 0].pack('L3S2L6');
        # create bmp file
        @FileHandle = File.open(@fileName, "wb");
        # setup a zero bit map
        @pixelMap = Array.new(@pixelMapLength, 0);
    end

    def pixel_write(x, y, b, g, r)
        @pixelMap[x * 3 + y * @lineLength] = b;
        @pixelMap[x * 3 + y * @lineLength + 1] = g;
        @pixelMap[x * 3 + y * @lineLength + 2] = r;
    end

    def close
        @FileHandle.print(@bmpHeader);
        @FileHandle.print(@bitMapInfoHeader);
        @pixelMapLength.times {|i|
            @FileHandle.putc(@pixelMap[i]);
        }
        @FileHandle.close;
    end
end

# test codes
=begin
class BMP
    attr_reader :bmpHeader, :bitMapInfoHeader;
    attr_reader :FileHandle;
end

bmpFile = BMP.new(15, 7, 't1.bmp');
print(bmpFile.bmpHeader.unpack('a2LLL'), "\n");
print(bmpFile.bitMapInfoHeader.unpack('L3S2L6'), "\n");
15.times {|i|
    bmpFile.pixel_write(i, 0, 0xff, 0x00, 0x00);
    bmpFile.pixel_write(i, 1, 0x00, 0xff, 0x00);
    bmpFile.pixel_write(i, 2, 0x00, 0x00, 0xff);
    bmpFile.pixel_write(i, 5, 0xff, 0x00, 0x00);
    bmpFile.pixel_write(i, 6, 0x00, 0xff, 0x00);
}
bmpFile.close;
=end

