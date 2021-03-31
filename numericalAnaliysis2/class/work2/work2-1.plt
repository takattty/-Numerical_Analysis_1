set terminal postscript enhanced color
set output "work2-2.ps"
set xlabel "step"
set ylabel "error"
set logscale
plot "work2-1.d" u 1:2 w l, "work2-1.d" u 1:2 w p ps 2 pt 7
replot "work2-1.d" u 1:3 w l, "work2-1.d" u 1:3 w p ps 2 pt 7
set output