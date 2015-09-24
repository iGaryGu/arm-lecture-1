#!/bin/gunplot

set terminal png size 800,600 crop
set output "output.png"
plot "timing.txt" using 1:2 with linespoints
print 'draw finish'
