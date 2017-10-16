#! /usr/bin/ruby -w
# Calculate the diffraction after a round aperture, a second mirror,
# and mirror support

# use c function
require('ffi');

module OpticsLib
    extend(FFI::Library);
    $CurPath = Dir.pwd;
    $CurPath += File::SEPARATOR;
    $CurPath.gsub!(File::SEPARATOR, File::ALT_SEPARATOR) if(File::ALT_SEPARATOR != nil);
    $DllName = $CurPath + 'calc_lib.dll';
    ffi_lib($DllName);
    attach_function(:cal_light_intensity, [:int, :int, :double, :double,
        :double, :double, :double, :double], :double);
end

print("Circle + support diffraction\n");

# light wavelength
WaveLength = 0.55e-3;   # green light, 0.55um
# the diameter of the main mirror
D = 80.0;   # mm
# the diameter of the second mirror
D2 = 24.0;  # mm
# the width of the support
W = 6.4;    # mm
# step of diffraction angle, count as arc-second
Theta_step = 0.05 * (2 * Math::PI) / (360 * 3600);
# step of lens sub-area
Len_step = D / 100.0;
CSV = File.open("support_diffraction.csv", "w");

#require('benchmark');
#Benchmark.bm do |bm|
#    bm.report("Cal:") do

#require('profile');

# total points in the full round
point_cnt = 10000 * Math::PI / 4;
# angle are signed as (i, j) * Theta_step
150.downto(0) {|i|
    150.downto(0) {|j|
        light_intensity = OpticsLib.cal_light_intensity(i, j, Theta_step, Len_step, D, D2, W, WaveLength);
        CSV.print(light_intensity / point_cnt, ",");
    }
    CSV.print("\n");
}

#    end
#end

CSV.close;

