# simple plot script for position of particles
unset label
set terminal aqua font "Arial, 12"
set multiplot layout 3,3
#set xlabel "X"
#set ylabel "Y"
set size ratio 1 
set xrange [-7:7]
set yrange [-7:7]
set style circle radius 0.1 
#set key at -4,6  box  
set key off 
set grid

set palette rgb 33, 13, 10
set cbrange [-0.01:0.01]

plot "data/2500/pos_1" using 1:3:(0.9*$10):4 with circles title 'initial' lc palette lw 2
plot "data/2500/pos_2" using 1:3:(0.9*$10):4 with circles title 'initial' lc palette lw 2
plot "data/2500/pos_3" using 1:3:(0.9*$10):4 with circles title 'initial' lc palette lw 2
plot "data/2500/pos_4" using 1:3:(0.9*$10):4 with circles title 'initial' lc palette lw 2
plot "data/2500/pos_5" using 1:3:(0.9*$10):4 with circles title 'initial' lc palette lw 2
plot "data/2500/pos_6" using 1:3:(0.9*$10):4 with circles title 'initial' lc palette lw 2
plot "data/2500/pos_7" using 1:3:(0.9*$10):4 with circles title 'initial' lc palette lw 2
plot "data/2500/pos_8" using 1:3:(0.9*$10):4 with circles title 'initial' lc palette lw 2
plot "data/2500/pos_11" using 1:3:(0.9*$10):4 with circles title 'initial' lc palette lw 2
