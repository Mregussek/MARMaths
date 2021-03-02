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


#include "include/MARMaths.h" // only need include

#include <iomanip>

using namespace marengine;

std::ostream& operator<<(std::ostream& stream, maths::vec2 vector) {
    stream << "vec2: ( " << vector.x << " , " << vector.y << " )";

    return stream;
}

std::ostream& operator<<(std::ostream& stream, maths::vec3 vector) {
    stream << "vec3: ( " << vector.x << " , " << vector.y << " , " << vector.z << " )";

    return stream;
}

std::ostream& operator<<(std::ostream& stream, maths::vec4 vector) {
    stream << "vec4: ( " << vector.x << " , " << vector.y << " , " <<
        vector.z << " , " << vector.w << " )";

    return stream;
}

std::ostream& operator<<(std::ostream& stream, maths::mat4 matrix) {
    stream << std::fixed << std::setw(11) << std::setprecision(6) << "\n"
        << " | " << matrix[0 + 0 * 4] << " " << matrix[0 + 1 * 4] << " " << matrix[0 + 2 * 4] << " " << matrix[0 + 3 * 4] << " | \n"
        << " | " << matrix[1 + 0 * 4] << " " << matrix[1 + 1 * 4] << " " << matrix[1 + 2 * 4] << " " << matrix[1 + 3 * 4] << " | \n"
        << " | " << matrix[2 + 0 * 4] << " " << matrix[2 + 1 * 4] << " " << matrix[2 + 2 * 4] << " " << matrix[2 + 3 * 4] << " | \n"
        << " | " << matrix[3 + 0 * 4] << " " << matrix[3 + 1 * 4] << " " << matrix[3 + 2 * 4] << " " << matrix[3 + 3 * 4] << " | \n";

    return stream;
}

int main() {

    maths::vec2 default_values;

    std::cout << "default_values:\n";
    std::cout << default_values << "\n";

    maths::vec3 v1 = { 1.f, 2.f, 3.f };
    maths::vec3 v2 = { 2.f, 3.f, 4.f };

    std::cout << "v1.multiply(v2):\n";
    std::cout << v1.multiply(v2) << "\n";
    std::cout << v1 * v2 << "\n";
    
    float value = 5.f;
    
    std::cout << " v2 - value:\n";
    std::cout << v2.subtract(value) << "\n";
    std::cout << v2 - value << "\n";

    maths::vec4 v4{ v1, 10.f };

    std::cout << "v4{ v1, 10.f }:\n";
    std::cout << v4 << "\n";
    std::cout << v4 * maths::vec4{ 3.f, 3.f, 3.f, 3.f } << "\n";

    maths::mat4 default_mat;

    std::cout << "default_mat:\n";
    std::cout << default_mat << "\n";

    maths::mat4 identity_2f{ 2.f };
    maths::mat4 identity_3f{ 3.f };

    std::cout << "identity_2f * identity_3f:\n";
    std::cout << identity_2f * identity_3f << "\n";

    float field_of_view = 55.f;
    float aspectRatio = 4.f / 3.f;
    float near = 0.1f;
    float far = 100.f;

    std::cout << "maths::mat4::perspective(55.f, 4.f / 3.f, 0.1f, 100.f):\n";
    std::cout << maths::mat4::perspective(field_of_view, aspectRatio, near, far) << "\n";

    float angle_in_degrees = 45.f;
    maths::vec3 rotation_axis = { 0.f, 1.f, 0.f }; // rotating around y-axis

    std::cout << "maths::mat4::rotation(maths::Trig::toRadians(45.f), rotation_axis):\n";
    std::cout << maths::mat4::rotation(maths::trig::toRadians(angle_in_degrees), rotation_axis) << "\n";

    maths::vec3 position{ 0.5, 0.5, 0.5 };
    maths::vec3 front{ 0.0f, 0.0f, -1.0f };
    maths::vec3 up{ 0.0f, 1.0f, 0.0f };
    maths::vec3 scale{ 1.f, 1.f, 2.f };

    std::cout << "maths::mat4::translation(position) * maths::mat4::scale(scale):\n";
    std::cout << maths::mat4::translation(position) * maths::mat4::scale(scale) << "\n";

    maths::mat4 id = maths::mat4::identity();
    std::cout << " maths::mat4::identity():\n";
    std::cout << id << "\n";

    maths::mat4 look = maths::mat4::lookAt(position, position + front, up);
    
    std::cout << "maths::mat4::lookAt(position, position + front, up):\n";
    std::cout << look << "\n";

    std::cout << "id * look:\n";
    std::cout << id * look << "\n";

    auto vec = maths::vec4{ 3.f, 3.f, 3.f, 3.f };
    auto rotate = maths::mat4::rotation(maths::trig::toRadians(angle_in_degrees), rotation_axis);

    std::cout << "rotate * vec:\n";
    std::cout << rotate * vec << "\n";

}