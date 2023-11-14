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

inline int WIDTH = 1920; // ������
inline int HEIGHT = 1080; // ������

inline glm::vec3 ambient(0.2f, 0.2f, 0.2f); // ������� (����������)
inline glm::vec3 diffuse(0.5f, 0.5f, 0.5f); // ���������
inline glm::vec3 specular(1.0f, 1.0f, 1.0f); // ��������� (����)

inline float constant = 1.0f;
inline float linear = 0.09f;
inline float quadratic = 0.032f;
inline float shininess = 32.0f; // ���� ������

struct Vertex { // ����� ������

	std::vector< glm::vec3 > vertices; // �������
	std::vector< glm::vec2 > uvs; // UV-����������
	std::vector< glm::vec3 > normals; // �������
	std::vector< unsigned short > indexes; // �������

};