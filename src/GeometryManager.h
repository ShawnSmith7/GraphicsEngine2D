#pragma once

#include <memory>

#include "VertexArray.h"
#include "VertexBuffer.h"

struct Geometry {
    VertexArray vertexArray;
    VertexBuffer vertexBuffer;
    unsigned int vertexCount;
};

class GeometryManager {
    public:
        GeometryManager(const GeometryManager& geometryManager) = delete;

        static GeometryManager& get();

        std::shared_ptr<Geometry> getRect();
    private:
        GeometryManager();
};