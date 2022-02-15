#!/bin/bash

# Makefile
make
# Run pageRank
./pageRank 0.000001
# Plot courbe
FILES="clock_*"
for f in $(ls clock_*)
do
  gnuplot -c ./gnuplot.gp $f > plot_${f%.*}.png
  eog plot_${f%.*}.png
done
