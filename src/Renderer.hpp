//
// Created by Candy on 11/21/2025.
//

#ifndef B_WENGINE_RENDER_HPP
#define B_WENGINE_RENDER_HPP
#include "Scene.hpp"
#include "Camera.hpp"
#include "Shader.hpp"

class Renderer
{
public:

    void Begin();
    void RenderScene(Scene& scene , Camera& cam);
    void SetActiveShader(Shader *s) ;
private:
    Shader* shaderptr = nullptr;

};


#endif //B_WENGINE_RENDER_HPP