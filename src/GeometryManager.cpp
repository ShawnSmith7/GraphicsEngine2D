#include "GeometryManager.h"

GeometryManager& GeometryManager::get() {
    static GeometryManager geometryManager;
    return geometryManager;
}

std::shared_ptr<Geometry> GeometryManager::getRect() {
    size_t key = std::hash<std::string>()("rect");
    
    std::shared_ptr<Geometry> ptr = loadOrGet(key, []() {
        std::shared_ptr<Geometry> geometryPtr = std::make_shared<Geometry>();
        
        geometryPtr->vertexArray.gen();
        geometryPtr->vertexArray.bind();

        const float vertices[] = {
            -0.5f, 0.5f,
            -0.5f, -0.5f,
            0.5f, -0.5f,
            0.5f, 0.5f
        };

        geometryPtr->vertexBuffer.gen();
        geometryPtr->vertexBuffer.bind();
        geometryPtr->vertexBuffer.setData(vertices, GL_STATIC_DRAW);

        const unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
        };

        geometryPtr->indexBuffer.gen();
        geometryPtr->indexBuffer.bind();
        geometryPtr->indexBuffer.setData(indices, GL_STATIC_DRAW);

        geometryPtr->vertexArray.enableAttribute(0);
        geometryPtr->vertexArray.setAttributePointer(0, 2, GL_FLOAT, false, 2 * sizeof(float), 0);

        geometryPtr->vertexArray.unbind();

        return geometryPtr;
    });
    
    return ptr;
}

std::shared_ptr<Geometry> GeometryManager::getCircle(unsigned int resolution) {
    size_t key = std::hash<std::string>()("circle_" + resolution);

    std::shared_ptr<Geometry> ptr = loadOrGet(key, [&]() {
        std::shared_ptr<Geometry> geometryPtr = std::make_shared<Geometry>();
        
        std::vector<float> vertices(2 * (resolution + 1));
        vertices[0] = 0.0f;
        vertices[1] = 0.0f;
        float stride = 2.0f * std::numbers::pi / resolution;
        for (unsigned int i = 0; i < resolution; i++) {
            float angle = i * stride;
            vertices[2 + 2 * i] = cos(angle);
            vertices[3 + 2 * i] = sin(angle);
        }

        std::vector<unsigned int> indices(resolution + 2);
        for (unsigned int i = 0; i < resolution + 1; i++)
            indices[i] = i;
        indices[resolution + 1] = 1;

        geometryPtr->vertexArray.gen();
        geometryPtr->vertexArray.bind();

        geometryPtr->vertexBuffer.gen();
        geometryPtr->vertexBuffer.bind();
        geometryPtr->vertexBuffer.setData(vertices, GL_STATIC_DRAW);

        geometryPtr->indexBuffer.gen();
        geometryPtr->indexBuffer.bind();
        geometryPtr->indexBuffer.setData(indices, GL_STATIC_DRAW);
    
        geometryPtr->vertexArray.enableAttribute(0);
        geometryPtr->vertexArray.setAttributePointer(0, 2, GL_FLOAT, false, 2 * sizeof(float), 0);

        geometryPtr->vertexArray.unbind();

        return geometryPtr;
    });

    return ptr;
}

GeometryManager::GeometryManager() {}

std::shared_ptr<Geometry> GeometryManager::loadOrGet(size_t key, std::function<std::shared_ptr<Geometry>()> generator) {
    auto iterator = cache.find(key);
    if (iterator != cache.end())
        return iterator->second;

    std::shared_ptr<Geometry> geometryPtr = generator();
    cache[key] = geometryPtr;
    return geometryPtr;
}