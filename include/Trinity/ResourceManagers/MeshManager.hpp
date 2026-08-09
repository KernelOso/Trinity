#pragma once

// ✦ . ──────────────────────────────── .✦
// ECS
    #include "Trinity/ResourceManager.hpp"
    #include "Trinity/Components/MeshComponent.hpp"
    #include "Trinity/ResourceLoaders/MeshLoader.hpp"

namespace Trinity::ResourceManagers {

    struct MeshManager : ResourceManager<Components::MeshResource> {
        MeshManager() : ResourceManager(ResourceLoaders::meshLoader) {}
    };

}
