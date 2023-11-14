#pragma once

#include "facilities/func.h"
#include "facilities/texture.h"
#include "facilities/mesh.h"
#include "facilities/camera.h"
#include "facilities/skybox.h"


///////////////////////
using namespace std;
///////////////////////


int main() {
	// Установка window, glew, imgui //////////////////////////////////////////////
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT, 32), "First Window",
		sf::Style::Titlebar | sf::Style::Close, default_settings());

	///////////////////////
	window.setVerticalSyncEnabled(true); // Вертикальная синхронизация
	window.setActive();                  // Активирует контекст окна
	///////////////////////

	glewExperimental = GL_TRUE; // Позволяет GLEW использовать новейшие техники для управления функционалом OpenGL

	if (GLEW_OK != glewInit()) {  // Инит Glew
		cout << "Error:: glew not init =(" << endl;
		return -1;
	}

	///////////////////////
	glEnable(GL_DEPTH_TEST); // Проверка глубины
	glDepthFunc(GL_LESS);    // Проверка глубины
	///////////////////////

	ImGui::SFML::Init(window); // Инит окна

	///////////////////////////////////////////////////////////////////////////////

	Shader cube("shaders/texture.vs", "shaders/texture.fs"); // Шейдеры объектов
	Shader light("shaders/point.vs", "shaders/point.fs");    // Шейдеры света

	Texture cube_texture("images/1.jpg"); // Текустура кубов

	cube.Use(); // Подключаем шейдеры
	cube.SetInt("material.diffuse", 1);
	cube.SetInt("material.specular", 1);
	///////////////////////
	Shader skybox_shader("shaders/skybox/skybox.vs", "shaders/skybox/skybox.fs"); // Путь к шейдерам скайбокса
	std::string path = "images/skybox/"; // Путь к текстуре скайбоксов

	std::vector<std::string> skybox_textures{ // Текстуры скайбоксов
		path + "right.jpg",
		path + "left.jpg",
		path + "down.jpg",
		path + "up.jpg",
		path + "front.jpg",
		path + "back.jpg"
	};
	Texture sky(skybox_textures); // Текстуры скайбоксов

	skybox_shader.Use(); // Подключаем шейдеры
	skybox_shader.SetInt("skybox",0);
	Skybox skybox(skybox_shader); // Создаём скайбокс
	///////////////////////
	Mesh box("models/box.obj");
	Mesh cylinder("models/cylinder.obj");

	///////////////////////

	camera camera; // Запуск камеры

	///////////////////////

	glm::mat4 projection = glm::perspective(glm::radians(45.0f), static_cast<float>(WIDTH) / static_cast<float>(HEIGHT), 0.1f, 1000.0f);
	cube.SetMat4("projection", projection); // Матрица проекции
	
	//glm::vec3 lamp(1.2f, 0.0f, 2.0f); // Расположение лампы 1

	glm::vec3 lamp_two(1.0f, 0.0f, -5.0f); // Расположение лампы 2

	///////////////////////

	sf::Color bgColor;
	float color[3] = { 0.f, 0.f, 0.f };
	sf::Clock deltaClock;
	float coeff = 0;
	bool isGo = true;
	while (isGo) {
		sf::Event windowEvent;
		while (window.pollEvent(windowEvent)) {

			switch (windowEvent.type)
			{
			case sf::Event::Closed:
				isGo = false;
				break;
			case sf::Event::KeyPressed:
				camera.KeyboardInput();
				break;
			case sf::Event::MouseMoved:
				camera.update_view(window);
				break;
			default:
				break;
			}
		}
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f); 
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		///////////////////////////////////////////////////////////////////// Работа со светом

		cube.Use();
		cube.SetVec3("viewPos", camera.GetPos());
		cube.SetFloat("material.shininess", shininess);

		/////////////////////// Внешний свет (Направленный)
		cube.SetVec3("dirLight.direction", glm::vec3(-0.2f, -1.0f, -0.3f));
		cube.SetVec3("dirLight.ambient", glm::vec3(0.05f, 0.05f, 0.05f));
		cube.SetVec3("dirLight.diffuse", glm::vec3(0.4f, 0.4f, 0.4f));
		cube.SetVec3("dirLight.specular", glm::vec3(0.5f, 0.5f, 0.5f));
		///////////////////////

		/////////////////////// Лампы (Точечный источник)
		//cube.SetVec3("pointLights[0].position", lamp * 1.f);
		cube.SetVec3("pointLights[0].ambient", glm::vec3(0.05f, 0.05f, 0.05f)*30.f);
		cube.SetVec3("pointLights[0].diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
		cube.SetVec3("pointLights[0].specular", specular);
		cube.SetFloat("pointLights[0].constant", constant);
		cube.SetFloat("pointLights[0].linear", linear);
		cube.SetFloat("pointLights[0].quadratic", quadratic);

		cube.SetVec3("pointLights[1].position", lamp_two*1.f);
		cube.SetVec3("pointLights[1].ambient", glm::vec3(0.05f, 0.05f, 0.05f));
		cube.SetVec3("pointLights[1].diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
		cube.SetVec3("pointLights[1].specular", specular);
		cube.SetFloat("pointLights[1].constant", constant);
		cube.SetFloat("pointLights[1].linear", linear);
		cube.SetFloat("pointLights[1].quadratic", quadratic);
		///////////////////////

		/////////////////////// Прожектор
		cube.SetVec3("spotLight.position", camera.GetPos());
		cube.SetVec3("spotLight.direction", camera.GetFront());
		cube.SetVec3("spotLight.ambient", glm::vec3(0.0f, 0.0f, 0.0f));
		cube.SetVec3("spotLight.diffuse", glm::vec3(1.0f, 1.0f, 1.0f));
		cube.SetVec3("spotLight.specular", specular);
		cube.SetFloat("spotLight.constant", constant);
		cube.SetFloat("spotLight.linear", linear);
		cube.SetFloat("spotLight.quadratic", quadratic);
		cube.SetFloat("spotLight.cutOff", cos(glm::radians(12.5f)));
		cube.SetFloat("spotLight.outerCutOff", cos(glm::radians(15.0f)));
		///////////////////////////////////////////////////////////////////// Работа со светом
		
		///////////////////////////////////////////////////////////////////// Отрисовка объектов
		//box.Draw(light, camera, lamp*1.f);
		box.Draw(light, camera, lamp_two*1.f);

		box.Draw(cube, camera, { 5.f, 0.f, -5.f });

		box.Draw(cube, camera, { 15.f, 0.f, -5.f }, -coeff, { 0.f, 5.f, 0.f });

		box.Draw(cube, camera, { 25.f, sin(coeff /30.f)*10.f, -5.f}, -coeff, {1.f, 0.f, 0.f});

		cylinder.Draw(cube, camera, { 35.f, 0.f, -5.f });

		cylinder.Draw(cube, camera, { 45.f, 0.f, -5.f }, -coeff, { 1.f, 0.f, -1.f });

		cylinder.Draw(cube, camera, { 55.f, tan(coeff / 30.f) * 10.f, -5.f }, -coeff, { 0.f, 1.f, 0.f });

		skybox.Draw(skybox_shader, camera);

		///////////////////////
		coeff = coeff + 1 % 360;
		///////////////////////

		///////////////////////////////////////////////////////////////////// Отрисовка объектов
		window.display();
	}


	window.close();
	return 0;
}