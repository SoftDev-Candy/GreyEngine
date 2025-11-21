//
// Created by Candy on 11/18/2025.
//

#ifndef B_WENGINE_TRIANGLE_HPP
#define B_WENGINE_TRIANGLE_HPP

#include "Renderable.hpp"
#include "Shader.hpp"
#include<glad/glad.h>



class Triangle : public Renderable
{
public:
     Triangle();
    ~Triangle();

    void Render() override;


private:

    unsigned int VAO{};
    unsigned int VBO{};
    Shader shader;

};


#endif //B_WENGINE_TRIANGLE_HPP