#pragma once

#include <Includes.h>

Vertex loadOBJ( // Загрузка модели (объекта)

	///////////////////////
	const char* path,
	///////////////////////

	std::vector < glm::vec3 >& out_vertices,
	std::vector < glm::vec2 >& out_uvs,
	std::vector < glm::vec3 >& out_normals
);