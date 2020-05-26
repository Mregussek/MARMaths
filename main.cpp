/*
 *	Mateusz Rzeczyca
 *	Copyright (C) 2020 Mateusz Rzeczyca <info@mateuszrzeczyca.pl>
 */

#include "src/maths.h"

int main() {
    using namespace mar::maths;

	vec4 v(3.0f, 5.0f, 2.0f, 1.5f);
	vec4 v2(2.0f, 2.0f, 2.0f, 2.0f);
	vec4 v3(1.0f, 2.0f, 2.0f, 2.5f);

	std::cout << v << std::endl;

	v *= v2;

	std::cout << v2 << std::endl;
	std::cout << v3 << std::endl;
	std::cout << " --- " << std::endl;
	std::cout << v << std::endl;
	std::cout << (v3 != v2) << std::endl;
	std::cout << (v3 == v2) << std::endl;
}