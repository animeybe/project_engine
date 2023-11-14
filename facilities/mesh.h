#pragma once

#include "service/modelloader.cpp"
#include "shader.h"
#include "camera.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "index_buffer.h"


class Mesh { // Mesh - Полигональная сетка (Mesh — набор вершин и треугольников)

public:
    GLuint size;

    Mesh(const GLchar* obj_path) {

        ///////////////////////
        Vertex vertex = loadOBJ(obj_path); // Объект
        size = GLuint(vertex.indexes.size());
        ///////////////////////

        ///////////////////////
		vertex_buffer vertices(vertex.vertices);
        vertices.Bind();
        vao.Bind();
        vao.AttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        ///////////////////////

        ///////////////////////
        vertex_buffer uvs(vertex.uvs);
        uvs.Bind();
        vao.Bind();
        vao.AttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        ///////////////////////

        ///////////////////////
        vertex_buffer normals(vertex.normals);
        normals.Bind();
        vao.Bind();
        vao.AttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        ///////////////////////

        ///////////////////////
        index_buffer indexes(vertex.indexes);
        indexes.Bind();
        vao.Bind();
        ///////////////////////

	}

    //Отрисовка
    void Draw(Shader shader, camera& camera, glm::vec3 position) {

        // Юзаем Шейдеры
        shader.Use();
        shader.SetMat4("view", camera.GetViewMatrix());
        shader.SetMat4("projection", camera.GetProjectionMatrix());
        ///////////////////////

        // Собираем объект
        vao.Bind();
        glm::mat4 model(1.0f);
        model = glm::translate(model, position);
        shader.SetMat4("model", model);
        glDrawElements(
            GL_TRIANGLES,      
            size,    
            GL_UNSIGNED_SHORT,   
            (void*)0           
        );
        ///////////////////////
    }

    // Отрисовка движений объектов
    void Draw(Shader shader, camera& camera, glm::vec3 position, float angle, glm::vec3 rotate) {

        // Юзаем Шейдеры
        shader.Use();
        shader.SetMat4("view", camera.GetViewMatrix());
        shader.SetMat4("projection", camera.GetProjectionMatrix());
        ///////////////////////

        // Собираем объект
        vao.Bind();
        glm::mat4 model(1.0f);
        model = glm::translate(model, position);
        model = glm::rotate(model, angle, rotate);
        shader.SetMat4("model", model);
        glDrawElements(
            GL_TRIANGLES,     
            size,    
            GL_UNSIGNED_SHORT,   
            (void*)0           
        );
        ///////////////////////
    }

private:
    Vertex_array vao;
};