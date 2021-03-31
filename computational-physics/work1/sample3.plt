set terminal postscript enhanced color
set output "sample3.ps"
plot "sample3-2.d" u 1:2 w l,\
"sample3-2.d" u 1:3 w l,\
"sample3-4.d" u 1:2 w l,\
"sample3-4.d" u 1:3 w l,\
"sample3-6.d" u 1:2 w l,\
"sample3-6.d" u 1:3 w l,\
"sample3-8.d" u 1:2 w l,\
"sample3-8.d" u 1:3 w l,\
"sample3-10.d" u 1:2 w l,\
"sample3-10.d" u 1:3 w l
set output