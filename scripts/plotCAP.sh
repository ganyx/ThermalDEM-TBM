set title "CapDEM"
set xlabel "Shear deformation"
set ylabel "Stress"
set xrange [0:500]
#set yrange [-0.01:0.01]
set grid

plot "data/CAP/ahistory" every 2::2 using 1:(-1*$4) title "normal stress" w p,\
"data/CAP/ahistory" every 2::2 using 1:5 title "shear stress" w p,\
"data/CAP/ahistory" every 2::2 using 1:($9*0.0001) title "water potential" w p
