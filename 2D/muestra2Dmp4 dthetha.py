import numpy as np
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import matplotlib.animation as animation

# Read the file and split by double newlines to get data for each time step
with open('Data.txt', 'r') as file:
    data_blocks = file.read().strip().split('\n\n')

# Create the figure and axes
fig, ax = plt.subplots(figsize=(10, 6))

# Define the color map from blue to red
cmap = mcolors.LinearSegmentedColormap.from_list("", [  
    "blue", "blue", "blue", "royalblue", "cyan",  
    "chartreuse", "yellow", "orange", "orangered", "red", "red", "firebrick", 
    "darkred",
])

# Adjust labels and legend
ax.set_xlabel('Posición en el eje x')
ax.set_ylabel('Posición en el eje y')
ax.set_title('Cambio a lo largo del tiempo')

# Initialize the visualization with the first block of data
data = np.loadtxt(data_blocks[0].split('\n'))
im = ax.imshow(data, cmap=cmap, vmin=-np.pi, vmax=np.pi)
plt.colorbar(im, ax=ax)  # Show the color bar

def update_frame(i):
    data = np.loadtxt(data_blocks[i].split('\n'))
    im.set_data(data)
    ax.set_title(f'Tiempo {i+1}')
    return im,

# Create the animation
ani = animation.FuncAnimation(fig, update_frame, frames=len(data_blocks), blit=True)

# Save the animation as an MP4 file
ani.save('datapromedio_animationdtheta.mp4', writer='ffmpeg', fps=10)

# Close the plot to avoid displaying it
plt.close()
