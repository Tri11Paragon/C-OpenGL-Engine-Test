#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "utils/time.h"
#include "shaders/shader.h"
#include "gldata/vao.h"

void key_callback(GLFWwindow* window, int key);

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// called when user resizes the window
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE)
        glfwSetWindowShouldClose(window, true);
}

void cursor_callback(GLFWwindow* window, double xpos, double ypos){

}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){

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

int main() {
    std::cout << "Init GLFW" << std::endl;
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
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    //glfwSetWindowSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, cursor_callback);
    glfwSetScrollCallback(window, scroll_callback);

    glfwSetKeyCallback(window, key_callback);
    glfwSwapInterval(0);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int EBO;
    glGenBuffers(1, &EBO);
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    // ..:: Initialization code :: ..
    // 1. bind Vertex Array Object
    glBindVertexArray(VAO);
    // 2. copy our vertices array in a vertex buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // 3. copy our index array in a element buffer for OpenGL to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    // 4. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // 2. use our shader program when we want to render an object
    Shader base("/home/brett/CLionProjects/untitled/src/shaders/vertex.glsl", "/home/brett/CLionProjects/untitled/src/shaders/fragment.glsl");
    base.use();
    glBindVertexArray(VAO);

    vao va(vertices, indices);
    long long last = getNanoTime();
    int frames = 0;
    while(!glfwWindowShouldClose(window))
    {
        long long start = getNanoTime();
        // input
        processInput(window);

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

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

    glDeleteProgram(base.ID);

    glfwTerminate();
    return 0;
}
