#pragma once

#include <Includes.h>

using namespace std;

class vertex_buffer {
public:
	vertex_buffer(float data[], int size) {
		glGenBuffers(1, &id);
		Bind();
		glBufferData(GL_ARRAY_BUFFER, size * sizeof(data), data, GL_STATIC_DRAW);
	}

	vertex_buffer(vector<glm::vec3> data) {
		glGenBuffers(1, &id);
		Bind();
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec3), &data[0], GL_STATIC_DRAW);
	}

	vertex_buffer(vector<glm::vec2> data) {
		glGenBuffers(1, &id);
		Bind();
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec2), &data[0], GL_STATIC_DRAW);
	}

	void Bind(int flag = -1) {
		if (flag == 0)
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		else
			glBindBuffer(GL_ARRAY_BUFFER, id);
	}
	void Delete() {
		glDeleteBuffers(1, &id);
	}

private:
	unsigned int id;
};
