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
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int width, height, nrChannels;
        unsigned char *data = stbi_load(file, &width, &height, &nrChannels, 0);
        if (data) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            std::cout << "Failed to load texture: " << file << std::endl;
        }
        stbi_image_free(data);
    }
    ~image(){
        glDeleteTextures(1, &TEXTURE_ID);
    }
};


#endif //UNTITLED_IMAGE_H
