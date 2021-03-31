set terminal postscript enhanced color
set output "work9-1.ps"
set xlabel "t"
set ylabel "u"
plot "work8-1-1.d" u 2:3 w l, "work8-1-1.d" u 2:3 w p ps 2 pt 7
replot "work9-1.d" u 2:3 w l, "work9-1.d" u 2:3 w p ps 2 pt 7
replot sin(x)
set output