# simple plot script for position of particles
unset label
set terminal aqua font "Arial, 20"
set title "Position X-Y"
set xlabel "X"
set ylabel "Y"
set size square
set xrange [-3:3]
set yrange [-8:8]
set style circle radius 0.1 
set grid

plot "data/2500/pos_11" using 1:2:(0.25*$10) with circles title 'initial' ,\
"data/test/pos_11" using 1:2 title 'final' 
