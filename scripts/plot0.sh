# simple plot script for position of particles
unset label
set terminal aqua font "Arial, 20"
set title "Position X-Y"
set xlabel "X"
set ylabel "Y"
set size ratio 2 
set xrange [-3:3]
set yrange [-6:6]
set style circle radius 0.1 
set key at -4,6  box  
set grid

plot "data/2500/pos_11" using 1:2:(0.2*$10) with circles title 'initial' ,\
"data/test/pos_11" using 1:2 title 'final' 
