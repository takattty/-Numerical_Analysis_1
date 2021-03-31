set terminal postscript enhanced color
set output "work13-2.ps"
set xlabel "x"
set ylabel "z"
plot "work13-2.d" u 1:2 w l, "work13-2.d" u 1:2 w p ps 2 pt 7
set output