set title 'Profundidade vs Densidade'
set xlabel 'ESD, lbm/gal'
set ylabel 'Depth, ft'
set grid
set style data linespoints
plot 'dados.txt' using 2:1 with lines title 'WBM HP/HT well', \
'' using 2:1 smooth unique with lines title 'SBM HP/HT well', \
'' using 15.0:20.0 with lines title '15.0 lbm/gal at 120F', \
'' using 15.2:18.0 with lines title 'SBM 8000 ft water', \
pause -1
