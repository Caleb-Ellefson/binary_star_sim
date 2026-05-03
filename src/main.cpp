#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define WIDTH 640
#define HEIGHT 480

float vertices[] = {
    // First triangle
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f,  0.5f, 0.0f,  // top left 
};

float vertices1[] = {
    // Second triangle
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left
};

// Vertex Shader source code
const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

// Fragment shader source code shader
const char *fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
    "FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\0";

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

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to init glad" << std::endl;
        return -1;
    }

    unsigned int VAO;
    // Generate vertex
    glGenVertexArrays(1, &VAO);
    // Bind it 
    glBindVertexArray(VAO);

    // Create Vertex buffer object
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    // Bind buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // Copy our data into the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Create Second VBO & VAO
    unsigned int VAO1;
    glGenVertexArrays(1, &VAO1);
    glBindVertexArray(VAO1);

    // Create Vertex buffer object
    unsigned int VBO1;
    glGenBuffers(1, &VBO1);
    // Bind buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
    // Copy our data into the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    // Enable the vertex attributes
    glEnableVertexAttribArray(0);


    // Vertex Shader
    unsigned int vertexShader;
    // Define shader type GL_VERTEX_SHADER
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // Create shader from shader source code
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int  success;
    char infoLog[512];
    // Check if compilation is sucessful
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        // Print error message
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Fragment Shader
    unsigned int fragmentShader;
    // Define shader type GL_FRAGMENT_SHADER
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // Build it from fragment shader source
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Create shader program to link fragment and vertex shader together
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();

    // Attach both shaders
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    // Link both shaders
    glLinkProgram(shaderProgram);
    // Check status
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::FRAGMENT::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;

    }
    // If success use them
    glUseProgram(shaderProgram);
    // No longer need indivudal shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    while (!glfwWindowShouldClose(window)) 
    {
        glfwPollEvents();
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        // Draw triangle 1
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // Drawe Triangle 2
        glBindVertexArray(VAO1);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
    }

    return 0;
}