import Metashape

# Configuração inicial
doc = Metashape.app.document
chunk = doc.chunk
output_file = "caminho_para_salvar/nuvem_classificada.txt"

# Abrir o arquivo de saída
with open(output_file, "w") as file:
    # Escrever o cabeçalho, se necessário
    file.write("ID;X;Y;Z;Classificação\n")
    
    # Iterar pelos pontos da nuvem
    for point in chunk.point_cloud.points:
        if point.valid:  # Verifica se o ponto é válido
            coord = point.coord  # Coordenadas X, Y, Z
            classification = point.classification  # Classificação do ponto
            # Formatação e escrita no arquivo
            line = f"{point.id};{coord.x:.3f};{coord.y:.3f};{coord.z:.3f};{classification}\n"
            file.write(line)
