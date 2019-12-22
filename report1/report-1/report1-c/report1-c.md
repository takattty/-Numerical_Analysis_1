# gnuplotのコマンド一覧

```
takatty-2:report1-c takatty$ gnuplot

        G N U P L O T
        Version 5.2 patchlevel 7    last modified 2019-05-29 

        Copyright (C) 1986-1993, 1998, 2004, 2007-2018
        Thomas Williams, Colin Kelley and many others

        gnuplot home:     http://www.gnuplot.info
        faq, bugs, etc:   type "help FAQ"
        immediate help:   type "help"  (plot window: hit 'h')

Terminal type is now 'qt'
gnuplot> set terminal postscript enhanced color

Terminal type is now 'postscript'
Options are 'landscape enhanced defaultplex \
   leveldefault color colortext \
   dashlength 1.0 linewidth 1.0 pointscale 1.0 butt noclip \
   nobackground \
   palfuncparam 2000,0.003 \
   "Helvetica" 14  fontscale 1.0 '
gnuplot> set output "report1-c.ps"
gnuplot> set logscale y
gnuplot> set xlabel "Step No."
gnuplot> set ylabel "|a - b|"
gnuplot> plot "report1-a.d" using 1:3 with lines, "report1-b.d" using 1:3 with lines
gnuplot> replot "report1-a.d" using 1:3 with points pointsize 3 pointtype 7, "report1-b.d" using 1:3 with points pointsize 3 pointtype 7
gnuplot> set output
gnuplot> set terminal x11

Terminal type is now 'unknown'
                      ^
         unknown or ambiguous terminal type; type just 'set terminal' for a list
```