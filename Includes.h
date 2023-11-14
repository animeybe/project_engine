#pragma once

#include <iostream>
#include <string>
#include <ctime>

//glew
#include <GL/glew.h>

//sfml
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

//imgui
#include <imgui/imgui.h>
#include <imgui/imgui-SFML.h>

//glm
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

inline int WIDTH = 1920; // Ширина
inline int HEIGHT = 1080; // Высота

inline glm::vec3 ambient(0.2f, 0.2f, 0.2f); // Фоновый (Окружающий)
inline glm::vec3 diffuse(0.5f, 0.5f, 0.5f); // Рассеяный
inline glm::vec3 specular(1.0f, 1.0f, 1.0f); // Отражённый (Блик)

inline float constant = 1.0f;
inline float linear = 0.09f;
inline float quadratic = 0.032f;
inline float shininess = 32.0f; // Сила блеска

struct Vertex { // Набор вершин

	std::vector< glm::vec3 > vertices; // Вершины
	std::vector< glm::vec2 > uvs; // UV-координаты
	std::vector< glm::vec3 > normals; // Нормали
	std::vector< unsigned short > indexes; // Индексы

};