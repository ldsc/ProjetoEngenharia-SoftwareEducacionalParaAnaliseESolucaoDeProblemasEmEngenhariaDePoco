set title 'Profundidade vs Densidade'
set xlabel 'Densidade'
set ylabel 'Profundidade'
plot 'dados.txt' using 1:2 with linespoints title 'Densidade vs Profundidade'
pause -1
