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
};

struct IndexedGeometry : public Geometry {
    IndexBuffer indexBuffer;
};

class GeometryManager {
    public:
        GeometryManager(const GeometryManager& geometryManager) = delete;

        static GeometryManager& get();

        std::shared_ptr<IndexedGeometry> getRect();
        std::shared_ptr<IndexedGeometry> getCircle(unsigned int resolution);
        std::shared_ptr<Geometry> getSemiCircle(unsigned int resolution, float arc);
    private:
        GeometryManager();

        std::unordered_map<size_t, std::shared_ptr<Geometry>> cache;

        template<typename T>
        std::shared_ptr<T> loadOrGet(size_t key, std::function<std::shared_ptr<T>()> generator);
};