import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# Load data from the text file
with open('1D/Datapromedio.txt', 'r') as file:
    data = file.read()

# Separate data blocks based on double newlines
data_blocks = data.strip().split('\n\n')

# Colors for plotting
colors = ['red', 'blue', 'green', 'orange', 'purple', 'black']

# Create a single plot for all blocks
plt.figure(figsize=(8, 6))

# Plot each data block
for i, block in enumerate(data_blocks):
    lines = block.strip().split('\n')
    block_data = np.array([list(map(float, line.split())) for line in lines])
    
    x, y = block_data[:, 0], block_data[:, 1]
    x_err = block_data[:, 2]  # Uncertainties from column 2
    y_err = block_data[:, 3]  # Uncertainties from column 3

    # Plot the data points with error bars for the block
    plt.errorbar(x, y, xerr=x_err, yerr=y_err, label=f'K {(i)*2}', color=colors[i % len(colors)], fmt='o', markersize=8, capsize=0.0)

plt.xlabel('(Time (t))')
plt.ylabel('(R)')
plt.title('')
plt.legend()
plt.grid(True)

# Save the plot as a PDF file
plt.savefig('datapromedio_combined_with_uncertainties_python.pdf')

# Show the plot
plt.show()
