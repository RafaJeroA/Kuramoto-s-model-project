import matplotlib.pyplot as plt

def plot_correlation_from_file(file_path):
    # Leer los valores del archivo
    with open(file_path, 'r') as file:
        lines = file.readlines()

    # Dividir los datos en segmentos basados en los dobles saltos de línea
    segments = []
    current_segment = []
    for line in lines:
        if line.strip():  # Si la línea no está vacía
            current_segment.append(float(line.strip()))
        elif current_segment:  # Si hay un doble salto de línea y hay datos en el segmento actual
            segments.append(current_segment)
            current_segment = []

    # Si hay datos en el último segmento, agrégalo también
    if current_segment:
        segments.append(current_segment)

    # Graficar cada segmento por separado
    for segment_idx, segment_data in enumerate(segments, start=1):
        times = range(len(segment_data))
        plt.plot(times, segment_data, marker='o', linestyle='-', markersize=1, label=f'K {((segment_idx-1)*2+0) }')

    plt.xlabel('Tiempo')
    plt.ylabel('Coeficiente de correlación')
    plt.title('Gráfico de Coeficiente de Correlación en función del Tiempo')
    plt.grid(True)
    plt.legend()
    plt.show()

# Llamar a la función para trazar la gráfica a partir de los valores del archivo
plot_correlation_from_file('1D\Data1.txt') 
