#pragma once

// ✦ . ──────────────────────────────── .✦
// Librerias de Sistema
    #include <memory>
// ✦ . ──────────────────────────────── .✦
// Librerias solo cabeceras
    #include "glad/glad.h"

namespace Trinity::Components {

    struct MeshResource {

        GLuint VAO = 0;
        GLuint VBO = 0;
        GLuint EBO = 0;

        GLsizei indexCount = 0;

        // Destructor para limpiar los recursos de la VRAM en GPU
        ~MeshResource() {
            glDeleteBuffers(1, &VBO);
            glDeleteBuffers(1, &EBO);
            glDeleteVertexArrays(1, &VAO);
        }

    };

    struct MeshComponent {
        std::shared_ptr<MeshResource> mesh;
    };

}

