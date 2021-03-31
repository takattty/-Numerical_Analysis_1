set terminal postscript enhanced color
set output "sample3-err.ps"
set logscale y
plot "sample3-2.d" u 1:4 w l,\
"sample3-4.d" u 1:4 w l,\
"sample3-6.d" u 1:4 w l,\
"sample3-8.d" u 1:4 w l,\
"sample3-10.d" u 1:4 w l
set output