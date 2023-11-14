#pragma once

#include <service/textureLoader.cpp>

class Texture {
public:

	Texture(char const* path) { // Загружает текстуру, сохраняя ID
		id = LoadTexture(path);
	};

	
	Texture(std::vector<std::string> faces) { // Загружает текстуру, сохраняя ID
		id = LoadSkyTexture(faces);
	}

	void Bind(int flag = -1) { // Привязкатекстуры к объекту
		if (flag == 0) {
			glActiveTexture(GL_TEXTURE0);
		}
		if (flag == 1) {
			glActiveTexture(GL_TEXTURE1);
		}
		glBindTexture(GL_TEXTURE_2D, id);
	};

private:
	// ID текстуры
	unsigned int id;
};