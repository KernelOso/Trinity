
// ✦ . ──────────────────────────────── .✦
// Librerias de Sistema
    #include <string>
// ✦ . ──────────────────────────────── .✦
// Librerias solo cabeceras
    #include "glad/glad.h"
    // ✶ ──
    #include "imgui/imgui.h"
    #include "imgui/backends/imgui_impl_sdl3.h"
    #include "imgui/backends/imgui_impl_opengl3.h"
// ✦ . ──────────────────────────────── .✦
// Librerias thirdparty
    #include "SDL3/SDL.h"
    // ✶ ──
    #include "flecs.h"
// ✦ . ──────────────────────────────── .✦
// Librerias internas
    #include "Trinity/Window.hpp"
    #include "Trinity/Logger.hpp"
// ✦ . ──────────────────────────────── .✦
// Resource Managers
    #include "Trinity/ResourceManagers/MeshManager.hpp"
// ✦ . ──────────────────────────────── .✦
// ECS
    #include "Trinity/Components/MeshComponent.hpp"

/*
 *  Nota importante:
 *
 *  Es MI CODIGO, Y YO VERE SI A MI SE ME DA LA HIJUEPUTA GANA
 *  DE PONER LOS COMENTARIOS EN ESPA;OL (no tengo la Ñ en mi teclado XD'nt)
 *
 */

