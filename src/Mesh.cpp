//
// Created by Candy on 12/11/2025.
//

#include "Mesh.hpp"

Mesh::Mesh(float *vertices, size_t vertSize, unsigned int *indices, size_t indexCount)
{
    this->indexCount = indexCount;
    //Create VAO Here //
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //Generate VBO
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER , VBO);
    glBufferData(GL_ARRAY_BUFFER,vertSize*sizeof(float),vertices,GL_STATIC_DRAW);

    //Generate the EBO
    glGenBuffers(1,&EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,indexCount*sizeof(unsigned int),indices,GL_STATIC_DRAW);

    //lets openGl know how to read to our data//
    glVertexAttribPointer(
        0, // attribute location 0 in shader
        3, // 3 components per vertex
        GL_FLOAT, // type
        GL_FALSE, // no normalization
        5 * sizeof(float), // stride (size of each vertex)
        (void *) 0 // offset (start of buffer)
    );
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(
       1, // attribute location 1 in shader
       2, // 2 components per vertex
       GL_FLOAT, // type
       GL_FALSE, // no normalization
       5 * sizeof(float), // stride (size of each vertex)
       (void *) (3 * sizeof(float)) // offset (start of buffer)
   );
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,0);

}

void Mesh::Bind()
{
glBindVertexArray(VAO);
}

unsigned int Mesh::GetIndexCount() const
{
    return indexCount;
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    glDeleteBuffers(1, &EBO);

}
