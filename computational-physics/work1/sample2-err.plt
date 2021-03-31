set terminal postscript enhanced color
set output "sample2-err.ps"
set logscale y
plot "sample2-2.d" u 1:4 w l,\
"sample2-4.d" u 1:4 w l,\
"sample2-6.d" u 1:4 w l,\
"sample2-8.d" u 1:4 w l,\
"sample2-10.d" u 1:4 w l
set output