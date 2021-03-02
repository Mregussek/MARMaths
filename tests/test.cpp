/***********************************************************************
* @internal @copyright
*
*        MARMaths - open source computing library for MAREngine
*
* Copyright (C) 2020-present Mateusz Rzeczyca <info@mateuszrzeczyca.pl>
* All rights reserved.
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
************************************************************************/


#include "pch.h"
#include "MARMaths.h"
#include <array>
#include <iostream>


using namespace marengine::maths;


std::ostream& operator<<(std::ostream& stream, vec3 vector) {
	stream << "vec3: ( " << vector.x << " , " << vector.y << " , " << vector.z << " )";

	return stream;
}

std::ostream& operator<<(std::ostream& stream, vec4 vector) {
	stream << "vec4: ( " << vector.x << " , " << vector.y << " , " <<
		vector.z << " , " << vector.w << " )";

	return stream;
}

std::ostream& operator<<(std::ostream& stream, mat4 matrix) {
	stream << std::fixed << std::setw(11) << std::setprecision(6) << "\n"
		<< " | " << matrix[0 + 0 * 4] << " " << matrix[0 + 1 * 4] << " " << matrix[0 + 2 * 4] << " " << matrix[0 + 3 * 4] << " | \n"
		<< " | " << matrix[1 + 0 * 4] << " " << matrix[1 + 1 * 4] << " " << matrix[1 + 2 * 4] << " " << matrix[1 + 3 * 4] << " | \n"
		<< " | " << matrix[2 + 0 * 4] << " " << matrix[2 + 1 * 4] << " " << matrix[2 + 2 * 4] << " " << matrix[2 + 3 * 4] << " | \n"
		<< " | " << matrix[3 + 0 * 4] << " " << matrix[3 + 1 * 4] << " " << matrix[3 + 2 * 4] << " " << matrix[3 + 3 * 4] << " | \n";

	return stream;
}


TEST(MAT4Testcase, MAT4BasicComparison) {
	const std::array<mat4, 3> arr1{ mat4{ 1.f }, mat4{ 2.f }, mat4{ 3.f } };
	const std::array<mat4, 3> arr2{ mat4{ 1.f }, mat4{ 2.f }, mat4{ 3.f } };
	const std::array<mat4, 3> arr3{ mat4{ 3.f }, mat4{ 1.f }, mat4{ 2.f } };

	// assert arr1 == arr2 (should be all true)
	for (size_t i = 0; i < 3; i++) {
		ASSERT_TRUE(arr1[i] == arr2[i]);
	}

	// assert arr1 == arr3 (should be all false)
	for (size_t i = 0; i < 3; i++) {
		ASSERT_FALSE(arr1[i] == arr3[i]);
	}

	// assert arr1 != arr2 (should be all false)
	for (size_t i = 0; i < 3; i++) {
		ASSERT_FALSE(arr1[i] != arr2[i]);
	}

	mat4 right, left;
	for (size_t i = 0; i < 16; i++) {
		right.elements[i] = (float)(i % 4);
		left.elements[i] = (float)(i % 4);
	}

	ASSERT_TRUE(right == left);
	ASSERT_FALSE(right != left);
}

TEST(MAT4testcase, MAT4multiplication1) {
	mat4 left;
	mat4 right;
	mat4 properRtn;

	for (size_t i = 0; i < 4; i++) {
		left.elements[0 + i * 4] = (float)(i + 1);
		left.elements[1 + i * 4] = (float)(i + 1);
		left.elements[2 + i * 4] = (float)(i + 1);
		left.elements[3 + i * 4] = (float)(i + 1);

		right.elements[0 + i * 4] = (float)(i + 1);
		right.elements[1 + i * 4] = (float)(i + 1);
		right.elements[2 + i * 4] = (float)(i + 1);
		right.elements[3 + i * 4] = (float)(i + 1);

		properRtn.elements[0 + i * 4] = (float)10 * (i + 1);
		properRtn.elements[1 + i * 4] = (float)10 * (i + 1);
		properRtn.elements[2 + i * 4] = (float)10 * (i + 1);
		properRtn.elements[3 + i * 4] = (float)10 * (i + 1);
	}

	const mat4 multiplyResult1 = left * right;

	ASSERT_TRUE(multiplyResult1 == properRtn);
	ASSERT_FALSE(multiplyResult1 != properRtn);

	const mat4 multiplyResult2 = right * left;

	ASSERT_TRUE(multiplyResult2 == properRtn);
	ASSERT_FALSE(multiplyResult2 != properRtn);

	ASSERT_TRUE(multiplyResult1 == multiplyResult2);
	ASSERT_FALSE(multiplyResult1 != multiplyResult2);
}

TEST(MAT4testcase, MAT4multiplication2) {
	const vec3 position{ 1.f, 2.f, 3.f };
	const vec3 scale{ 2.f, 2.f, 2.f };
	const mat4 trans{ mat4::translation(position) };
	const mat4 sca{ mat4::scale(scale) };
	mat4 rtn;
	rtn[0 + 0 * 4] = 2.f;
	rtn[1 + 0 * 4] = 0.f;
	rtn[2 + 0 * 4] = 0.f;
	rtn[3 + 0 * 4] = 0.f;

	rtn[0 + 1 * 4] = 0.f;
	rtn[1 + 1 * 4] = 2.f;
	rtn[2 + 1 * 4] = 0.f;
	rtn[3 + 1 * 4] = 0.f;

	rtn[0 + 2 * 4] = 0.f;
	rtn[1 + 2 * 4] = 0.f;
	rtn[2 + 2 * 4] = 2.f;
	rtn[3 + 2 * 4] = 0.f;

	rtn[0 + 3 * 4] = 1.f;
	rtn[1 + 3 * 4] = 2.f;
	rtn[2 + 3 * 4] = 3.f;
	rtn[3 + 3 * 4] = 1.f;

	const mat4 multiplyResult = trans * sca;

	ASSERT_TRUE(multiplyResult == rtn);
	ASSERT_FALSE(multiplyResult != rtn);

}
