# calc
Some sources for calcualtion
用于计算的一些Ruby小程序的集合

Pythagorean_number.rb
  计算勾股数三元组。
  
prime_number.rb
  用筛法计算质数。
  
rand_pi.rb
  用蒙特卡洛法取随机点计算圆周率。
  
s2x.rb
  Ruby的字符串-十六进制-二进制转换。
  
gauss.rb
  高斯概率分布函数。

csv_dup4.rb
  在CSV格式下，将以下的1/4象限的衍射计算的结果对称复制到全部4个象限。

square_diffraction.rb
  平行光的正方形光阑衍射计算。
  
round_diffraction.rb
  平行光的圆孔衍射计算。
  
circle_diffraction.rb
  有中央副镜遮挡的情况下的平行光的圆孔衍射计算。
  
support_circle_diffraction.rb
  有中央副镜和十字支架遮挡的情况下，平行光的圆孔衍射计算。
  
support_circle_diffraction.c
  （C版本）有中央副镜和十字支架遮挡的情况下，平行光的圆孔衍射计算。
  
calc_lib.c
calc_lib.h
  单点计算的C函数库，用于有中央副镜和十字支架遮挡的情况下，平行光的圆孔衍射计算。
  
calc_lib.bat
  Windows下使用gcc编译产生DLL文件。
  
c_support_circle_diffraction.rb
  使用ffi gem调用C函数动态链接库，实现有中央副镜和十字支架遮挡的情况下，平行光的圆孔衍射计算。
  使用相对目录和Windows路径的兼容处理。
  用时约为纯ruby版本的1/10（Ruby 2.4.2）。