int main() {

    std::cout << R"(
█▀▀▀▀▀▀▀▀▀▀█ █▀▀▀▀▀▀▀▀▀▄  █▀▀▀▀█ █▀▀▀▀▀▀▀▀▀▄  █▀▀▀▀█ █▀▀▀▀▀▀▀▀▀▀█ █▀▀▀▀█ ▓▀▀▀█
█▄▄▄·   ▄▄▄█ ▀    ▄▄  ∙ █ ▀    ▓ ▀    ▄▄    █ ▀    ▓ █▄▄▄·   ▄▄▄█ ▀    ▓ ▒ ∙ █
   ▓  . ▓    ▓    ▓▄▌   ▓ ▓    ▓ ▓    ▓ ▌   ▓ ▓    ▓    ▓  . ▓    ▓    ▓▄░   ▓
   ▒ ∙  ▒    ▒   ·▄▄▄  ▀▄ ▒   ·▒ ▒    ▒ ▒ · ▒ ▒   ·▒    ▒ ∙  ▒    ▀▄▄▄▄▄▄▄   ▒
   ░    ░    ░ .  ░ ░  .░ ░ .  ░ ░   ∙░ ░   ░ ░ .  ░    ░    ░    ▄▄▄▄▄▄ ░  .░
   █    █    █    █ █∙  █ █    █ █ ∙  █ █   █ █    █    █    █    ░    ▀▀▀∙  █
   █▄▄▄▄█    █▄▄▄▄█ █▄▄▄█ █▄▄▄▄█ █▄▄▄▄█ █▄▄▄█ █▄▄▄▄█    █▄▄▄▄█    █▄▄▄▄▄▄▄▄▄▄█
✶ ────────────────────────────────────────────────────────────────────────────
    Por: @KernelOso
✶ ─────────────
    )" << std::endl;

    // ✦ . ──────────────────────────────── .✦
    // ▄▖    ▐▘▘            ▄▖▄▖▄   ▖
    // ▌ ▛▌▛▌▜▘▌▛▌▌▌▛▘▀▌▛▘  ▚ ▙▌▌▌▄▖▌ ▛▌▛▌
    // ▙▖▙▌▌▌▐ ▌▙▌▙▌▌ █▌▌   ▄▌▌ ▙▘  ▙▖▙▌▙▌
    //          ▄▌                      ▄▌
    // ✶ ────────────── ✶

    Trinity::Logger::initLogger();

    // Contexto interno del motor
    // Evita que todo se vaya a la mierda al momento de terminar la ejecucion
    // Obliga a que los objetos se destruyan correctamente

    // ✦ . ──────────────────────────────── .✦
    // ▄▖      ▗     ▘    ▖▖    ▗
    // ▌ ▛▌▛▌▛▘▜▘▛▘▌▌▌▛▘  ▌▌█▌▛▌▜▘▀▌▛▌▀▌
    // ▙▖▙▌▌▌▄▌▐▖▌ ▙▌▌▌   ▚▘▙▖▌▌▐▖█▌▌▌█▌
    // ✶ ────────────── ✶

    // Crear la ventana inicial
    Trinity::Window window = Trinity::initOpenGlWindow( 4 , 6 );

    // Configurar la ventana
    window  .setTitle( "Trinity DEV" )
            .setSize( 1280 , 720 )
            .setResizable( false )
            .setVsync( 1 );
    {

        // ✦ . ──────────────────────────────── .✦
        // ▄▖    ▐▘▘          ▘      ▄▖   ▄▖  ▘
        // ▌ ▛▌▛▌▜▘▌▛▌▌▌▛▘▀▌▛▘▌▛▌▛▌  ▐ ▛▛▌▌ ▌▌▌
        // ▙▖▙▌▌▌▐ ▌▙▌▙▌▌ █▌▙▖▌▙▌▌▌  ▟▖▌▌▌▙▌▙▌▌
        //          ▄▌
        // ✶ ────────────── ✶

        LOG_DEBUG("(Main::ImGui) Inicializando ImGui...");

        // Inicializar ImGui
        ImGui::CreateContext();
        ImGuiIO& imGuiIo = ImGui::GetIO();
        imGuiIo.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

        // Definir tema ImGui
        ImGui::StyleColorsDark();

        // Conectar ImGui con SDL y OpenGL
        ImGui_ImplSDL3_InitForOpenGL(window.sdlWindow, window.openGlContext);
        ImGui_ImplOpenGL3_Init("#version 460");

        LOG_INFO("(Main::ImGui) Contexto global de ImGui inicializado");

        // ✦ . ──────────────────────────────── .✦
        // ▄▖▜
        // ▙▖▐ █▌▛▘▛▘
        // ▌ ▐▖▙▖▙▖▄▌
        // ✶ ────────────── ✶

        LOG_DEBUG("(Main::Flecs) Inicializando entorno de ejecucion Flecs...");

        // Inicializar flecs
        flecs::world flecsWorld;

        flecsWorld.emplace<Trinity::ResourceManagers::MeshManager>();

        auto& meshManager = flecsWorld.get_mut<Trinity::ResourceManagers::MeshManager>();

        auto testCube = flecsWorld.entity()
            .set<Trinity::Components::MeshComponent>({  meshManager.Get("base/meshes/cube.obj") })
        ;

        LOG_INFO("(Main::Flecs) Entorno de ejecucion Flecs cargado.");

        // ✦ . ──────────────────────────────── .✦
        // ▄   ▜ ▗     ▄▖▘
        // ▌▌█▌▐ ▜▘▀▌▄▖▐ ▌▛▛▌█▌
        // ▙▘▙▖▐▖▐▖█▌  ▐ ▌▌▌▌▙▖
        // ✶ ────────────── ✶
        Uint64 currentTime = SDL_GetPerformanceCounter();
        Uint64 lastTime = 0;
        double deltaTime = 0.0;

        // ✦ . ──────────────────────────────── .✦
        // ▄▖▄▖▄▖  ▄▖      ▗
        // ▙▖▙▌▚   ▌ ▛▌▌▌▛▌▜▘█▌▛▘
        // ▌ ▌ ▄▌  ▙▖▙▌▙▌▌▌▐▖▙▖▌
        // ✶ ────────────── ✶
        int frameCount = 0;
        double fps_timer = 0.0;
        int actualFPS = 0;

        // ✦ . ──────────────────────────────── .✦
        // ▖  ▖  ▘    ▖
        // ▛▖▞▌▀▌▌▛▌  ▌ ▛▌▛▌▛▌
        // ▌▝ ▌█▌▌▌▌  ▙▖▙▌▙▌▙▌
        //                  ▌
        // ✶ ────────────── ✶

        // Manejo de eventos SDL
        SDL_Event event;

        // El programa seguira corriendo?
        bool isRunning = true;

        // Bucle principal...
        while (isRunning) {

            // ✦ . ──────────────────────────────── .✦
            // ▄   ▜ ▗     ▄▖▘
            // ▌▌█▌▐ ▜▘▀▌▄▖▐ ▌▛▛▌█▌
            // ▙▘▙▖▐▖▐▖█▌  ▐ ▌▌▌▌▙▖
            // ✶ ────────────── ✶
            lastTime = currentTime;
            currentTime = SDL_GetPerformanceCounter();
            deltaTime = (double)(currentTime - lastTime) / (double)SDL_GetPerformanceFrequency();

            // ✦ . ──────────────────────────────── .✦
            // ▄▖▄▖▄▖  ▄▖      ▗
            // ▙▖▙▌▚   ▌ ▛▌▌▌▛▌▜▘█▌▛▘
            // ▌ ▌ ▄▌  ▙▖▙▌▙▌▌▌▐▖▙▖▌
            // ✶ ────────────── ✶
            frameCount++;
            fps_timer += deltaTime;
            if (fps_timer >= 1.0) {
                actualFPS = frameCount;
                frameCount = 0;
                fps_timer -= 1.0;
            }

            // ✦ . ──────────────────────────────── .✦
            // ▄▖    ▗      ▘    ▗      ▌    ▄▖      ▗       ▄▖▄ ▖
            // ▐ ▛▘▀▌▜▘▀▌▛▛▌▌█▌▛▌▜▘▛▌  ▛▌█▌  ▙▖▌▌█▌▛▌▜▘▛▌▛▘  ▚ ▌▌▌
            // ▐ ▌ █▌▐▖█▌▌▌▌▌▙▖▌▌▐▖▙▌  ▙▌▙▖  ▙▖▚▘▙▖▌▌▐▖▙▌▄▌  ▄▌▙▘▙▖
            // ✶ ────────────── ✶

            // Por cada evento registrado por SDL desde el ultimo frame realizar...
            while (SDL_PollEvent(&event)) {

                // Inyectar eventos a ImGui
                ImGui_ImplSDL3_ProcessEvent(&event);

                // Cerrar la ejecucion de forma segura
                if (event.type == SDL_EVENT_QUIT) isRunning = false;

            } // Tratamiento de eventos SDL

            // ✦ . ──────────────────────────────── .✦
            // ▄▖      ▄▖▖
            // ▌▌▛▌█▌▛▌▌ ▌
            // ▙▌▙▌▙▖▌▌▙▌▙▖
            //   ▌
            // ✶ ────────────── ✶

            // Color base del frame
            glClearColor(0.6f , 0.733f , 0.949f , 0.0f);

            // Limpiar el frame anterior
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // Dibujar frame...

            // ✦ . ──────────────────────────────── .✦
            // ▄▖   ▄▖  ▘
            // ▐ ▛▛▌▌ ▌▌▌
            // ▟▖▌▌▌▙▌▙▌▌
            // ✶ ────────────── ✶
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplSDL3_NewFrame();
            ImGui::NewFrame();

            ImGui::Begin("Monitor Global");
            ImGui::Text("FPS: %d" , actualFPS );
            ImGui::Text("Delta-Time: %fms" , deltaTime * 1000);
            ImGui::End();

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            // ✦ . ──────────────────────────────── .✦

            // mostrar el frame dibujado
            SDL_GL_SwapWindow(window.sdlWindow);

        }

        // ✦ . ──────────────────────────────── .✦
        // ▖ ▘     ▘        ▄▖▘    ▜
        // ▌ ▌▛▛▌▛▌▌█▌▀▌▀▌  ▙▖▌▛▌▀▌▐
        // ▙▖▌▌▌▌▙▌▌▙▖▙▖█▌  ▌ ▌▌▌█▌▐▖
        //       ▌
        // ✶ ────────────── ✶
        LOG_INFO("✦ . ──────────────────────────────────────────────────────────────── .✦");
        LOG_INFO("(Main::ExecEnd) Terminando la ejecucion de forma ordenada...");

        LOG_DEBUG("(Main::ExecEnd::ImGui) Limpiando contexto global ImGui");
        // Limpiar ImGui
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplSDL3_Shutdown();
        ImGui::DestroyContext();
        LOG_INFO("(Main::ExecEnd::ImGui) Se limpio correctamente el contexto global ImGui.");

    }

    // Destruir la ventana SDL
    window.destroy();

    // Limpia por completo la ejecucion de SDL
    SDL_Quit();

    // Limpiar SPDLog
    spdlog::shutdown();

    return 0;
}
