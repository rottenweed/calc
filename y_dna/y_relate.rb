#! /usr/bin/ruby -w
# statistics for the Y-DNA clusters relation

require "../least_squares"

CSV = File.open("23_Y.csv", "r");
CSV_O = File.open("y23_r.csv", "w");

# y name in ISOGG_2018
y_tree = (CSV.readline).split(/,/);
y_tree.each {|item| item.chomp!};
# y SNP names
y_snp = (CSV.readline).split(/,/);
y_snp.each {|item| item.chomp!};
cluster_count = y_tree.size;

y_ratio = Array.new;
cluster_count.times {
    y_ratio << Array.new;
}

# add the Y ratio in the different areas
area_count = 0;
CSV.each {|line|
    area_count += 1;
    # each line is a area
    ratio_in_area = line.split(/,/);
    cluster_count.times {|i|
        y_ratio[i] << ratio_in_area[i].to_f;
    }
}
print("Y branch: #{cluster_count}, Area: #{area_count}\n");

# the first line of the output data, y_tree
CSV_O.print(",,");
y_tree.each {|item|
    CSV_O.print("#{item},");
}
CSV_O.print("\n");
CSV_O.print(",,");
y_snp.each {|item|
    CSV_O.print("#{item},");
}
CSV_O.print("\n");

cluster_count.times {|i|
    CSV_O.print(y_tree[i], ",");
    CSV_O.print(y_snp[i], ",");
    cluster_count.times {|j|
        result = least_squares(y_ratio[i], y_ratio[j]);
        CSV_O.printf("%1.3f,", result[2]);
    }
    CSV_O.print("\n");
}

CSV_O.close;

