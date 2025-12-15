#pragma once

#include <memory>
#include <unordered_map>
#include <functional>

#include "Geometry.h"

class GeometryManager {
    public:
        GeometryManager(const GeometryManager& geometryManager) = delete;

        static GeometryManager& get();

        std::shared_ptr<IndexedGeometry> getRect();
        std::shared_ptr<IndexedGeometry> getCircle(unsigned int resolution);
        std::shared_ptr<Geometry> getSemiCircle(unsigned int resolution, float arc);
        std::shared_ptr<Geometry> getLine();
    private:
        GeometryManager();

        std::unordered_map<size_t, std::shared_ptr<Geometry>> cache;

        template<typename T>
        std::shared_ptr<T> loadOrGet(size_t key, std::function<std::shared_ptr<T>()> generator) {
            auto iterator = cache.find(key);
            if (iterator != cache.end())
                return std::static_pointer_cast<T>(iterator->second);

            std::shared_ptr<T> geometryPtr = generator();
            cache[key] = geometryPtr;
            return geometryPtr;
        }
};