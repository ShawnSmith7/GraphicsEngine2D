#pragma once

#include <memory>
#include <unordered_map>
#include <functional>
#include <string>

#include "VertexArray.h"
#include "VertexBuffer.h"

struct Geometry {
    VertexArray vertexArray;
    VertexBuffer vertexBuffer;
    unsigned int vertexCount;
};

class GeometryManager {
    public:
        static GeometryManager& get();

        std::shared_ptr<Geometry> getRect();
        std::shared_ptr<Geometry> getCircle(unsigned int resolution);
        std::shared_ptr<Geometry> getSemiCircle(unsigned int resolution);

    private:
        std::unordered_map<size_t, std::shared_ptr<Geometry>> cache;

        std::shared_ptr<Geometry> loadOrGet(size_t key, std::function<std::shared_ptr<Geometry>()> generator);
};