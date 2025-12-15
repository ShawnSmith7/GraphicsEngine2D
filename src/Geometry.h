#pragma once

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