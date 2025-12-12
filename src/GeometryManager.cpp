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
        geometryPtr->vertexCount = 4;

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