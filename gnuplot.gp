set term png size 1900,1000 enhanced font "Terminal,20"

set title "Execution en milliseconds en fonction du damping factor"

set key left top
set style line 1 linewidth 3

set xlabel "Damping factor"
set ylabel "Temps (ms)"

plot ARG1 using 2:1 t "Time" linestyle 1 with linespoints
