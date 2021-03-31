set terminal postscript enhanced color
set polar
set output "work14-1.ps"
plot "work14-1.d" using 2:1 with lines
set output