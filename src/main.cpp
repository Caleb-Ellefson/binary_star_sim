#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define WIDTH 640
#define HEIGHT 480

int main () {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, " MyWindow" , NULL, NULL);

    if (window == NULL) {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
{
 
    glfwSwapBuffers(window);
    glfwPollEvents();
}


    return 0;
}