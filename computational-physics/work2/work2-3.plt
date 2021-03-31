set terminal postscript enhanced color
set output "sample2-3.ps"
set logscale x
set logscale y
plot "work2-3.d" u 1:5 w l,\
"work2-3.d" u 1:6 w l
set output