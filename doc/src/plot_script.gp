set title 'Profundidade vs Densidade'
set xlabel 'ESD, lbm/gal'
set ylabel 'Depth, ft'
set yrange [20:0] 
set grid
set style data linespoints
plot 'dados.txt' using 2:1 with linespoints title 'Densidade vs Profundidade'
pause -1
