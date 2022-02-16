#!/bin/bash

rm data/clock*
rm plot/plot*
# Makefile
make
# Run pageRank
./pageRank
# Plot courbe
FILES="clock_*"
cd ./data
for f in $(ls clock_*)
do
  gnuplot -c ../script/gnuplot.gp $f > ../plot/plot_${f%.*}.png
  eog ../plot/plot_${f%.*}.png
done
cd ..
