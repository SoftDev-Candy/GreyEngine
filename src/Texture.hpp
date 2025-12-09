//
// Created by Candy on 12/7/2025.
//

#ifndef B_WENGINE_TEXTURE_HPP
#define B_WENGINE_TEXTURE_HPP

#include"glad/glad.h"


class Texture
{
public:
    Texture(const char* path);
    void Bind(int bind_id);
    GLuint id;

    ~Texture();

};


#endif //B_WENGINE_TEXTURE_HPP