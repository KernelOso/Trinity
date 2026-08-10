
# ✦ ──────
# ▄█████ ██▄  ▄██  ▄▄▄  ▄▄ ▄▄ ▄▄▄▄▄ 
# ██     ██ ▀▀ ██ ██▀██ ██▄█▀ ██▄▄  
# ▀█████ ██    ██ ██▀██ ██ ██ ██▄▄▄ 
# Fuente: ANSI Compact
# ✦ . ──────────────────────────────────────────────────────────────────── .✦

# ✶ ──

    # Define explicitamente la version de Cmake a utilizar
    cmake_minimum_required(VERSION "3.20")

# ✶ ──


# ✦ ──────
# █████▄ ▄▄ ▄▄ ▄▄ ▄▄    ▄▄▄▄    █████▄ ▄▄▄▄  ▄▄▄▄▄  ▄▄▄▄ ▄▄▄▄▄ ▄▄▄▄▄▄ ▄▄▄▄ 
# ██▄▄██ ██ ██ ██ ██    ██▀██   ██▄▄█▀ ██▄█▄ ██▄▄  ███▄▄ ██▄▄    ██  ███▄▄ 
# ██▄▄█▀ ▀███▀ ██ ██▄▄▄ ████▀   ██     ██ ██ ██▄▄▄ ▄▄██▀ ██▄▄▄   ██  ▄▄██▀  
# Fuente: ANSI Compact
# ✦ . ──────────────────────────────────────────────────────────────────── .✦
#
#   PC Release :
#
#       Cmake Project Folder:
#
#           cmake -S . -B cmake/build-release -G Ninja -DCMAKE_BUILD_TYPE=Release
#   
#       Compile Project:
#
#           cmake --build cmake/build-release --parallel $(nproc)
#
#       Run Project:
#
#           ./bin/release/Trinity
#  
#   PC Debug :
#
#       Cmake Project Folder:
#
#           cmake -S . -B cmake/build-debug -G Ninja -DCMAKE_BUILD_TYPE=Debug 
#
#       Compile Project:
#
#           cmake --build cmake/build-debug --parallel $(nproc)
#
#       Run Project:
#
#           ./bin/debug/Trinity
#


# ✦ ──────
# █████▄ ▄▄▄▄   ▄▄▄    ▄▄ ▄▄▄▄▄  ▄▄▄▄ ▄▄▄▄▄▄   ▄█████ ▄▄▄▄▄▄ ▄▄▄▄  ▄▄ ▄▄  ▄▄▄▄ ▄▄▄▄▄▄ 
# ██▄▄█▀ ██▄█▄ ██▀██   ██ ██▄▄  ██▀▀▀   ██     ▀▀▀▄▄▄   ██   ██▄█▄ ██ ██ ██▀▀▀   ██   
# ██     ██ ██ ▀███▀ ▄▄█▀ ██▄▄▄ ▀████   ██     █████▀   ██   ██ ██ ▀███▀ ▀████   ██   
# Fuente: ANSI Compact
# ✦ . ──────────────────────────────────────────────────────────────────── .✦
#
#   ./ 
#   ├─  ./build/ : Directorio pendej de VsCode
#   │       
#   ├─  ./cmake/ : Directorio de proyectos de compilacion cmake
#   │   │
#   │   ├─  ./cmake/build-debug/   : Directorio de proyecto de compilacion de debugeo
#   │   │
#   │   └─  ./cmake/build-release/ : Directorio de proyecto de compilacion de produccion
#   │
#   ├─  ./bin/          : Directorio de binarios ejecutables post-compilacion
#   │   │
#   │   ├─  ./bin/debug/   : Directorio donde terminara el ejecutable de debugeo
#   │   │
#   │   └─  ./bin/release/ : Directorio donde terminara el ejecutable de produccion
#   │
#   ├─  ./include/      : Directorio de archivos de cabecera del proyecto (.h)
#   │
#   ├─  ./libs/         : Directorio de importacion de librerias basadas en solo archivos de cabeceras (.h)
#   │
#   ├─  ./resources/    : Directorio de archivos y recursos externos (Texturas, archivos de texto, etc...)
#   │
#   ├─  ./src/          : Directorio principal de archivos de codigo
#   │
#   ├─  ./thirdparty/   : Directorio de proyectos CMake de librerias estaticas a compilar junto el proyecto principal
#   │
#   └─  ./CMakeLists.txt: Este archivo
#

