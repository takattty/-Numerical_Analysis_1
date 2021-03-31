set terminal postscript enhanced color
set output "work14-3.ps"
set xlabel "x"
set ylabel "v"
plot "work14-2.d" u 2:3 w l, "work14-2.d" u 2:3 w p ps 2 pt 7
replot "work14-2.d" u 2:3 w l, "work14-2.d" u 2:3 w p ps 2 pt 7
set output