set terminal gif animate delay 50
set output 'plotAnim.gif'
#set termoption dashed
set size ratio 1 
set xrange [-7:7]
set yrange [-7:7]
set style circle radius 0.1 
set key off 
set grid
set palette rgb 33, 13, 10
set cbrange [-3:3]

do for [i=3:99]{
set multiplot layout 1,2
set title 'Horizontal'
plot 'data/VIBRATION/pos_'.i using 1:2:(0.95*$10):5 with circles title 'initial' lc palette lw 2
set title 'Vertical'
plot 'data/VIBRATION/pos_'.i using 1:3:(0.95*$10):5 with circles title 'initial' lc palette lw 2, \
	'cicles' using 1:2:3 with circle lt 2 lw 1 
}
