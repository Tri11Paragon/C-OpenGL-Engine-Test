//
// Created by brett on 2021-01-20.
//
#pragma once

#ifndef UNTITLED_CAMERA_H
#define UNTITLED_CAMERA_H

static glm::mat4 project = glm::mat4(1.0f);
static glm::vec3 cameraPos = glm::vec3(0.0, 0.0, -1.0);
static glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
static glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
static const glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
static glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
static glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);



#endif //UNTITLED_CAMERA_H
