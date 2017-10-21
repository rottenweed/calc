#! /usr/bin/ruby -w
# Read the csv file of diffraction value to BMP file.

require 'csv'
require '.\bmp.rb'

bmpFile = BMP.new(301, 301, 'square.bmp');

i = 0;
CSV.foreach("square_diffraction.csv") {|row|
    j = 0;
    row.each {|col|
        if(j <= 150)
            light = (col.to_f * 255.0 / 1.298832).to_i;
            bmpFile.pixel_write(j, i, light, light, light);
            bmpFile.pixel_write(300 - j, i, light, light, light);
            bmpFile.pixel_write(j, 300 - i, light, light, light);
            bmpFile.pixel_write(300 - j, 300 - i, light, light, light);
        end
        j += 1;
    }
    i += 1;
}
bmpFile.close;

bmpFile = BMP.new(301, 301, 'support.bmp');

i = 0;
CSV.foreach("support_diffraction.csv") {|row|
    j = 0;
    row.each {|col|
        if(j <= 150)
                light = (col.to_f * 255.0 / 0.729312).to_i;
            light = 0xff if(light > 0xff);
            bmpFile.pixel_write(j, i, light, light, light);
            bmpFile.pixel_write(300 - j, i, light, light, light);
            bmpFile.pixel_write(j, 300 - i, light, light, light);
            bmpFile.pixel_write(300 - j, 300 - i, light, light, light);
        end
        j += 1;
    }
    i += 1;
}
bmpFile.close;

