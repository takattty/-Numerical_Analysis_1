set terminal postscript enhanced color
set output "sample4.ps"
plot "sample4-2.d" u 1:2 w l,\
"sample4-2.d" u 1:3 w l,\
"sample4-4.d" u 1:2 w l,\
"sample4-4.d" u 1:3 w l,\
"sample4-6.d" u 1:2 w l,\
"sample4-6.d" u 1:3 w l,\
"sample4-8.d" u 1:2 w l,\
"sample4-8.d" u 1:3 w l,\
"sample4-10.d" u 1:2 w l,\
"sample4-10.d" u 1:3 w l
set output