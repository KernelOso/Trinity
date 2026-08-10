#pragma once

// ✦ . ──────────────────────────────── .✦
// Librerias de Sistema
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <vector>
    #include <memory>
// ✦ . ──────────────────────────────── .✦
// Librerias solo cabeceras
    #include "glad/glad.h"
    // ✶ ──
    #include "glm/gtc/matrix_transform.hpp"
    #include "glm/gtc/type_ptr.hpp"
// ✦ . ──────────────────────────────── .✦
// Librerias thirdparty
    #include "assimp/Importer.hpp"
    #include "assimp/scene.h"
    #include "assimp/postprocess.h"
// ✦ . ──────────────────────────────── .✦
// ECS
    #include "Trinity/Components/MeshComponent.hpp"
    #include "Trinity/Logger.hpp"

namespace Trinity::ResourceLoaders {

    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 uv;
    };

    inline std::shared_ptr<Trinity::Components::MeshResource> meshLoader (const std::string& meshFilePath) {

        LOG_DEBUG("(Trinity::ResourceLoaders::meshLoader) Cargando la Mesh: \"{}\"...", meshFilePath);

        // ✦ . ──────────────────────────────── .✦
        // ▄▖               ▌  ▗       ▄▖▄▖▄▖▄▖▖  ▖▄▖
        // ▙▌▀▌▛▘▛▘█▌▀▌▛▘  ▛▌▀▌▜▘▛▌▛▘  ▌▌▚ ▚ ▐ ▛▖▞▌▙▌
        // ▌ █▌▌ ▄▌▙▖█▌▌   ▙▌█▌▐▖▙▌▄▌  ▛▌▄▌▄▌▟▖▌▝ ▌▌
        // ✶ ────────────── ✶

        Assimp::Importer importer;

        // Obtener Escena Base del archivo
        const aiScene* scene = importer.ReadFile(
            std::string(RESOURCES_PATH) + meshFilePath,
            aiProcess_Triangulate |
            aiProcess_FlipUVs |
            aiProcess_GenNormals |
            aiProcess_JoinIdenticalVertices
        );

        // Recurso Mesh a cachear
        auto meshResource = std::make_shared<Trinity::Components::MeshResource>();

        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;

        // Verifica la integridad del archivo cargado
        if (!scene || !scene->mRootNode || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || scene->mNumMeshes == 0) {

            LOG_ERROR( "(Trinity::ResourceLoaders::meshLoader) Error al cargar la Mesh: \"{}\" | Excepcion: {}", meshFilePath, importer.GetErrorString() );

            // En caso de error...
            // Cargar modelo placeholder de error
            vertices = {
                // Cara Frontal
                { {-1.0f,  1.0f,  1.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f} },
                { { 1.0f, -1.0f,  1.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f} },
                { {-1.0f, -1.0f,  1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f} },
                { { 1.0f,  1.0f,  1.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f} },

                // Cara Derecha
                { { 1.0f,  1.0f,  1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f} },
                { { 1.0f, -1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f} },
                { { 1.0f, -1.0f,  1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f} },
                { { 1.0f,  1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f} },

                // Cara Izquierda
                { {-1.0f,  1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f} },
                { {-1.0f, -1.0f,  1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f} },
                { {-1.0f, -1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f} },
                { {-1.0f,  1.0f,  1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f} },

                // Cara Trasera
                { { 1.0f,  1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f} },
                { {-1.0f, -1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f} },
                { { 1.0f, -1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f} },
                { {-1.0f,  1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f} },

                // Cara Superior
                { {-1.0f,  1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f} },
                { { 1.0f,  1.0f,  1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f} },
                { {-1.0f,  1.0f,  1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f} },
                { { 1.0f,  1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f} },

                // Cara Inferior
                { {-1.0f, -1.0f,  1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f} },
                { { 1.0f, -1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f} },
                { {-1.0f, -1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f} },
                { { 1.0f, -1.0f,  1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f} },
            };

            indices = {
                // Cara Frontal
                0, 1, 2,
                0, 3, 1,

                // Cara Derecha
                4, 5, 6,
                4, 7, 5,

                // Cara Izquierda
                8, 9, 10,
                8, 11, 9,

                // Cara Trasera
                12, 13, 14,
                12, 15, 13,

                // Cara Superior
                16, 17, 18,
                16, 19, 17,

                // Cara Inferior
                20, 21, 22,
                20, 23, 21
            };

            LOG_WARN("(Trinity::ResourceLoaders::meshLoader) Falla al cargar la Mesh: \"{}\", utilizando Mesh Fallback." , meshFilePath);

        }
        else {

            // Obtener la primera mesh del archivo
            aiMesh* baseMesh = scene->mMeshes[0];

            // ✦ . ──────────────────────────────── .✦
            // Parsear Vertices

            // Cargar la infomracion del modelo en un vector
            vertices.resize(baseMesh->mNumVertices);

            for (unsigned i = 0; i < baseMesh->mNumVertices; ++i) {

                // Posicion de los vertices
                vertices[i].position = { baseMesh->mVertices[i].x, baseMesh->mVertices[i].y, baseMesh->mVertices[i].z };

                // Normales
                vertices[i].normal   = { baseMesh->mNormals[i].x, baseMesh->mNormals[i].y, baseMesh->mNormals[i].z };

                // Texture UV
                vertices[i].uv       = baseMesh->mTextureCoords[0]
                    ? glm::vec2{ baseMesh->mTextureCoords[0][i].x, baseMesh->mTextureCoords[0][i].y }
                : glm::vec2{ 0.0f, 0.0f };

            }

            // ✦ . ──────────────────────────────── .✦
            // Parsear indices

            // Cargar los datos del EBO en un vector
            indices.resize(baseMesh->mNumFaces * 3);

            // Recorre cada una de las caras del modelo exportando los indices de los vertices
            // que la componene
            for (unsigned i = 0; i < baseMesh->mNumFaces; ++i) {
                aiFace& face = baseMesh->mFaces[i];
                for (unsigned j = 0; j < face.mNumIndices; ++j)
                    indices.push_back(face.mIndices[j]);
            }

        }

        // ✦ . ──────────────────────────────── .✦
        // ▄▖      ▄▖▖   ▄ ▄▖▄▖
        // ▌▌▛▌█▌▛▌▌ ▌   ▌▌▚ ▌▌
        // ▙▌▙▌▙▖▌▌▙▌▙▖  ▙▘▄▌▛▌
        //   ▌
        // ✶ ────────────── ✶

        // ✶ ───
        // VBO

            // Crear VBO
            glCreateBuffers(1, &meshResource->VBO);

            // Cargar vertices en VBO
            glNamedBufferStorage(meshResource->VBO , vertices.size() * sizeof(Vertex), vertices.data(), 0);

        // ✶ ───
        // EBO

            // Crear EBO
            glCreateBuffers(1, &meshResource->EBO);

            // Cargar Indices en EBO
            glNamedBufferData(meshResource->EBO , indices.size() * sizeof(unsigned), indices.data(), GL_STATIC_DRAW);

        // ✶ ───
        // VAO

            // Crear VAO
            glCreateVertexArrays(1, &meshResource->VAO);

            // Conectar VBO al Binding Point 0 del VAO
            glVertexArrayVertexBuffer(meshResource->VAO , 0 , meshResource->VBO , 0 , sizeof(Vertex)  );

            // Asginar el EBO al VAO
            glVertexArrayElementBuffer(meshResource->VAO, meshResource->EBO );

        // ✶ ───
        // Cargar informacion al VAO

            // ✦ . ───────────
            // Atributo 0 :: Posiciones de los vertices

                // Habilitar el atributo 0
                glEnableVertexArrayAttrib(meshResource->VAO, 0);

                // Configurar formato de lecttura del atributo
                glVertexArrayAttribFormat(meshResource->VAO, 0, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, position));

                // Enlazar el binding point 0 al atributo 0
                glVertexArrayAttribBinding(meshResource->VAO, 0, 0);

            // ✦ . ───────────
            // Atributo 1 :: Normales

                // Habilitar el atributo 1
                glEnableVertexArrayAttrib(meshResource->VAO, 1);

                // Configurar formato de lecttura del atributo
                glVertexArrayAttribFormat(meshResource->VAO, 1, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, normal));

                // Enlazar el binding point 0 al atributo 1
                glVertexArrayAttribBinding(meshResource->VAO, 1, 0);

            // ✦ . ───────────
            // Atributo 2 :: UV

                // Habilitar el atributo 2
                glEnableVertexArrayAttrib(meshResource->VAO, 2);

                // Configurar formato de lecttura del atributo
                glVertexArrayAttribFormat(meshResource->VAO, 2, 2, GL_FLOAT, GL_FALSE, offsetof(Vertex, uv));

                // Enlazar el binding point 0 al atributo 2
                glVertexArrayAttribBinding(meshResource->VAO, 2, 0);

        // Cargar la cantidad de indices en el EBO
        meshResource->indexCount = static_cast<GLsizei>(indices.size());

        LOG_INFO("(Trinity::ResourceLoaders::meshLoader) Mesh: \"{}\" cargada. | # de vertices: {}  ", meshFilePath , indices.size());

        return meshResource;
    }

}
