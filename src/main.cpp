#include <iostream>
#include <filesystem>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "utils/time.h"
#include "shaders/shader.h"
#include "gldata/vao.h"
#include "gldata/image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "utils/camera.h"

Shader base;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// called when user resizes the window
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    project = glm::perspective(glm::radians(90.0f), (float)width/(float)height, 0.1f, 1000.0f);
    base.setProjectionMatrix(project);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
        glfwSetInputMode(window, GLFW_CURSOR, glfwGetInputMode(window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED);
}

void cursor_callback(GLFWwindow* window, double xpos, double ypos){

}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){

}

void mouse_callback(GLFWwindow* window, double mouseX, double mouseY){
    mx = mouseX;
    my = mouseY;
}

void processInput(GLFWwindow *window)
{
    //if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    //    glfwSetWindowShouldClose(window, true);
}

float vertices[] = {
        0.5f,  0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left
};
unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
};
float texCoords[] = {
        1.0f, 1.0f,   // top right
        1.0f, 0.0f,   // bottom right
        0.0f, 0.0f,   // bottom left
        0.0f, 1.0f    // top left
};

int main() {
    std::cout << "Init GLFW" << std::endl;
    std::cout << std::filesystem::current_path() << std::endl;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    int width = 800;
    int height = 600;

    GLFWwindow* window = glfwCreateWindow(width, height, "LearnC++", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glViewport(0, 0, width, height);
    project = glm::perspective(glm::radians(90.0f), (float)width/(float)height, 0.1f, 1000.0f);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    //glfwSetWindowSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, cursor_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetCursorPosCallback(window, mouse_callback);

    glfwSetKeyCallback(window, key_callback);
    glfwSwapInterval(0);

    // 2. use our shader program when we want to render an object
    base = Shader("/home/brett/CLionProjects/untitled/src/shaders/vertex.glsl", "/home/brett/CLionProjects/untitled/src/shaders/fragment.glsl");
    base.use();
    base.setProjectionMatrix(project);
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::scale(trans, glm::vec3(5, 5, 5));
    trans = glm::translate(trans, glm::vec3(0, 0, -1));
    base.setTransformationMatrix(trans);

    vao va(vertices, texCoords, indices, sizeof(vertices), sizeof(texCoords), sizeof(indices));
    image img("/home/brett/CLionProjects/untitled/src/res/bluestone.png");
    img.use();
    va.use();

    long long last = getNanoTime();
    int frames = 0;
    while(!glfwWindowShouldClose(window))
    {
        long long start = getNanoTime();
        // input
        processInput(window);
        // move the camera
        move(window);
        // update all shader view matrix
        base.setViewMatrix(view);
        lx = mx;
        ly = my;

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, va.size, GL_UNSIGNED_INT, 0);

        // glfw stuff
        glfwSwapBuffers(window);
        glfwPollEvents();
        long long stop = getNanoTime();
        frames++;
        setDelta(stop - start);
        if (stop - last > 1000000000){
            std::cout << "FPS: " << frames << " DELTA: " << getDeltaMS() << std::endl;
            frames = 0;
            last = getNanoTime();
        }
    }

    glfwTerminate();
    return 0;
}