# ✦ ──────
# ██▄  ▄██ ██  ██ ▄█████ ▄█████   ██  ██  ▄▄▄▄ █████▄  ▄▄▄▄▄ ▄▄▄▄  ▄▄▄▄  ▄▄ ▄▄▄▄▄▄ ▄▄▄▄ 
# ██ ▀▀ ██ ██▄▄██ ▀▀▀▄▄▄ ██       ██▄▄██ ██▀▀▀ ██▄▄██▄ ██▄▄  ██▀██ ██▀██ ██   ██  ███▄▄ 
# ██    ██  ▀██▀  █████▀ ▀█████    ▀██▀  ▀████ ██   ██ ██▄▄▄ ████▀ ████▀ ██   ██  ▄▄██▀  
# Fuente: ANSI Compact
# ✦ . ──────────────────────────────────────────────────────────────────── .✦
#
#   Estas 2 lineas le indican a Cmake que compile de forma estatica las librerias
#   VcRedist para runtime del programa en Windows
#
#   Esta configuracion solo funciona en Windows con el compilador MSVC
#

# ✶ ── 

    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")

# ✶ ──


# ✦ ──────
# ▄█████  ▄▄▄  ▄▄   ▄▄ ▄▄▄▄  ▄▄ ▄▄    ▄▄▄▄▄   ▄████▄ ▄▄▄▄ ▄▄▄▄▄▄ ▄▄ ▄▄   ▄▄ ▄▄ ▄▄▄▄▄  ▄▄▄ ▄▄▄▄▄▄ ▄▄  ▄▄▄  ▄▄  ▄▄  ▄▄▄▄ 
# ██     ██▀██ ██▀▄▀██ ██▄█▀ ██ ██    ██▄▄    ██  ██ ██▄█▀  ██   ██ ██▀▄▀██ ██   ▄█▀ ██▀██  ██   ██ ██▀██ ███▄██ ███▄▄ 
# ▀█████ ▀███▀ ██   ██ ██    ██ ██▄▄▄ ██▄▄▄   ▀████▀ ██     ██   ██ ██   ██ ██ ▄██▄▄ ██▀██  ██   ██ ▀███▀ ██ ▀██ ▄▄██▀    
# Fuente: ANSI Compact    
# ✦ . ──────────────────────────────────────────────────────────────────── .✦
#
#   En caso de una compilacion de deslpiegue (release),
#   compilar utilizando las optimizaciones IPO/LTO
#

# ✶ ──

    if(CMAKE_BUILD_TYPE STREQUAL "Release")

        set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

    else()

        set(CMAKE_INTERPROCEDURAL_OPTIMIZATION FALSE)

    endif()

# ✶ ──


# ✦ ──────
# ▄█████ ██▄  ▄██  ▄▄▄  ▄▄ ▄▄ ▄▄▄▄▄    ▄████  ▄▄▄▄▄ ▄▄  ▄▄ ▄▄▄▄▄ ▄▄▄▄   ▄▄▄  ▄▄      ▄█████  ▄▄▄  ▄▄  ▄▄ ▄▄▄▄▄ ▄▄  ▄▄▄▄ 
# ██     ██ ▀▀ ██ ██▀██ ██▄█▀ ██▄▄    ██  ▄▄▄ ██▄▄  ███▄██ ██▄▄  ██▄█▄ ██▀██ ██      ██     ██▀██ ███▄██ ██▄▄  ██ ██ ▄▄ 
# ▀█████ ██    ██ ██▀██ ██ ██ ██▄▄▄    ▀███▀  ██▄▄▄ ██ ▀██ ██▄▄▄ ██ ██ ██▀██ ██▄▄▄   ▀█████ ▀███▀ ██ ▀██ ██    ██ ▀███▀ 
# Fuente: ANSI Compact
# ✦ . ──────────────────────────────────────────────────────────────────── .✦
#
#   Variables Utiles :
#    ⊹ ${CMAKE_PROJECT_NAME}         ::   Almacena el nombre del proyecto CMake
#    ⊹ ${CMAKE_CURRENT_SOURCE_DIR}   ::   Almacena la ruta actual del directorio del proyecto
#    

