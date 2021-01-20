//
// Created by brett on 2021-01-19.
//
#pragma once
#include <iostream>
#include <glad/glad.h>

#ifndef UNTITLED_VAO_H
#define UNTITLED_VAO_H

class vao {
public:
    // main vao
    unsigned int VAO_ID;
    // indices
    unsigned int EBO_ID;
    // vertex vbo
    unsigned int VERTEX_ID;
    vao(float vertex_data[], unsigned int indices[], int vertex_length, int indices_length){
        //create vertex array
        glGenVertexArrays(1, &VAO_ID);
        glGenBuffers(1, &EBO_ID);
        glGenBuffers(1, &VERTEX_ID);

        glBindVertexArray(VAO_ID);
        // bind in indices
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_ID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_length, indices, GL_STATIC_DRAW);
        // bind in vertices
        glBindBuffer(GL_ARRAY_BUFFER, VERTEX_ID);
        glBufferData(GL_ARRAY_BUFFER, vertex_length, vertex_data, GL_STATIC_DRAW);
        // attribute number, coordinate size, type, normalized, stride, offset
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        //unbind the vertex array;
        glBindVertexArray(0);
    }
    void use(){
        glBindVertexArray(VAO_ID);
        glEnableVertexAttribArray(0);
    }
    void bind(){
        glBindVertexArray(VAO_ID);
    }
    void unbind(){
        glBindVertexArray(0);
    }
    void unuse(){
        glDisableVertexAttribArray(0);
        glad_glBindVertexArray(0);
    }
    ~vao(){

    }
};


#endif //UNTITLED_VAO_H
