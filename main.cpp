/*
 *	Mateusz Rzeczyca
 *	Copyright (C) 2020 Mateusz Rzeczyca <info@mateuszrzeczyca.pl>
 */

#include "MARMaths.h"

int main() {
    using namespace mar::maths;

    mat4 ide = mat4::identity();
    ide = mat4(2.0f);
    mat4 diag(3.0f);

    std::cout << ide << std::endl;
    std::cout << diag << std::endl;

    std::cout << ide * diag << std::endl;
}