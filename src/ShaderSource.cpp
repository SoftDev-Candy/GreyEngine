//
// Created by Candy on 11/21/2025.
//

#include "ShaderSource.hpp"

//This is like tiny C functions the language is called GLSL
const char* VertexShaderSource = R"(
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aUV;
out vec2 vUV;

uniform mat4 MVP; //allows us to send model X view X projection from C++

void main() {
vUV = aUV;
    gl_Position =MVP* vec4(aPos, 1.0);
}
)";

const char* FragmentShaderSource = R"(
#version 330 core
out vec4 FragColor;

in vec2 vUV;

uniform sampler2D uTexture;

void main() {
    FragColor = texture(uTexture,vUV);
}
)";
