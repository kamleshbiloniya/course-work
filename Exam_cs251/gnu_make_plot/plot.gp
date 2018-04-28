#!/usr/bin/gnuplot
set datafile separator " "
set autoscale
plot 'file.txt' using 1:6
pause -1
