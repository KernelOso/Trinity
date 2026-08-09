#pragma once

// ✦ . ──────────────────────────────── .✦
// Librerias de Sistema
#include <iostream>
#include <string>
// ✦ . ──────────────────────────────── .✦
// Librerias solo cabeceras
#include "glad/glad.h"
// ✦ . ──────────────────────────────── .✦
// Librerias thirdparty
#include "SDL3/SDL.h"
// ✦ . ──────────────────────────────── .✦
// Librerias internas
    #include "Trinity/Logger.hpp"

namespace Trinity {

    // ✦ . ──────────────────────────────── .✦
    // ▄▖  ▗       ▗          ▌    ▜     ▖▖    ▗
    // ▙▖▛▘▜▘▛▘▌▌▛▘▜▘▌▌▛▘▀▌  ▛▌█▌  ▐ ▀▌  ▌▌█▌▛▌▜▘▀▌▛▌▀▌
    // ▙▖▄▌▐▖▌ ▙▌▙▖▐▖▙▌▌ █▌  ▙▌▙▖  ▐▖█▌  ▚▘▙▖▌▌▐▖█▌▌▌█▌
    // ✶ ────────────── ✶

    struct Window {

        // ✦ . ──────────────────────────────── .✦
        // ▄▖    ▗
        // ▙▌▌▌▛▌▜▘█▌▛▘▛▌▛▘
        // ▌ ▙▌▌▌▐▖▙▖▌ ▙▌▄▌
        // ✶ ────────────── ✶

        // Puntero al objeto ventana SDL3
        SDL_Window* sdlWindow = nullptr;

        // Contexto OpenGL
        SDL_GLContext openGlContext = nullptr;

        // ✦ . ──────────────────────────────── .✦
        // ▄▖    ▐▘▘     ▌    ▜     ▖▖    ▗
        // ▌ ▛▌▛▌▜▘▌▛▌  ▛▌█▌  ▐ ▀▌  ▌▌█▌▛▌▜▘▀▌▛▌▀▌
        // ▙▖▙▌▌▌▐ ▌▙▌  ▙▌▙▖  ▐▖█▌  ▚▘▙▖▌▌▐▖█▌▌▌█▌
        //          ▄▌
        // ✶ ────────────── ✶

            // ✶ ────────────── ✶
            // Setters:

                Window& setTitle(std::string title) {
                    if (!sdlWindow) return *this;
                    if (!SDL_SetWindowTitle(sdlWindow, title.c_str())) {
                        LOG_ERROR("Error al cambiar el titulo de la ventana SDL");
                    }
                    LOG_INFO("Titulo de la ventana configurado en: {}" , title);
                    return *this;
                }

                Window& setSize(int width , int height) {
                    if (!sdlWindow) return *this;
                    if (!SDL_SetWindowSize(sdlWindow, width, height)) {
                        LOG_ERROR("Error al cambiar el tamanio de la ventana SDL");
                    }
                    LOG_INFO("Tamanio de la ventana configurado en: {} x {}" , width , height);
                    return *this;
                }

                Window& setFullscreen(bool isFullscreen) {
                    if (!sdlWindow) return *this;
                    if (!SDL_SetWindowFullscreen(sdlWindow, isFullscreen)) {
                        LOG_ERROR("Error al cambiar el estado de la pantalla completa en la ventana SDL");
                    }
                    LOG_INFO("Estado de la pantalla completa configurado en: {}" , isFullscreen);
                    return *this;
                }

                Window& setResizable(bool isResizable) {
                    if (!sdlWindow) return *this;
                    if (!SDL_SetWindowResizable(sdlWindow, isResizable)) {
                        LOG_ERROR("Error al cambiar el estado del modo \"resizable\" en la ventana SDL");
                    }
                    LOG_INFO("Estado \"resizable\" de la ventana configurado en: {}" , isResizable);
                    return *this;
                }

