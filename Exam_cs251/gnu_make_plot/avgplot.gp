#!/usr/bin/gnuplot
set datafile separator " "
set autoscale
plot"<(sed -n '1,5p' avgfile)"using 3:1 w lines
plot"<(sed -n '6,10p' avgfile)"using 3:1 w lines
plot"<(sed -n '11,15p' avgfile)"using 3:1 w lines
pause -1
