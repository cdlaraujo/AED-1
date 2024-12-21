import Metashape

# Obtenha o chunk ativo
doc = Metashape.app.document
chunk = doc.chunk

if not chunk:
    raise Exception("Nenhum chunk ativo encontrado!")

# Verifique se a nuvem de pontos existe
if not chunk.point_cloud:
    raise Exception("Nenhuma nuvem de pontos encontrada no chunk ativo!")

# Acessar pontos da nuvem
points = chunk.point_cloud.points
print(f"Número de pontos: {len(points)}")

# Exporte para o formato desejado
output_file = "C:/Users/SeuUsuario/Documents/nuvem_classificada.txt"
with open(output_file, "w") as f:
    f.write("ID;X;Y;Z;R;G;B;CLASSIFICATION\n")
    for point in points:
        if point.valid:  # Verifica se o ponto é válido
            coord = point.coord
            classification = point.classification if hasattr(point, "classification") else 0
            f.write(f"{point.index};{coord.x:.3f};{coord.y:.3f};{coord.z:.3f};0;0;0;{classification}\n")

print(f"Nuvem exportada para {output_file}")
