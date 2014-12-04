# simple plot script for position of particles
unset label
set terminal aqua font "Arial, 10"

set multiplot layout 3,5
#set title "Position X-Y"
#set xlabel "X"
#set ylabel "Y"
set size ratio 2 
set xrange [-3:3]
set yrange [-6:6]
set style circle radius 0.1 
set key off  
set grid

set palette rgb 33,13,10
set cbrange[-0.001:0.001]

set title
plot "data/CapLand/pos_1" using 1:2:(0.5*$10):5 with circles lc palette
set title
plot "data/CapLand/pos_5" using 1:2:(0.5*$10):5 with circles title 'initial' lc palette
set title
plot "data/CapLand/pos_10" using 1:2:(0.5*$10):5 with circles title 'initial' lc palette
set title
plot "data/CapLand/pos_15" using 1:2:(0.5*$10):5 with circles title 'initial' lc palette
set title
plot "data/CapLand/pos_20" using 1:2:(0.5*$10):5 with circles title 'initial' lc palette
set title
plot "data/CapLand/pos_25" using 1:2:(0.5*$10):5 with circles title 'initial' lc palette
set title
plot "data/CapLand/pos_30" using 1:2:(0.5*$10):5 with circles title 'initial' lc palette
set title
plot "data/CapLand/pos_35" using 1:2:(0.5*$10):5 with circles title 'initial' lc palette
set title
plot "data/CapLand/pos_40" using 1:2:(0.5*$10):5 with circles title 'initial' lc palette
set title
plot "data/CapLand/pos_45" using 1:2:(0.5*$10):5 with circles title 'initial' lc palette
set title
plot "data/CapLand/pos_50" using 1:2:(0.5*$10):5 with circles title 'initial' lc palette
set title
plot "data/CapLand/pos_55" using 1:2:(0.5*$10):5 with circles title 'initial' lc palette
set title
plot "data/CapLand/pos_60" using 1:2:(0.5*$10):5 with circles title 'initial' lc palette
set title
plot "data/CapLand/pos_65" using 1:2:(0.5*$10):5 with circles title 'initial' lc palette
set title
plot "data/CapLand/pos_70" using 1:2:(0.5*$10):5 with circles title 'initial' lc palette
set title
plot "data/CapLand/pos_75" using 1:2:(0.5*$10):5 with circles title 'initial' lc palette
