set terminal postscript enhanced color
set output "work7-2.ps"
set xlabel "Number of divisions"
set ylabel "Relative error"
set logscale
plot "work7-1.dat" u 1:2 w l, "work7-1.dat" u 1:2 w p ps 2 pt 7
replot "work7-1.dat" u 1:3 w l, "work7-1.dat" u 1:3 w p ps 2 pt 7
replot "work7-1.dat" u 1:4 w l, "work7-1.dat" u 1:4 w p ps 2 pt 7
set output
set terminal x11