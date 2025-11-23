//
// Created by Candy on 11/22/2025.
//

#ifndef B_WENGINE_CUBE_HPP
#define B_WENGINE_CUBE_HPP
#include"Renderable.hpp"
#include "Shader.hpp"
#include <glad/glad.h>

class Cube
{
public:

    Cube();//Constructor big man //
    ~Cube();//No so constructor//

    void Render()override;

private:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;

Shader shader;


};


#endif //B_WENGINE_CUBE_HPP