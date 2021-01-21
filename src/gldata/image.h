//
// Created by brett on 2021-01-19.
//
#pragma once
#include <iostream>
#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#ifndef UNTITLED_IMAGE_H
#define UNTITLED_IMAGE_H


class image {
public:
    unsigned int TEXTURE_ID;
    image(const char *file){
        glGenTextures(1, &TEXTURE_ID);
        glBindTexture(GL_TEXTURE_2D, TEXTURE_ID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char *data = stbi_load(file, &width, &height, &nrChannels, 0);
        if (data) {
            if (nrChannels > 3)
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            else
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            std::cout << "Failed to load texture: " << file << std::endl;
        }
        stbi_image_free(data);
    }
    void use(){
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, TEXTURE_ID);
    }
    void unbind(){
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    void cull(){
        glEnable(GL_CULL_FACE);
    }
    void nocull(){
        glDisable(GL_CULL_FACE);
    }
    ~image(){

    }
};


#endif //UNTITLED_IMAGE_H
