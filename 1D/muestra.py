import numpy as np
import matplotlib.pyplot as plt

# Lee el archivo
data = np.loadtxt('1D/Data1.txt')

# Obtiene el número de columnas y filas
num_rows, num_cols = data.shape

# Crea una lista de colores para las líneas
colors = plt.cm.viridis(np.linspace(0, 1, num_rows))

# Crea la figura y los ejes
fig, ax = plt.subplots(figsize=(10, 6))

# Ajusta las etiquetas y la leyenda
ax.set_xlabel('Posición en el eje x')
ax.set_ylabel('Valor en el eje y')
ax.set_title('Cambio a lo largo del tiempo')

# Plotea una vez para establecer los límites del gráfico
line, = ax.plot(np.arange(num_cols), data[0], color=colors[0], label=f'Tiempo 1')
ax.grid(True)
plt.pause(0.5)

# Itera sobre cada fila y actualiza el gráfico
for i in range(1, num_rows):
    line.set_ydata(data[i])
    ax.set_ylim(-3.1416, 3.1416)  # Ajusta los límites y
    #ax.set_ylim(np.min(data[i]), np.max(data[i]))
    line.set_label(f'Tiempo {i+1}')
    ax.legend()
    plt.pause(0.01)

# Muestra el gráfico final
plt.show()
