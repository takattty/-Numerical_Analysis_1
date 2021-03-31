set terminal postscript enhanced color
set output "work13-3.ps"
set xlabel "x"
set ylabel "z"
plot "work13-2.d" u 1:2 w l, "work13-2.d" u 1:2 w p ps 2 pt 7
replot "work13-1-1.d" u 1:2 w l, "work13-1-1.d" u 1:2 w p ps 2 pt 7
replot -((9.80665/2500)*(x*x)) + x
set output