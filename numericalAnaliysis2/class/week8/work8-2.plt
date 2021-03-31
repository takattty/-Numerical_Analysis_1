set terminal postscript enhanced color
set output "work8-2.ps"
set xlabel "step"
set ylabel "error"
plot "work8-2.d" u 1:2 w l, "work8-2.d" u 1:2 w p ps 2 pt 7
set logscale
set output