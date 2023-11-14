#pragma once

#include <Includes.h>

class camera { // ���������� ������

public:

	//���� ������ (���� 3 ���� ������: ������ (pitch), �������� (yaw) � ���� (roll))
	float CameraYaw = -90.0f; 
	float CameraPitch = 0.0f;
	///////////////////////

	glm::vec3 up;
	glm::vec3 front;
	glm::vec3 right;
	glm::vec3 CameraPosition = {0.f, 0.f, 0.f};
	float speed = 0.2f;

	///////////////////////
	camera() = default;
	///////////////////////

	void update_view(sf::RenderWindow& window ) {

		///////////////////////
		float speed = 0.1f;
		static sf::Vector2i prevPos, curPos, temp, temp2;
		static sf::Vector2i zero = { 0,0 };
		///////////////////////

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			temp2 = sf::Mouse::getPosition(window);
			if (temp != zero) {
				curPos += temp2 - temp;
				temp = temp2;
			}
			else {
				temp = sf::Mouse::getPosition(window);
			}
		}
		else {
			temp = zero;
			temp2 = zero;
		}
		auto dxy = (curPos - prevPos);

		///////////////////////
		prevPos = curPos;
		///////////////////////

		CameraYaw += static_cast<float>(dxy.x) * speed;
		CameraPitch += static_cast<float>(-dxy.y) * speed;

		///////////////////////
		if (CameraPitch > 89.0f)
			CameraPitch = 89.0f;
		if (CameraPitch < -89.0f)
			CameraPitch = -89.0f;
		///////////////////////

		front.x = cos(glm::radians(CameraYaw)) * cos(glm::radians(CameraPitch));
		front.y = sin(glm::radians(CameraPitch));
		front.z = sin(glm::radians(CameraYaw)) * cos(glm::radians(CameraPitch));
		front = normalize(front);
		right = glm::normalize(glm::cross(front, glm::vec3(0.0f, 1.0f, 0.0f)));
		up = normalize(cross(right, front));
		///////////////////////
	};

	glm::mat4 GetProjectionMatrix() { // ������� ��� �������� � ������������ ���������
		return glm::perspective(glm::radians(45.0f), 1920.0f / 1080.0f, 0.1f, 500.0f);
		// ������������ �������
	}

	glm::mat4 GetViewMatrix() { // ������� ��� �������� � ������������ ����
		glm::mat4 view;
		view = glm::lookAt(CameraPosition, CameraPosition + front, up);
		return view;
		//������� ����
	}

	glm::mat4 ViewForSkybox() {
		glm::mat4 view = GetViewMatrix();
		view[3][0] = 0;
		view[3][1] = 0;
		view[3][2] = 0;
		view[3][3] = 0;

		return view;
	}

	//������������
	void KeyboardInput() {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			CameraPosition += front * speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			CameraPosition -= front * speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			CameraPosition -= right * speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			CameraPosition += right * speed;
		}
	}
	///////////////////////

	glm::vec3 GetPos() {
		return CameraPosition;
	}

	glm::vec3 GetFront() {
		return front;
	}
	///////////////////////
};
