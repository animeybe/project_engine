#pragma once

#include <Includes.h>

/*
	Преднастройки
*/

inline sf:: ContextSettings default_settings() {
	sf::ContextSettings settings;
	settings.depthBits = 24; // количество битов буффера глубины
	settings.stencilBits = 8; //количество битов буфера трафарета
	settings.minorVersion = 3;
	settings.attributeFlags = sf::ContextSettings::Core;
	return settings;
}

