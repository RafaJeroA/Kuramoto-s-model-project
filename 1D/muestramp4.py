import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib.animation import FFMpegWriter

# Lee el archivo
data = np.loadtxt('1D/Data1.txt')

# Obtiene el número de columnas y filas
num_rows, num_cols = data.shape

# Crea una lista de colores para las líneas
colors = plt.cm.viridis(np.linspace(0, 1, num_rows))

# Crea la figura y los ejes en coordenadas polares
fig, ax = plt.subplots(subplot_kw={'projection': 'polar'}, figsize=(10, 6))

# Ajusta las etiquetas y la leyenda
ax.set_title('Theta angle of each oscillator')

# Configura el scatter inicial (ahora será un conjunto de puntos)
scat = ax.scatter([], [], s=30, facecolors='red', edgecolors='black')#color=colors[0])  # s es el tamaño de los puntos

# Función para inicializar la animación
def init():
    scat.set_offsets(np.empty((0, 2)))  # Establece un array vacío con dos columnas
    return scat,

# Función para actualizar la animación
def update(frame):
    angles = data[frame]  # Los valores del archivo son los ángulos
    radii = np.ones_like(angles)  # Radio fijo de 1
    points = np.column_stack((angles, radii))  # Crea un array de puntos (ángulo, radio)
    scat.set_offsets(points)  # Actualiza la posición de los puntos
    scat.set_label(f'Time {frame}')
    ax.legend()
    return scat,

# Crea la animación
ani = animation.FuncAnimation(fig, update, frames=num_rows, init_func=init, blit=True, repeat=False)

# Define el writer para guardar la animación
writer = FFMpegWriter(fps=30, metadata=dict(artist='Me'), bitrate=1800)

# Guarda la animación como un archivo MP4
ani.save('animacion.mp4', writer=writer)

print ('1')