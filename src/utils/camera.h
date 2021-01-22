//
// Created by brett on 2021-01-20.
//
#pragma once

#include "time.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <iostream>

static glm::mat4 project = glm::mat4(1.0f);

static glm::vec3 cameraPos = glm::vec3(0.0, 0.0, 3.0);
static glm::mat4 view = glm::mat4(1.0f);
static const glm::vec3 rx = glm::vec3(1.0f, 0.0f, 0.0f);
static const glm::vec3 ry = glm::vec3(0.0f, 1.0f, 0.0f);
static const glm::vec3 rz = glm::vec3(0.0f, 0.0f, 1.0f);

const float speed = 0.01f;
const float turnSpeed = 0.1f;

float moveAtW = 0.0f;
float moveAtA = 0.0f;
float moveAtY = 0.0f;

static float mx;
static float my;
static float lx;
static float ly;

float pitch = 0.0f;
float yaw = 0.0f;
float roll = 0.0f;

void move(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        moveAtW = speed * getDeltaMS();
    else
        moveAtW = 0.0;
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        moveAtW = -speed * getDeltaMS();
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        moveAtA = -speed * getDeltaMS();
    else
        moveAtA = 0.0f;
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        moveAtA = speed * getDeltaMS();
    if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        moveAtY = speed * getDeltaMS();
    else
        moveAtY = 0.0f;
    if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        moveAtY = -speed * getDeltaMS();

    pitch += (mx-lx) * turnSpeed / 100;
    yaw += (my-ly) * turnSpeed / 100;

    double dx = ((((-((moveAtW) * sin(glm::radians(yaw)))) + -((moveAtA) * cos(glm::radians(yaw))))));
    double dy = ((((moveAtW * (sin(glm::radians(roll)))) + moveAtY)));
    double dz = ((((moveAtW) * cos(glm::radians(yaw))) + -((moveAtA) * sin(glm::radians(yaw)))));

    cameraPos.x += dx;
    cameraPos.y += dy;
    cameraPos.z += dz;

    view = glm::translate(glm::mat4(1.0f), cameraPos);
    view = glm::rotate(view, pitch, ry);
    view = glm::rotate(view, yaw, rx);

}
