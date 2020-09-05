/**
 *        MARMaths - open source computing library for MAREngine
 * Copyright (C) 2020-present Mateusz Rzeczyca <info@mateuszrzeczyca.pl>
 * All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
**/


#include "MARMaths.h"


int main() {
    using namespace mar::maths;

    vec3 position{ 0.5, 0.5, 0.5 };
    vec3 front{ 0.0f, 0.0f, -1.0f };
    vec3 up{ 0.0f, 1.0f, 0.0f };

    mat4 id = mat4::identity();
    std::cout << id << "\n";

    mat4 look = mat4::lookAt(position, position + front, up);
    std::cout << look << "\n";

    std::cout << id * look << "\n";

}