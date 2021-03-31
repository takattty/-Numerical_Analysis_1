set terminal postscript enhanced color
set output "sample4-err.ps"
set logscale y
plot "sample4-2.d" u 1:4 w l,\
"sample4-4.d" u 1:4 w l,\
"sample4-6.d" u 1:4 w l,\
"sample4-8.d" u 1:4 w l,\
"sample4-10.d" u 1:4 w l
set output