                Window& setVsync(int vsyncMode) {
                    /*
                     *  -1 :: Vsync Adaptativo
                     *  0 :: Vsync Desactivado
                     *  1 :: Vsync Activado
                     */
                    if (!openGlContext) return *this; // guard mínimo
                    if (!SDL_GL_SetSwapInterval(vsyncMode)) {
                        LOG_ERROR("Error al cambiar el modo V-Sync en la ventana SDL");
                    }
                    LOG_INFO("Modo V-Sync configurado en: {}" , vsyncMode);
                    return *this;
                }

            // ✶ ────────────── ✶
            // Getters:

                std::string getTitle() {
                    if (!sdlWindow) return "";
                    return SDL_GetWindowTitle(sdlWindow);
                }

            // ✶ ────────────── ✶
            // Togglers:

        // ✦ . ──────────────────────────────── .✦
        // ▄▖▜        ▌          ▘▐▘▘      ▘
        // ▙▖▐ ▀▌▛▌  ▛▌█▌  ▌▌█▌▛▘▌▜▘▌▛▘▀▌▛▘▌▛▌▛▌
        // ▌ ▐▖█▌▙▌  ▙▌▙▖  ▚▘▙▖▌ ▌▐ ▌▙▖█▌▙▖▌▙▌▌▌
        //       ▄▌
        // ✶ ────────────── ✶

        bool isValid = false;

        // ✦ . ──────────────────────────────── .✦
        // ▖ ▖▘  ▄▖  ▗     ▄▖ ▌
        // ▛▖▌▌  ▙▌▌▌▜▘▀▌  ▐ ▛▌█▌▀▌
        // ▌▝▌▌  ▌ ▙▌▐▖█▌  ▟▖▙▌▙▖█▌
        // ✶ ────────────── ✶
        /*
         *  No tengo ni puta idea como funciona esto,
         *  pero basicamente evita errores al intentar
         *  copiar el objeto
         */

            Window() = default;
            Window(const Window&) = delete;
            Window& operator=(const Window&) = delete;
            Window(Window&& other) noexcept { *this = std::move(other); }
            Window& operator=(Window&& other) noexcept {
                if (this != &other) {
                    destroy();
                    sdlWindow = other.sdlWindow;
                    openGlContext = other.openGlContext;
                    isValid = other.isValid;
                    other.sdlWindow = nullptr;
                    other.openGlContext = nullptr;
                    other.isValid = false;
                }
                return *this;
            }
            ~Window() { destroy(); }

        // ✦ . ──────────────────────────────── .✦
        // ▄     ▗       ▗
        // ▌▌█▌▛▘▜▘▛▘▌▌▛▘▜▘▛▌▛▘
        // ▙▘▙▖▄▌▐▖▌ ▙▌▙▖▐▖▙▌▌
        // ✶ ────────────── ✶
        void destroy() {
            LOG_INFO("Destruyendo la ventana SDL...");

            if (openGlContext) { SDL_GL_DestroyContext(openGlContext); openGlContext = nullptr; }
            if (sdlWindow) {SDL_DestroyWindow(sdlWindow); sdlWindow = nullptr; }
        }

    };

