unset key
set grid
set view equal xyz
set xlabel "x"
set ylabel "y"
set zlabel "z"
splot "pointcloud.txt" every 3:3 with dots