# ✶ ──

    # Especifica el nombre del proyecto CMake
    project("Trinity") 

# ✶ ──

    # Version del estandar C
    set(CMAKE_C_STANDARD 11)

    # Version del estandar C++
    set(CMAKE_CXX_STANDARD 17)

# ✶ ──

    # Ruta donde se alojaran los binarios compilados
    if(CMAKE_BUILD_TYPE STREQUAL "Release")

        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/release")

    else()

        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/debug")

    endif()

# ✶ ──


# ✦ ──────
# ██████ ▄▄ ▄▄ ▄▄▄▄▄  ▄▄▄▄ ▄▄ ▄▄ ▄▄▄▄▄▄ ▄▄▄  ▄▄▄▄  ▄▄    ▄▄▄▄▄ 
# ██▄▄   ▀█▄█▀ ██▄▄  ██▀▀▀ ██ ██   ██  ██▀██ ██▄██ ██    ██▄▄  
# ██▄▄▄▄ ██ ██ ██▄▄▄ ▀████ ▀███▀   ██  ██▀██ ██▄█▀ ██▄▄▄ ██▄▄▄ 
# Fuente: ANSI Compact
# ✦ . ──────────────────────────────────────────────────────────────────── .✦
#
#   Esta linea, agrega automatizamence todos los archivos de codigo
#   en la variable ${MY_SOURCES} para luego ser agregados automaticamente
#   al ejecutable del programa
# 

# ✶ ──

    # Agregar archivos de codigo .c y .cpp 
    file( 
        GLOB_RECURSE 
        
        MY_SOURCES 
        
        CONFIGURE_DEPENDS 
        
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c" 
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    )

# ✶ ──

    # Agregar archivos de codigo al ejecutable
    add_executable(
        "${CMAKE_PROJECT_NAME}" 
        
        "${MY_SOURCES}"
    )

# ✶ ──

    # Agrega todos los archivos de cabecera locales al proyecto
    target_include_directories(
        "${CMAKE_PROJECT_NAME}" 
        
        PUBLIC 
        
        "${CMAKE_CURRENT_SOURCE_DIR}/include/"
    )

# ✶ ──

    # Agrega todos los archivos de cabecera de librerias locales al proyecto
    target_include_directories(
        "${CMAKE_PROJECT_NAME}" 
        
        PUBLIC 
        
        "${CMAKE_CURRENT_SOURCE_DIR}/libs/"
    )

# ✶ ──



# ██     ▄▄ ▄▄▄▄  ▄▄▄▄   ▄▄▄  ▄▄▄▄  ▄▄ ▄▄▄▄▄  ▄▄▄▄ 
# ██     ██ ██▄██ ██▄█▄ ██▀██ ██▄█▄ ██ ██▄▄  ███▄▄ 
# ██████ ██ ██▄█▀ ██ ██ ██▀██ ██ ██ ██ ██▄▄▄ ▄▄██▀ 
# Fuente: ANSI Compact
# ✦ . ──────────────────────────────────────────────────────────────────── .✦
#
#   Librerias agregadas al proyecto
#
#   Se deben organizar en orden de dependencias
#
#   Deben de tener :
#   
#       ⊹ Enlace al recurso original
#       ⊹ Configuraciones de la libreria
#       ⊹ Agregar Subdirectorio (En caso de libreria sub-proyecto)
#       ⊹ Agregar variables de librerias (En caso de librerias pre-compiladas externas)
#       ⊹ Enlazar otras librerias dependentes
#       ⊹ Enlazar al proyecto principal
#

