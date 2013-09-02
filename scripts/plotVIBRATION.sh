# simple plot script for position of particles
unset label
set terminal aqua font "Arial, 12"
set multiplot layout 2,4
#set xlabel "X"
#set ylabel "Y"
set size ratio 2 
set xrange [-3:3]
set yrange [-7:7]
set style circle radius 0.1 
#set key at -4,6  box  
set key off 
set grid

set palette rgb 33, 13, 10
set cbrange [-0.1:0.1]

set title "t=20"
plot "data/VIBRATION/pos_43" using 1:2:(0.9*$10):5 with circles title 'initial' lc palette lw 2
set title "t=30"
plot "data/VIBRATION/pos_44" using 1:2:(0.9*$10):5 with circles title 'initial' lc palette lw 2
set title "t=40"
plot "data/VIBRATION/pos_45" using 1:2:(0.9*$10):5 with circles title 'initial' lc palette lw 2
set title "t=50"
plot "data/VIBRATION/pos_46" using 1:2:(0.9*$10):5 with circles title 'initial' lc palette lw 2
set title "t=60"
plot "data/VIBRATION/pos_47" using 1:2:(0.9*$10):5 with circles title 'initial' lc palette lw 2
set title "t=70"
plot "data/VIBRATION/pos_48" using 1:2:(0.9*$10):5 with circles title 'initial' lc palette lw 2
set title "t=80"
plot "data/VIBRATION/pos_49" using 1:2:(0.9*$10):5 with circles title 'initial' lc palette lw 2
set title "t=100"
plot "data/VIBRATION/pos_50" using 1:2:(0.9*$10):5 with circles title 'initial' lc palette lw 2
