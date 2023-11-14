#pragma once

#include <Includes.h>

/*
	�������������
*/

inline sf:: ContextSettings default_settings() {
	sf::ContextSettings settings;
	settings.depthBits = 24; // ���������� ����� ������� �������
	settings.stencilBits = 8; //���������� ����� ������ ���������
	settings.minorVersion = 3;
	settings.attributeFlags = sf::ContextSettings::Core;
	return settings;
}

