# simple plot script for position of particles
unset label
set terminal aqua font "Arial, 12"
set multiplot layout 1,3
#set xlabel "X"
#set ylabel "Y"
set size ratio 2 
set xrange [-3:3]
set yrange [-6:6]
set style circle radius 0.1 
#set key at -4,6  box  
set key off 
set grid

set palette rgb 33, 13, 10
set cbrange [500:600]

set title "t=5"
plot "data/TBM/pos_5" using 1:2:(0.9*$10):14 with circles title 'initial' lc palette lw 2
set title "t=10"
plot "data/TBM/pos_10" using 1:2:(0.9*$10):14 with circles title 'initial' lc palette lw 2
set title "t=20"
plot "data/TBM/pos_20" using 1:2:(0.9*$10):14 with circles title 'initial' lc palette lw 2
