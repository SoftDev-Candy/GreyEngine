//
// Created by Candy on 12/7/2025.
//

#include "Texture.hpp"

#include <iostream>

#include "stb_image.h"
#define STB_IMAGE_IMPLEMENTATION
//RAII is very important although could've named it literally anything else ...resource allocation is initailzation...WDUM<???//
Texture::Texture(const char *path)
{
    int height;
    int width;
    int channels;

  unsigned char* storedata =  stbi_load(path , &width , &height, &channels,0);

        if(storedata == NULL)
        {
            std::cerr<<"The data for texture was NULL "<<std::endl;
        }
}

Texture::~Texture()
{

}
