import matplotlib.pyplot as plt

def plot_correlation_from_file(file_path):
    # Leer los valores del archivo
    with open(file_path, 'r') as file:
        column_values = [float(line.strip()) for line in file]

    # Extraer los tiempos y los coeficientes de correlación
    times = range(len(column_values))
    correlations = column_values

    # Graficar los coeficientes de correlación en función del tiempo
    plt.plot(times, correlations, marker='o', linestyle='-', markersize=1)
    plt.xlabel('Tiempo')
    plt.ylabel('Coeficiente de correlación')
    plt.title('Gráfico de Coeficiente de Correlación en función del Tiempo')
    plt.grid(True)
    plt.show()

# Llamar a la función para trazar la gráfica a partir de los valores del archivo
plot_correlation_from_file('data.txt')
