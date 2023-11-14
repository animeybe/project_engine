#pragma once

#include <memory>
#include "shader.h"
#include "camera.h"
#include "vertex_array.h"
#include "vertex_buffer.h"

// Опищем класс скайбоксов
class Skybox {

public:

	///////////////////////
	int size;
	///////////////////////

	///////////////////////
	Skybox(Shader shader) {
		float vertices[] = { // Вершины
			-1.0f, 1.0f, -1.0f,
			-1.0f, 1.0f, 1.0f,
			1.0f, 1.0f, -1.0f,
			1.0f, 1.0f, 1.0f,

			-1.0f, -1.0f, -1.0f,
			-1.0f, -1.0f, 1.0f,
			1.0f, -1.0f, -1.0f,
			1.0f, -1.0f, 1.0f,
		};

		unsigned short indices[] = { // Индексы
			0, 1, 2,
			1, 2, 3,

			4, 5, 6,
			5, 6, 7,

			0, 1, 5,
			0, 4, 5,

			2, 3, 7,
			2, 6, 7,

			0, 2, 6,
			0, 4, 6,

			1, 5, 7,
			1, 3, 7
		};
		///////////////////////
		vertex_buffer vbo(vertices, sizeof(vertices) / sizeof(float));
		vbo.Bind();
		vao.Bind();
		vao.AttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		unsigned int ebo;
		///////////////////////
		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
		///////////////////////
		shader.Use();
		shader.SetInt("skybox", 0);
		///////////////////////
	}
	///////////////////////

	// Отрисовка
	void Draw(Shader shader, camera& camera) {

		///////////////////////
		glDepthFunc(GL_LEQUAL);
		shader.Use();
		glm::mat4 view = glm::rotate(camera.ViewForSkybox(), glm::radians(180.f), { 0.f, 0.f, 1.f });
		shader.SetMat4("view", view);
		shader.SetMat4("projection", camera.GetProjectionMatrix());
		///////////////////////
		vao.Bind();
		glm::mat4 model(1.0f);
		shader.SetMat4("model", model);
		///////////////////////
		glDrawElements(
			GL_TRIANGLES,      
			36,    
			GL_UNSIGNED_SHORT,   
			(void*)0           
		);
		///////////////////////
		glDepthFunc(GL_LESS);
		///////////////////////
	}
	///////////////////////

private:
	Vertex_array vao;
};