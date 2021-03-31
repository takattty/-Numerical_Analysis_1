set terminal postscript enhanced color
set output "work5-4.ps"
set xlabel "Number of divisions"
set ylabel "Relative error"
set logscale
plot "work5-4.dat" u 2:4 w l, "work5-4.dat" u 2:4 w p ps 2 pt 7
set output
set terminal x11