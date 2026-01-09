# Set terminal to PDF
set term pdf enhanced color font "Arial,14"
set output "datapromedio.pdf"

# Set the labels for the axes
set xlabel "(H [A/m])"
set ylabel "(B [mT])"

# Set the range for x and y axes
set xrange [-1:1001]
set yrange [-0:1.01]

# First fit and plot
f(x) = a + b * x

# Plot data from the first block
plot 'Datapromedio.txt' index 0 using 1:2 title "R" with points lc rgb "red" ps 0.5 pt 7, \
     '' index 1 using 1:2 title "Valores núcleo laminado" with points lc rgb "blue" ps 0.5 pt 7

# Define fit function and fit for the first block
fit f(x) 'Datapromedio.txt' index 0 using 1:2 via a, b

# Replot the fit function
replot f(x) title "Ajuste Lineal" with lines linestyle 1 dt 1 lw 3

# Add legend and additional styles
set key left box
set key opaque

# Close the output
set output
