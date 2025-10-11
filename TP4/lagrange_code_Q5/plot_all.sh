#!/bin/bash
gnuplot -persist <<-EOF
    reset
    set title "Zoom sur la zone centrale des interpolations de Lagrange" font "Helvetica,16"
    set xlabel "x" font "Helvetica,14"
    set ylabel "y" font "Helvetica,14"

    # Adjust zoom area here:
    set xrange [-1:1]
    set yrange [-1:2]        # You can tweak this to [-0.5:1.5] or similar if needed

    set key outside top center font "Helvetica,10" box
    unset grid
    set border lw 1.5
    set tics font "Helvetica,10"

    set style line 1 lc rgb "#E41A1C" lt 1 lw 3 pt 7  ps 1.2
    set style line 2 lc rgb "#377EB8" lt 2 lw 3 pt 5  ps 1.2
    set style line 3 lc rgb "#4DAF4A" lt 3 lw 3 pt 9  ps 1.2
    set style line 4 lc rgb "#FF7F00" lt 4 lw 3 pt 11 ps 1.2

    set terminal qt size 900,600

    plot \
        "data_tchebychef_m4.txt"  using 1:2 with linespoints ls 1 title "m = 4", \
        "data_tchebychef_m8.txt"  using 1:2 with linespoints ls 2 title "m = 8", \
        "data_tchebychef_m12.txt" using 1:2 with linespoints ls 3 title "m = 12", \
        "data_tchebychef_m20.txt" using 1:2 with linespoints ls 4 title "m = 20",\
         "data_original.txt" using 1:2 with lines lw 2 lc rgb "#4C00B0" title "f(x) = 1/(1+25x^2)"
EOF

