#pragma once

#include <string>
#include <vector>
#include <GL/glew.h>

inline GLuint LoadTexture(const char* texture_file_path);
inline GLuint LoadSkyTexture(std::vector<std::string> faces);