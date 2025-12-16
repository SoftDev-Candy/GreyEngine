//
// Created by Candy on 12/14/2025.
//

#include "ShaderManager.hpp"
#include "Shader.hpp"

ShaderManager::ShaderManager()
{

}

void ShaderManager::LoadShader(std::string shaderName, const char *vertexSrc, const char *fragmentSrc)
{
if (shaderMap.find(shaderName)!= shaderMap.end())
{
return;
}

shaderMap[shaderName] = new Shader(vertexSrc,fragmentSrc);

}

Shader* ShaderManager::GetShader(std::string shaderName) const
{
    auto it = shaderMap.find(shaderName);
    if (it == shaderMap.end())
    {
        return nullptr;
    }
    else
        {
            return it->second;
        }
}

ShaderManager::~ShaderManager()
{
for (auto& it : shaderMap)
{
    delete it.second;
}
    shaderMap.clear();
}