# ✦ . ──────────────────────────────── .✦

    #┏━┓╺┳┓╻
    #┗━┓ ┃┃┃
    #┗━┛╺┻┛┗━╸
    # Fuente : Future
    # ✶ ────────────── ✶

    # ✶ ── ⊹ Repositorio de codigo fuente

        # github.com/libsdl-org/SDL

    # ✶ ── ⊹ Version Instalada

        # github.com/libsdl-org/SDL/releases/tag/release-3.4.14

    # ✶ ── ⊹ Configuraciones de la libreria


        # Act/Des la compilación de la versión compartida (.DLL / .O)
        set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
        set(SDL_SHARED OFF CACHE BOOL "" FORCE)

        # Act/Des la compilación de la versión estática
        set(SDL_STATIC ON CACHE BOOL "" FORCE)

        # Act/Des la compilacion de la libreria de tests interna de SDL
        set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)

        # Act/Des la compilacion de tests
        set(SDL_TESTS OFF CACHE BOOL "" FORCE)

        # Act/Des la compilacion de ejemplos
        set(SDL_SAMPLES OFF CACHE BOOL "" FORCE)
        set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)

        # Act/Des la instalacion como libreria de sistema
        set(SDL_INSTALL OFF CACHE BOOL "" FORCE)

        # ──

        # Act/Des la compilacion del modulo de acceso a camara
        set(SDL_CAMERA OFF CACHE BOOL "" FORCE)

        # Act/Des la compilacion del modulo de acceso a acelerometros y giroscopios
        set(SDL_SENSOR OFF CACHE BOOL "" FORCE)

        # Act/Des la lectura del estado de la bateria del dispositivo
        set(SDL_POWER OFF CACHE BOOL "" FORCE)

        # Act/Des el soporte nativo de ventanas de dialogo (Abrir/Guardar archivo)
        set(SDL_DIALOG OFF CACHE BOOL "" FORCE)

        # Act/Des la Vibracion en mandos
        set(SDL_HAPTIC OFF CACHE BOOL "" FORCE)

        # ──

        # Act/Des el soporte a Vulkan
        set(SDL_VULKAN OFF CACHE BOOL "" FORCE)

        # Desactiva la nueva abstraccion grafica 3D introducida en SDL3
        set(SDL_GPU OFF CACHE BOOL "" FORCE)

        # Desactiva el motor interno de renderizado 2D de SDL
        set(SDL_RENDER OFF CACHE BOOL "" FORCE)

        # Desactiva OpenGL para sistemas embebidos (Mantiene solo el GL de escritorio)
        set(SDL_OPENGLES OFF CACHE BOOL "" FORCE)

    # ✶ ── ⊹ Agregar Sub-Directoroio al proyecto

        add_subdirectory("thirdparty/SDL" EXCLUDE_FROM_ALL)

    # ✶ ── ⊹ Optimizaciones de copmpilacion

        # Habilitar LTO / IPO
        include(CheckIPOSupported)
        check_ipo_supported(RESULT ipo_supported)
        if(ipo_supported)
            set_target_properties(SDL3-static PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)
        endif()

    # ✶ ── ⊹ Linkear libreria al proyecto principal

        target_link_libraries(
                "${CMAKE_PROJECT_NAME}"

                PRIVATE

                SDL3::SDL3
        )

    # ✦ . ──────────────────────────────── .✦

    #┏━╸╻  ┏━╸┏━╸┏━┓
    #┣╸ ┃  ┣╸ ┃  ┗━┓
    #╹  ┗━╸┗━╸┗━╸┗━┛
    # Fuente : Future
    # ✶ ────────────── ✶

    # ✶ ── ⊹ Repositorio de codigo fuente

        # github.com/SanderMertens/flecs

    # ✶ ── ⊹ Version Instalada

        # github.com/SanderMertens/flecs/releases/tag/v4.1.6

    # ✶ ── ⊹ Configuraciones de la libreria

        # Act/Des la compilación de la versión compartida (.DLL/.O)
        set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
        set(FLECS_SHARED OFF CACHE BOOL "" FORCE)

        # Act/Des la compilacion como libreria estatica
        set(FLECS_STATIC ON CACHE BOOL "" FORCE)

        # Act/Des la compilacion de tests
        set(FLECS_TESTS OFF CACHE BOOL "" FORCE)

        # Act/Des Position Independent Code. Al compilar como librería estática,
        set(FLECS_PIC OFF CACHE BOOL "" FORCE)

        # Act/Des el sistema de alertas.
        set(FLECS_ALERTS OFF CACHE BOOL "" FORCE)

        # Act/Des el framework de ventanas y bucle principal integrado de Flecs (Innecesario porque usas SDL3).
        set(FLECS_APP OFF CACHE BOOL "" FORCE)

        # Act/Des la metadata para documentar componentes y entidades internamente.
        set(FLECS_DOC OFF CACHE BOOL "" FORCE)

        # Act/Des el servidor HTTP embebido.
        set(FLECS_HTTP OFF CACHE BOOL "" FORCE)

        # Act/Des el registro de telemetría y eventos en tiempo real (Journaling) del ECS.
        set(FLECS_JOURNAL OFF CACHE BOOL "" FORCE)

        # Act/Des la serialización/deserialización automática de entidades y componentes a formato JSON.
        set(FLECS_JSON OFF CACHE BOOL "" FORCE)

        # Act/Des la salida de logs internos de la librería (Innecesario si vas a usar spdlog para tu motor).
        set(FLECS_LOG OFF CACHE BOOL "" FORCE)

        # Act/Des el sistema de reflexión. Es muy pesado y solo es útil si necesitas
        # leer/escribir componentes genéricos en tiempo de ejecución sin conocer su tipo en C++.
        set(FLECS_META OFF CACHE BOOL "" FORCE)

        # Act/Des los contadores internos de rendimiento y métricas operativas del ECS.
        set(FLECS_METRICS OFF CACHE BOOL "" FORCE)

        # Act/Des el parser interno utilizado para interpretar expresiones y valores desde texto.
        set(FLECS_PARSER OFF CACHE BOOL "" FORCE)

        # Act/Des el Domain Specific Language para queries. Permite buscar entidades usando
        # strings (ej. "Position, Velocity") en lugar de la API builder nativa de C++.
        set(FLECS_QUERY_DSL OFF CACHE BOOL "" FORCE)

        # Act/Des la API REST de depuración (Depende de HTTP y JSON para funcionar).
        set(FLECS_REST OFF CACHE BOOL "" FORCE)

        # Act/Des el motor de scripting para parsear archivos .flecs (lenguaje declarativo propio).
        set(FLECS_SCRIPT OFF CACHE BOOL "" FORCE)

        # Act/Des la recolección de estadísticas de uso del mundo y los sistemas.
        set(FLECS_STATS OFF CACHE BOOL "" FORCE)

        # Act/Des los tipos de datos de medidas estándar incorporados (kilos, metros, bytes, etc.).
        set(FLECS_UNITS OFF CACHE BOOL "" FORCE)

    # ✶ ── ⊹ Agregar Sub-Directoroio al proyecto

        add_subdirectory("thirdparty/flecs" EXCLUDE_FROM_ALL)
    
    # ✶ ── ⊹ Optimizaciones de copmpilacion

        # Desactivar aserciones en Release
        target_compile_definitions(flecs_static PUBLIC $<$<CONFIG:Release>:NDEBUG>)

        # Habilitar LTO / IPO
        include(CheckIPOSupported)
        check_ipo_supported(RESULT ipo_supported)
        if(ipo_supported)
            set_target_properties(flecs_static PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)
        endif()

    # ✶ ── ⊹ Linkear libreria al proyecto principal

        target_link_libraries(
            "${CMAKE_PROJECT_NAME}"

            PRIVATE

            flecs_static
        )

    # ✦ . ──────────────────────────────── .✦

    #┏━┓┏━┓┏━┓╻┏┳┓┏━┓
    #┣━┫┗━┓┗━┓┃┃┃┃┣━┛
    #╹ ╹┗━┛┗━┛╹╹ ╹╹
    # Fuente : Future
    # ✶ ────────────── ✶

    # ✶ ── ⊹ Repositorio de codigo fuente

        # github.com/assimp/assimp

    # ✶ ── ⊹ Version Instalada

        # github.com/assimp/assimp/releases/tag/v6.0.5

    # ✶ ── ⊹ Configuraciones de la libreria

        # Act/Des la compilación de la versión compartida (.DLL/.O)
        set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

        # Act/Des la compilacion de tests
        set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "" FORCE)

        # Act/Des la convercion de advertencias a errores de compilacion
        set(ASSIMP_WARNINGS_AS_ERRORS OFF CACHE BOOL "" FORCE)

        # Act/Des la instalacion de assimp como libreria de sistema
        set(ASSIMP_INSTALL OFF CACHE BOOL "" FORCE)

        # Act/Des la compilacion de las herramientas internas de assimp
        set(ASSIMP_BUILD_ASSIMP_TOOLS OFF CACHE BOOL "" FORCE)

        # Act/Des la compilacion de ejemplos de uso
        set(ASSIMP_BUILD_SAMPLES OFF CACHE BOOL "" FORCE)

        # Act/Des la compilacion integrada de su dependencia zlib
        set(ASSIMP_BUILD_ZLIB ON CACHE BOOL "" FORCE)

        # Act/Des las llamadas a git
        set(ASSIMP_IGNORE_GIT_HASH ON CACHE BOOL "" FORCE)

        # ──

        # Act/Des la funcionalidad de exportacion de modelos
        set(ASSIMP_NO_EXPORT ON CACHE BOOL "" FORCE)

        # Act/Des la compilacion de todos los importadores
        set(ASSIMP_BUILD_ALL_IMPORTERS_BY_DEFAULT OFF CACHE BOOL "" FORCE)

        # Act/Des la compilacion del importador del formato OBJ
        set(ASSIMP_BUILD_OBJ_IMPORTER ON CACHE BOOL "" FORCE)

    # ✶ ── ⊹ Agregar Sub-Directoroio al proyecto

        list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/assimp/cmake-modules")

        add_subdirectory("thirdparty/assimp" EXCLUDE_FROM_ALL)

    # ✶ ── ⊹ Linkear libreria al proyecto principal

        target_link_libraries(
            "${CMAKE_PROJECT_NAME}"

            PRIVATE

            assimp
        )

    # ✦ . ──────────────────────────────── .✦

