#!/bin/bash

# Configuración de carpetas
SRC_DIR="./embedded_resources"
DST_DIR="./embedded"

# Crear el directorio destino si no existe
mkdir -p "$DST_DIR"

echo "Embebiendo archivos de $SRC_DIR en $DST_DIR..."

# Iterar sobre todos los archivos en la carpeta origen
for file in "$SRC_DIR"/*; do
    if [ -f "$file" ]; then
        filename=$(basename "$file")
        # Reemplazar caracteres no válidos para C++ (ej: fallbackVertShader.vert -> fallbackVertShader_vert)
        var_name=$(echo "$filename" | sed 's/[^a-zA-Z0-9_]/_/g')
        header_path="$DST_DIR/${var_name}.hpp"

        echo "Procesando: $filename -> ${var_name}.hpp"

        # Crear el header con el formato C++
        cat <<EOF > "$header_path"
#pragma once
#include <cstddef>
#include <cstdint>

namespace Embedded {
    inline const uint8_t ${var_name}[] = {
EOF
        
        # Convierte los bytes a Hex limpiamente sin importar cuántos bytes tenga la última línea
        od -An -v -tx1 "$file" | awk '{for(i=1;i<=NF;i++) printf "0x%s, ", $i; print ""}' >> "$header_path"
        
        # Cerrar el arreglo con el nulo final y la longitud
        cat <<EOF >> "$header_path"
        0x00
    };
    inline const size_t ${var_name}_len = sizeof(${var_name}) - 1;
}
EOF
    fi
done

echo "¡Listo! Archivos generados correctamente en $DST_DIR."