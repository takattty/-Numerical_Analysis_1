set terminal postscript enhanced color
set output "work8-1.ps"
set xlabel "t"
set ylabel "u"
plot "work8-1-1.d" u 2:3 w l, "work8-1-1.d" u 2:3 w p ps 2 pt 7
replot "work8-1-2.d" u 2:3 w l, "work8-1-2.d" u 2:3 w p ps 2 pt 7
replot "work8-1-3.d" u 2:3 w l, "work8-1-3.d" u 2:3 w p ps 2 pt 7
replot sin(x)
set output