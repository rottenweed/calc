#! /usr/bin/ruby -w

# duplicate the data in quadrant III to all the 4 quadrants

CSV_in = File.open("support_diffraction.csv", "r");
CSV_out = File.open("full_support_diffraction.csv", "w");

lines = CSV_in.readlines;
lines.size.times {|i|
    item = lines[i].split(/\s*,\s*/);
    item.size.times {|j|
        CSV_out.print(item[j], ",");
    }
    item.size.times {|j|
        CSV_out.print(item[-1 - j], ",");
    }
    CSV_out.print("\n");
}
=begin
lines.size.times {|i|
    item = lines[-1 - i].split(/\s*,\s*/);
    item.size.times {|j|
        CSV_out.print(item[j], ",");
    }
    item.size.times {|j|
        CSV_out.print(item[-1 - j], ",");
    }
    CSV_out.print("\n");
}
=end
CSV_in.close;
CSV_out.close;

