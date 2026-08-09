#pragma once

// ✦ . ──────────────────────────────── .✦
// Librerias de Sistema
    #include <iostream>
    #include <string>
    #include <memory>
    #include <functional>
    #include <unordered_map>

namespace Trinity {

    template<typename T>
    class ResourceManager {
    public:

        // Alias para la funcion lambda a ingresar a modo de cargador de recursos
        using Loader = std::function<std::shared_ptr<T>(const std::string& path)>;

        // Consturctor, carga la lambda pasada como argumento a modo de metodo cargador de recursos
        ResourceManager(Loader loader) : m_loader(loader) {}

        // Manejo y obttencion del shared_ptr al recurso
        std::shared_ptr<T> Get(const std::string& path) {

            // Intenta buscar el recurso en el map
            auto it = m_cache.find(path);

            // En caso de encontrarlo, retornar el puntero
            if (it != m_cache.end()) {

                // recurso ya cargado, se reusa la instancia
                return it->second;
            }

            // en caso de no, cargar el recurso y guardarlo en el map
            auto resource = m_loader(path);
            m_cache[path] = resource;

            // Retornar el recurso
            return resource;
        }

    private:

        // Funcion cargadora de recursos
        Loader m_loader;

        // Cache de recursos cargados
        std::unordered_map<std::string, std::shared_ptr<T>> m_cache;
    };

}
