//
// Created by Candy on 11/20/2025.
//

#ifndef B_WENGINE_SCENE_HPP
#define B_WENGINE_SCENE_HPP
#include <string>
#include <vector>
#include "Entity.hpp"
#include "MeshComponent.hpp"
#include"Transform.hpp"

struct SceneObject
{
    Entity entity;
    Transform transform;
    MeshComponent mesh;
    std::string name = "Unnamed";

};


class Scene
{
public:

Entity CreateObject()
{
        Entity e {nextId++ };
        SceneObject obj;
        obj.entity = e;
        objects.push_back(obj);
        return e;
}

    std::vector<SceneObject>& GetObjects()
    {
        return objects;
    }

private:

    std::vector<SceneObject>objects;
    EntityID nextId = 1;

};

#endif //B_WENGINE_SCENE_HPP