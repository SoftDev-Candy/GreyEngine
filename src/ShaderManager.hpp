//
// Created by Candy on 12/14/2025.
//

#ifndef B_WENGINE_SHADERMANAGER_HPP
#define B_WENGINE_SHADERMANAGER_HPP
#include <unordered_map>
#include <string>
class Shader;

class ShaderManager
{
public:
    ShaderManager();
    void LoadShader(std::string shaderName, const char* vertexSrc , const char* fragmentSrc);
    Shader* GetShader(std::string shaderName)const;
    ~ShaderManager();

private:
    std::unordered_map<std::string , Shader*> shaderMap;
};


#endif //B_WENGINE_SHADERMANAGER_HPP