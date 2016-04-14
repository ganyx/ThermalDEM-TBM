# simple plot script for position of particles
unset label
set terminal aqua font "Arial, 12"
set multiplot layout 2,3
#set xlabel "X"
#set ylabel "Y"
set size ratio 1 
set xrange [-8:8]
set yrange [-8:8]
set style circle radius 0.1 
#set key at -4,6  box  
set key off 
set grid

set palette rgb 33, 13, 10
set cbrange [-0.1:0.1]

plot "data/VIBRATION/pos_18" using 1:2:(0.9*$10):5 with circles title 'initial' lc palette lw 2
plot "data/VIBRATION/pos_19" using 1:2:(0.9*$10):5 with circles title 'initial' lc palette lw 2
plot "data/VIBRATION/pos_20" using 1:2:(0.9*$10):5 with circles title 'initial' lc palette lw 2
plot "data/VIBRATION/pos_18" using 1:3:(0.9*$10):5 with circles title 'initial' lc palette lw 2
plot "data/VIBRATION/pos_19" using 1:3:(0.9*$10):5 with circles title 'initial' lc palette lw 2
plot "data/VIBRATION/pos_20" using 1:3:(0.9*$10):5 with circles title 'initial' lc palette lw 2
