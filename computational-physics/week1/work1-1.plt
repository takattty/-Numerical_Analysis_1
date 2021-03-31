set terminal postscript enhanced eps color dashed "Helvetica" 24
set output 'work1-1.eps'
set logscale y
set format y "10^{%L}"
set xlabel "{/Times=40 x}"
set ylabel "{/Times=40 function}"
plot [-1:1][-2:2] "データファイル名_1" u 1:2 notitle w l lw 1.5 lt 1, \
                  "データファイル名_1" u 1:3 notitle w l lw 1.5 lt 2, \
                  "データファイル名_2" u 1:2 notitle w l lw 3   lt 3