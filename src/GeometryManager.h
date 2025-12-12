#pragma once

#include <memory>
#include <unordered_map>
#include <functional>
#include <string>
#include <numbers>
#include <cmath>

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

struct Geometry {
    VertexArray vertexArray;
    VertexBuffer vertexBuffer;
    IndexBuffer indexBuffer;
};

class GeometryManager {
    public:
        GeometryManager(const GeometryManager& geometryManager) = delete;

        static GeometryManager& get();

        std::shared_ptr<Geometry> getRect();
        std::shared_ptr<Geometry> getCircle(unsigned int resolution);
    private:
        GeometryManager();

        std::unordered_map<size_t, std::shared_ptr<Geometry>> cache;

        std::shared_ptr<Geometry> loadOrGet(size_t key, std::function<std::shared_ptr<Geometry>()> generator);
};