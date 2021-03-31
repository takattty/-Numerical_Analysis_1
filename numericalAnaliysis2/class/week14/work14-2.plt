set terminal postscript enhanced color
set output "work14-2.ps"
set xlabel "t"
set ylabel "x"
plot "work14-2.d" u 1:2 w l, "work14-2.d" u 1:2 w p ps 2 pt 7
replot "work14-2.d" u 1:2 w l, "work14-2.d" u 1:2 w p ps 2 pt 7
set output