# █████▄  ▄▄▄▄▄  ▄▄▄▄  ▄▄▄  ▄▄ ▄▄ ▄▄▄▄   ▄▄▄▄ ▄▄▄▄▄  ▄▄▄▄ 
# ██▄▄██▄ ██▄▄  ███▄▄ ██▀██ ██ ██ ██▄█▄ ██▀▀▀ ██▄▄  ███▄▄ 
# ██   ██ ██▄▄▄ ▄▄██▀ ▀███▀ ▀███▀ ██ ██ ▀████ ██▄▄▄ ▄▄██▀ 
# Fuente: ANSI Compact
# ✦ . ──────────────────────────────────────────────────────────────────── .✦
#   
#   Este codigo genera una macro llamada "RESOURCES_PATH" en la cual, dependiendo si es una compilacion de debugeo o de release
#   almacena la ruta del directorio de los recursos a los que podra acceder el proyectpo
#
#   Si es una compilacion Debug :
#       La ruta es el subdirectorio "resources" del proyecto CMake
#
#   Si es una compilacion Release :
#       La ruta es la ruta actual del ejecutable
#
#

    if(CMAKE_BUILD_TYPE STREQUAL "Release")

        target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC "RESOURCES_PATH=\"./resources/\"")

    else()

        target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC "RESOURCES_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}/resources/\"")

    endif ()

                                              