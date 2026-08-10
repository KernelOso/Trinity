#pragma once

#include <iostream>

#ifndef NDEBUG
    #define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG
#endif

#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#ifdef NDEBUG
    #define LOG_DEBUG(...)      ((void)0)
    #define LOG_INFO(...)       spdlog::info(__VA_ARGS__)
    #define LOG_WARN(...)       spdlog::warn(__VA_ARGS__)
    #define LOG_ERROR(...)      spdlog::error(__VA_ARGS__)
    #define LOG_CRITICAL(...)   spdlog::critical(__VA_ARGS__)
#else
    #define LOG_DEBUG(...)      SPDLOG_DEBUG(__VA_ARGS__)
    #define LOG_INFO(...)       SPDLOG_INFO(__VA_ARGS__)
    #define LOG_WARN(...)       SPDLOG_WARN(__VA_ARGS__)
    #define LOG_ERROR(...)      SPDLOG_ERROR(__VA_ARGS__)
    #define LOG_CRITICAL(...)   SPDLOG_CRITICAL(__VA_ARGS__)
#endif

// ✦ . ──────────────────────────────── .✦
// ▄▖    ▐▘▘            ▄▖▄▖▄   ▖
// ▌ ▛▌▛▌▜▘▌▛▌▌▌▛▘▀▌▛▘  ▚ ▙▌▌▌▄▖▌ ▛▌▛▌
// ▙▖▙▌▌▌▐ ▌▙▌▙▌▌ █▌▌   ▄▌▌ ▙▘  ▙▖▙▌▙▌
//          ▄▌                      ▄▌
// ✶ ────────────── ✶
namespace Trinity::Logger {

    inline void initLogger() {

        try {
            // Inicializar el thread pool
            spdlog::init_thread_pool(8192, 1);

            // Crear el logger asyncrono
            auto async_logger = spdlog::stdout_color_mt<spdlog::async_factory>("async_logger");

            // Configurar el disenio de los logs
            #ifdef NDEBUG
                async_logger->set_pattern("%^[%-8l] :: %v %$");
            #else
                async_logger->set_pattern("%^[%-8l] { %-20!s::%4# } :: %v %$");
            #endif

            // Establecer el logger asincrono como el logger global por defecto
            spdlog::set_default_logger(async_logger);

            // Configurar el nivel mínimo de log a mostrar
            spdlog::set_level(spdlog::level::debug);
        } catch (const spdlog::spdlog_ex& ex) {

            std::cerr << "Error al inicializar el logger: " << ex.what() << std::endl;

        }

    }
    
}
