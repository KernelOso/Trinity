# Trinity Game Engine

![[./_README_ASSETS/screenshot.png]]

Solo un simple motor de videojuegos hecho desde 0 en C/C++.

Las librerias utilizadas en este proyecto son:

- OpenGL Core (GLAD) (v4.6) 
- [SDL](https://github.com/libsdl-org/SDL) (v3.4.14)
- [Flecs](https://github.com/SanderMertens/flecs) (v4.1.6)
- [ImGUI](https://github.com/ocornut/imgui) (v1.92.9b)
- [Assimp](https://github.com/assimp/assimp) (v5.0.6)
- [GLM](https://github.com/g-truc/glm) (v1.0.3)
- [SPDLog](https://github.com/gabime/spdlog) (v1.17.0)
- [STB](https://github.com/nothings/stb) 
    - stb_image.h

# Como compilar el proyecto?

Este proyecto esta configurado para usar sus librerias y dependencias de forma estatica, intenamente en la carpeta `thirparty/` estara el codigo fuente de los proyector Cmake de las dependencias utilizadas.

> ⚠️ : Este proyecto solo esta siendo probado y desarrollado en y para Linux; No tengo forma de verificar su compilacion y ejecucion en Windows.


Para generar las carpetas de proyecto CMake se usan los siguienets comandos:

> Se recomineda el uso de Ninja para compilar

```
# Proyecto Debug:
cmake -S . -B cmake/build-debug -G Ninja -DCMAKE_BUILD_TYPE=Debug 

# Proyecto Release: 
cmake -S . -B cmake/build-release -G Ninja -DCMAKE_BUILD_TYPE=Release

```

Para compilar los ejecutables en si, se usan los siguientes comandos:

```
# Compilacion de Debugeo
cmake --build cmake/build-debug --parallel $(nproc)

# Compilacion Release
cmake --build cmake/build-release --parallel $(nproc)
```
