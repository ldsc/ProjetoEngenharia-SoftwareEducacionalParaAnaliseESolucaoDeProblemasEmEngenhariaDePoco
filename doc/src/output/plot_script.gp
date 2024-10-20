set title 'Profundidade vs Densidade'
set xlabel 'Densidade, lbm/gal'
set ylabel 'Profundidade, ft'
set yrange [20:0]
set grid
set style data linespoints
plot 'dados.txt' using 2:1 with linespoints title 'Densidade vs Profundidade'
pause -1
