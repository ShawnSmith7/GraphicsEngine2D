#include "GeometryManager.h"

GeometryManager& GeometryManager::get() {
    static GeometryManager geometryManager;
    return geometryManager;
}

std::shared_ptr<Geometry> GeometryManager::getRect() {
    size_t key = std::hash<std::string>()("rect");

    std::shared_ptr<Geometry> geometryPtr = loadOrGet(key, []() {
        std::shared_ptr<Geometry> geometry = std::make_shared<Geometry>();

        float vertices[] = {
            -0.5f, 0.5f,
            -0.5f, -0.5f,
            0.5f, -0.5f,
            0.5f, 0.5f
        };

        geometry->vertexArray.gen();
        geometry->vertexArray.bind();

        geometry->vertexBuffer.gen();
        geometry->vertexBuffer.bind();
        geometry->vertexBuffer.setData(vertices, sizeof(vertices));

        geometry->vertexArray.enableAttribute(0);
        geometry->vertexArray.setAttributePointer(0, 2, GL_FLOAT, false, 2 * sizeof(float), 0);

        geometry->vertexCount = 4;
        return geometry;
    });

    return { geometryPtr };
}

std::shared_ptr<Geometry> GeometryManager::getCircle(unsigned int resolution) {
    // temp
    std::shared_ptr<Geometry> geometry = std::make_shared<Geometry>();
    return geometry;
}

std::shared_ptr<Geometry> GeometryManager::getSemiCircle(unsigned int resolution) {
    // temp
    std::shared_ptr<Geometry> geometry = std::make_shared<Geometry>();
    return geometry;
}

std::shared_ptr<Geometry> GeometryManager::loadOrGet(size_t key, std::function<std::shared_ptr<Geometry>()> generator) {
    auto iterator = cache.find(key);
    if (iterator != cache.end())
        return iterator->second;

    std::shared_ptr<Geometry> geometry = generator();
    cache[key] = geometry;
    return geometry;
}