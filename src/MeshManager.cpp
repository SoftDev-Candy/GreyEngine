//
// Created by Candy on 1/3/2026.
//
#include "MeshManager.hpp"
#include<utility>

Mesh * MeshManager::Add(const std::string key, std::unique_ptr<Mesh> mesh)
{
    //1. To be safe lets not overwrite in mem just find it and if it exists return//
    auto it = meshes.find(key);
    if (it != meshes.end())
    {
        return it->second.get();
    }
//2. Store it

    meshes.emplace(key,std::move(mesh));

//3.Return the RAWWWWWWR pointer to the stored mesh//
    return meshes.at(key).get();

}

Mesh * MeshManager::Get(const std::string &key)
{
    auto it = meshes.find(key);
    if (it == meshes.end())
    {
        return nullptr;
    }

    return it->second.get();

}

bool MeshManager::Has(const std::string &key) const
{

    return meshes.find(key) != meshes.end();

}
