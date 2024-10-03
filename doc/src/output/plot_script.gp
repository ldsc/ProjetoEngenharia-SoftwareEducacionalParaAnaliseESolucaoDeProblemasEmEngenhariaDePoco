set title 'Profundidade vs Densidade'
set xlabel 'Profundidade'
set ylabel 'Densidade'
plot 'dados.txt' using 1:2 with linespoints title 'Densidade vs Profundidade'
pause -1
