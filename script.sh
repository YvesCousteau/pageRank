#!/bin/bash

# Makefile
make
# Run pageRank
./pageRank
# Plot courbe
gnuplot -c ./gnuplot.gp clock.txt > plot.png
eog plot.png
