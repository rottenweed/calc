#! /usr/bin/ruby -w
# Read the csv file of diffraction value to BMP file.

require 'csv'
require '.\bmp.rb'

bmpFile = BMP.new(301, 301, 'diffraction.bmp');

i = 0;
CSV.foreach("square_diffraction.csv") {|row|
    j = 0;
    row.each {|col|
        if(j <= 150)
            light = (col.to_f * 256.0 / 1.298832).to_i;
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