    // ✦ . ──────────────────────────────── .✦
    // ▄▖      ▗       ▗
    // ▌ ▛▌▛▌▛▘▜▘▛▘▌▌▛▘▜▘▛▌▛▘
    // ▙▖▙▌▌▌▄▌▐▖▌ ▙▌▙▖▐▖▙▌▌
    // ✶ ────────────── ✶
    inline Window initOpenGlWindow( int openGlMajorVersion , int openGlMinorVersion ) {

        LOG_INFO("Inicializando la ventana SDL...");

        // Crear el objeto de la ventana
        Window windowContext;

        // ✦ . ──────────────────────────────── .✦
        // ▄▖    ▐▘▘          ▘          ▄▖      ▄▖▖
        // ▌ ▛▌▛▌▜▘▌▛▌▌▌▛▘▀▌▛▘▌▛▌▛▌█▌▛▘  ▌▌▛▌█▌▛▌▌ ▌
        // ▙▖▙▌▌▌▐ ▌▙▌▙▌▌ █▌▙▖▌▙▌▌▌▙▖▄▌  ▙▌▙▌▙▖▌▌▙▌▙▖
        //          ▄▌                     ▌
        // ✶ ────────────── ✶

        // Define la version OpenGL a utilizar
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, openGlMajorVersion );
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, openGlMinorVersion );

        LOG_DEBUG("Version de OpenGL configurada en: {}.{}" , openGlMajorVersion , openGlMinorVersion);

        // Define que se va a utilizar el perfil de desarrollo "core" de OpenGL
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        // ✦ . ──────────────────────────────── .✦
        // ▄▖               ▗       ▄▖▄ ▖
        // ▌ ▛▌▛▛▌▛▌▛▌▛▌█▌▛▌▜▘█▌▛▘  ▚ ▌▌▌
        // ▙▖▙▌▌▌▌▙▌▙▌▌▌▙▖▌▌▐▖▙▖▄▌  ▄▌▙▘▙▖
        //        ▌
        // ✶ ────────────── ✶

        // Inicializa el componente de Video SDL
        if (!SDL_Init(SDL_INIT_VIDEO))
        {
            LOG_ERROR("Error al inicializar el componente de video SDL :: {}" , SDL_GetError());
            return windowContext;
        }

        // ✦ . ──────────────────────────────── .✦
        // ▄▖          ▖▖    ▗         ▄▖▄ ▖
        // ▌ ▛▘█▌▀▌▛▘  ▌▌█▌▛▌▜▘▀▌▛▌▀▌  ▚ ▌▌▌
        // ▙▖▌ ▙▖█▌▌   ▚▘▙▖▌▌▐▖█▌▌▌█▌  ▄▌▙▘▙▖
        // ✶ ────────────── ✶
        windowContext.sdlWindow = SDL_CreateWindow(
            " - Loading - ",
            400,
            400,
            SDL_WINDOW_OPENGL
        );
            // En caso de error creando la ventana:
            if (!windowContext.sdlWindow)
            {
                LOG_ERROR("Error al crear la ventana SDL :: {}" , SDL_GetError());
                return windowContext;
            }

        // ✦ . ──────────────────────────────── .✦
        // ▄▖                  ▗     ▗     ▄▖      ▄▖▖
        // ▌ ▀▌▛▘▛▌▀▌▛▘  ▛▘▛▌▛▌▜▘█▌▚▘▜▘▛▌  ▌▌▛▌█▌▛▌▌ ▌
        // ▙▖█▌▌ ▙▌█▌▌   ▙▖▙▌▌▌▐▖▙▖▞▖▐▖▙▌  ▙▌▙▌▙▖▌▌▙▌▙▖
        //       ▄▌                          ▌
        // ✶ ────────────── ✶

        // Crear contexto OpenGL
        windowContext.openGlContext = SDL_GL_CreateContext(windowContext.sdlWindow);

            // En caso de error creando el contexto:
            if (!windowContext.openGlContext)
            {
                LOG_ERROR("Error al crear el contexto OpenGL");
                return windowContext;
            }

        // Cargar funciones OpenGL con glad
        if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
        {
            LOG_ERROR("Error al cargar las funciones OpenGL con GLAD");
            return windowContext;
        }

        // ✦ . ──────────────────────────────── .✦
        // ▄▖▜        ▌          ▘▐▘▘      ▘
        // ▙▖▐ ▀▌▛▌  ▛▌█▌  ▌▌█▌▛▘▌▜▘▌▛▘▀▌▛▘▌▛▌▛▌
        // ▌ ▐▖█▌▙▌  ▙▌▙▖  ▚▘▙▖▌ ▌▐ ▌▙▖█▌▙▖▌▙▌▌▌
        //       ▄▌
        // ✶ ────────────── ✶
        LOG_INFO("Ventana inicializada correctamente!");
        windowContext.isValid = true;
        return windowContext;
    }
}
