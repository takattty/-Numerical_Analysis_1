set terminal postscript enhanced color
set output "sample2-2.ps"
set logscale x
set logscale y
plot "work2-2.d" u 1:5 w l,\
"work2-2.d" u 1:6 w l
set output