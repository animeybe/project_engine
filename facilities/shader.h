#pragma once
#include "service/shaderloader.cpp"

// Описыаем шейдеры
class Shader
{
public:
    GLuint id;
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath) {
        this->id = LoadShaders(vertexPath, fragmentPath); // Загрузка шейдера
    }

    void Use() { // Использование шейдера
        glUseProgram(this->id);
    }

    void SetMat4(std::string type, const glm::mat4& mat) { // Передача юниформов в шейдеры
        glm::mat4 res = glm::mat4(mat);
        glUniformMatrix4fv(glGetUniformLocation(id, type.c_str()), 1, GL_FALSE, &res[0][0]);
    }

    void SetVec3(const std::string unif, const glm::vec3& data) { // Передача юниформов в шейдеры
        glm::vec3 res = glm::vec3(data.x, data.y, data.z);
        glUniform3fv(glGetUniformLocation(id, unif.c_str()), 1, &res[0]);
    }

    void SetInt(const std::string unif, int data) { // Передача юниформов в шейдеры
        glUniform1i(glGetUniformLocation(id, unif.c_str()), data);
    }

    void SetFloat(const std::string unif, float data) { // Передача юниформов в шейдеры
        glUniform1f(glGetUniformLocation(id, unif.c_str()), data);
    }



};