/*
 *	Mateusz Rzeczyca
 *	Copyright (C) 2020 Mateusz Rzeczyca <info@mateuszrzeczyca.pl>
 */

#include "MARMaths.h"

int main() {
    using namespace mar::maths;

    vec3 position{ 0.5, 0.5, 0.5 };
    vec3 front{ 0.0f, 0.0f, -1.0f };
    vec3 up{ 0.0f, 1.0f, 0.0f };

    std::cout << mat4::lookAt(position, position + front, up) << "\n";
    std::cout << position << "\n";
    position += 1.f;
    std::cout << position << "\n";
}