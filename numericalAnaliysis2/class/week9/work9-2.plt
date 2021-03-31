set terminal postscript enhanced color
set output "work9-2.ps"
set xlabel "step"
set ylabel "error"
plot "work9-2.d" u 1:2 w l, "work9-2.d" u 1:2 w p ps 2 pt 7
replot "work8-2.d"  u 1:2 w l, "work8-2.d" u 1:2 w p ps 2 pt 7
set logscale
set output