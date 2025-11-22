//
// Created by Candy on 11/18/2025.
//

#include "Triangle.hpp"
#include "ShaderSource.hpp"


Triangle::Triangle() : shader(VertexShaderSource,FragmentShaderSource)
{
    //MAKE A TRIANGLE HERE NOW //
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
    };

    //Doing the VAO HERE
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //Doing the VBO in here
    glGenBuffers(1, &VBO); //Assigns an id to the buffer and creates it .
    glBindBuffer(GL_ARRAY_BUFFER, VBO); //Anything I upload will go into this buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    //Take my floats and add it to GPU memory.

    //lets openGl how to read to our data//
    glVertexAttribPointer(
        0, // attribute location 0 in shader
        3, // 3 components per vertex
        GL_FLOAT, // type
        GL_FALSE, // no normalization
        3 * sizeof(float), // stride (size of each vertex)
        (void *) 0 // offset (start of buffer)
    );
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_VERTEX_ARRAY,0);
    glBindVertexArray(0);

    //VAO IS COMPLETELY SETUP HERE//
}

Triangle::~Triangle()
{
glDeleteVertexArrays(1,&VAO);
glDeleteBuffers(1,&VBO);
}

void Triangle::Render()
{
    shader.bind();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES,0,3);
}
