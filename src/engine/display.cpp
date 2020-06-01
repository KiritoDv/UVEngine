#include "gl/glew.h"

#include "GLFW/glfw3.h"
#include "engine/display.h"
#include "engine/render.h"
#include "engine/camera.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <engine/renderer/utils/IndexBuffer.h>
#include <engine/renderer/utils/VertexBuffer.h>

Display::Display(int width, int height, char *windowTitle) {
    window.width = width;
    window.height = height;
    window.title = windowTitle;
}

struct ShaderSrc{
    std::string Vertex;
    std::string Fragment;
};

static ShaderSrc ParseShader(const std::string& path){
    std::ifstream stream(path.c_str());

    enum class ShaderType {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;

    while(getline(stream, line)){
        if(line.find("#subtype") != std::string::npos){
            if(line.find("vertex") != std::string::npos){
                type = ShaderType::VERTEX;
            }else if(line.find("fragment") != std::string::npos){
                type = ShaderType::FRAGMENT;
            }
        }else{
            ss[(int)type] << line << '\n';
        }
    }

    return {ss[0].str(), ss[1].str()};
}

static unsigned int CompileShader(unsigned int type, const std::string& source){
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    if(!result){
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char * message = (char*) alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Shader Compilation Error" << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader){
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

void Display::createDisplay(int width, int height, char* title, Render* render){

    auto tmp = new Display(width, height, title);
    render->game = tmp;
    tmp->camera = new Camera();

    if(!glfwInit()){
        std::cout << "Failed to start GLFW" << std::endl;
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    tmp->window.glwindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
    glfwSetWindowTitle(tmp->window.glwindow, tmp->window.title);

    if(!tmp->window.glwindow){
        std::cout << "Failed to create window" << std::endl;
        glfwDestroyWindow(tmp->window.glwindow);
        return;
    }

    glfwSetWindowUserPointer(tmp->window.glwindow, tmp);
    glfwMakeContextCurrent(tmp->window.glwindow);

    if (glewInit()){
        std::cout << "Failed to start GLEW" << std::endl;
        glfwDestroyWindow(tmp->window.glwindow);
        return;
    }

    glfwSwapInterval(0);

    float time = 0;
    float oldTime = 0;

    //render->create();

    //tmp->updateWindowSize(width, height);
    glfwSetFramebufferSizeCallback(tmp->window.glwindow, WindowResizeCallback);
    glfwSetCursorEnterCallback(tmp->window.glwindow, MouseEnterCallback);
    glfwSetScrollCallback(tmp->window.glwindow, ScrollCallback);
    //tmp->camera->setupCamera(tmp->window.glwindow);

    float pos[] = {
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.5, 0.5f,

        -0.5f, 0.5f,
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

   unsigned int vao;
   glGenVertexArrays(1, &vao);
   glBindVertexArray(vao);

    VertexBuffer vb(pos, sizeof(pos));
    IndexBuffer(indices, 6);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, nullptr);

    ShaderSrc src = ParseShader("assets/shaders/Tile.shader");

    unsigned int shader = CreateShader(src.Vertex, src.Fragment);
    glUseProgram(shader);

    int loc = glGetUniformLocation(shader, "u_Color");
    srand(NULL);
    glUniform4f(loc, ((int)rand() % 255) / 255.0, ((int)rand() % 255) / 255.0, ((int)rand() % 255) / 255.0, 1.0);

    while(!glfwWindowShouldClose(tmp->window.glwindow)){

        //render->update();

        double xMPos, yMPos;
        glfwGetCursorPos(tmp->window.glwindow, &xMPos, &yMPos);

        time = glfwGetTime();
        tmp->graphics.deltaTime = ( time - oldTime );
        oldTime = time;

        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwSwapBuffers(tmp->window.glwindow);
        glfwPollEvents();
    }

    glDeleteProgram(shader);

    render->dispose();
    glfwDestroyWindow(tmp->window.glwindow);
    delete tmp->camera;
    delete tmp;
}

void Display::updateWindowSize(int w, int h){
    window.width = w;
    window.height = h;
    //camera->setupCamera(window.glwindow);
}
