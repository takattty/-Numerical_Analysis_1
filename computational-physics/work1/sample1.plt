set terminal postscript enhanced color
set output "sample1.ps"
plot "sample1-2.d" u 1:2 w l,\
"sample1-2.d" u 1:3 w l,\
"sample1-4.d" u 1:2 w l,\
"sample1-4.d" u 1:3 w l,\
"sample1-6.d" u 1:2 w l,\
"sample1-6.d" u 1:3 w l,\
"sample1-8.d" u 1:2 w l,\
"sample1-8.d" u 1:3 w l,\
"sample1-10.d" u 1:2 w l,\
"sample1-10.d" u 1:3 w l
set output