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


#define COMPARE_GLM_TO_MARMATH 1


#include "pch.h"
#include <array>
#include <iostream>


#include "MARMaths.h"

using namespace marengine;


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


using namespace marengine::maths;


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

TEST(MAT4Testcase, MAT4multiplication1) {
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

TEST(MAT4Testcase, MAT4multiplication2) {
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

	const mat4 multiplyResult1 = trans * sca;

	ASSERT_TRUE(multiplyResult1 == rtn);
	ASSERT_FALSE(multiplyResult1 != rtn);

	const mat4 multiplyResult2 = trans.multiply(sca);

	ASSERT_TRUE(multiplyResult2 == rtn);
	ASSERT_FALSE(multiplyResult2 != rtn);

}


#if COMPARE_GLM_TO_MARMATH

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/common.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtc/epsilon.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace test_glm {

	bool DecomposeTransform(const glm::mat4& transform, glm::vec3& translation, glm::vec3& rotation, glm::vec3& scale)
	{
		// From glm::decompose in matrix_decompose.inl
		using T = float;

		glm::mat4 LocalMatrix(transform);

		// Normalize the matrix.
		if (glm::epsilonEqual(LocalMatrix[3][3], static_cast<float>(0), FLT_EPSILON))
			return false;

		// First, isolate perspective.  This is the messiest.
		if (
			glm::epsilonNotEqual(LocalMatrix[0][3], static_cast<T>(0), FLT_EPSILON) ||
			glm::epsilonNotEqual(LocalMatrix[1][3], static_cast<T>(0), FLT_EPSILON) ||
			glm::epsilonNotEqual(LocalMatrix[2][3], static_cast<T>(0), FLT_EPSILON))
		{
			// Clear the perspective partition
			LocalMatrix[0][3] = LocalMatrix[1][3] = LocalMatrix[2][3] = static_cast<T>(0);
			LocalMatrix[3][3] = static_cast<T>(1);
		}

		// Next take care of translation (easy).
		translation = glm::vec3(LocalMatrix[3]);
		LocalMatrix[3] = glm::vec4(0, 0, 0, LocalMatrix[3].w);

		glm::vec3 Row[3];

		// Now get scale and shear.
		for (glm::length_t i = 0; i < 3; ++i)
			for (glm::length_t j = 0; j < 3; ++j)
				Row[i][j] = LocalMatrix[i][j];

		// Compute X scale factor and normalize first row.
		scale.x = glm::length(Row[0]);
		Row[0] = glm::detail::scale(Row[0], static_cast<T>(1));
		scale.y = glm::length(Row[1]);
		Row[1] = glm::detail::scale(Row[1], static_cast<T>(1));
		scale.z = glm::length(Row[2]);
		Row[2] = glm::detail::scale(Row[2], static_cast<T>(1));

		// At this point, the matrix (in rows[]) is orthonormal.
		// Check for a coordinate system flip.  If the determinant
		// is -1, then negate the matrix and the scaling factors.
#if 0
		Pdum3 = cross(Row[1], Row[2]); // v3Cross(row[1], row[2], Pdum3);
		if (dot(Row[0], Pdum3) < 0)
		{
			for (length_t i = 0; i < 3; i++)
			{
				scale[i] *= static_cast<T>(-1);
				Row[i] *= static_cast<T>(-1);
			}
		}
#endif
		rotation.y = asin(-Row[0][2]);
		if (cos(rotation.y) != 0) {
			rotation.x = atan2(Row[1][2], Row[2][2]);
			rotation.z = atan2(Row[0][1], Row[0][0]);
		}
		else {
			rotation.x = atan2(-Row[2][0], Row[1][1]);
			rotation.z = 0;
		}


		return true;
	}

}

std::ostream& operator<<(std::ostream& stream, glm::vec3 vector) {
	stream << "vec3: ( " << vector.x << " , " << vector.y << " , " << vector.z << " )";

	return stream;
}

std::ostream& operator<<(std::ostream& stream, const glm::mat4& mat) {
	const float* matrix{ glm::value_ptr(mat) };

	stream << std::fixed << std::setw(11) << std::setprecision(6) << "\n"
		<< " | " << matrix[0 + 0 * 4] << " " << matrix[0 + 1 * 4] << " " << matrix[0 + 2 * 4] << " " << matrix[0 + 3 * 4] << " | \n"
		<< " | " << matrix[1 + 0 * 4] << " " << matrix[1 + 1 * 4] << " " << matrix[1 + 2 * 4] << " " << matrix[1 + 3 * 4] << " | \n"
		<< " | " << matrix[2 + 0 * 4] << " " << matrix[2 + 1 * 4] << " " << matrix[2 + 2 * 4] << " " << matrix[2 + 3 * 4] << " | \n"
		<< " | " << matrix[3 + 0 * 4] << " " << matrix[3 + 1 * 4] << " " << matrix[3 + 2 * 4] << " " << matrix[3 + 3 * 4] << " | \n";

	return stream;
}


TEST(MARMATHvsGLM, MAT4TranslateComparison) {
	glm::vec3 posGLM;
	glm::mat4 transformGLM;
	maths::vec3 posMAR;
	maths::mat4 transformMAR;

	{
		posGLM = { 1.f, 2.f, 3.f };
		transformGLM = { glm::translate(glm::mat4(1.0f), posGLM) };
		posMAR = { 1.f, 2.f, 3.f };
		transformMAR = { maths::mat4::translation(posMAR) };
		float* iteratorGLM{ glm::value_ptr(transformGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == transformMAR[i]);
		}
	}
	{
		posGLM = { 1.25f, 1.25f, 1.25f };
		transformGLM = { glm::translate(glm::mat4(1.0f), posGLM) };
		posMAR = { 1.25f, 1.25f, 1.25f };
		transformMAR = { maths::mat4::translation(posMAR) };
		float* iteratorGLM{ glm::value_ptr(transformGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == transformMAR[i]);
		}
	}
}

TEST(MARMATHvsGLM, MAT4RotationXaxisComparison) {
	float angle;
	const glm::vec3 rotGLM{ 1.f, 0.f, 0.f };
	glm::mat4 transformGLM;
	const maths::vec3 rotMAR{ 1.f, 0.f, 0.f };
	maths::mat4 transformMAR;

	{
		angle = 45.f;
		transformGLM = { glm::rotate(glm::mat4(1.0f), glm::radians(angle), rotGLM) };
		transformMAR = { maths::mat4::rotation(trig::toRadians(angle), rotMAR) };
		float* iteratorGLM{ glm::value_ptr(transformGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == transformMAR[i]);
		}
	}
	{
		angle = 55.f;
		transformGLM = { glm::rotate(glm::mat4(1.0f), glm::radians(angle), rotGLM) };
		transformMAR = { maths::mat4::rotation(trig::toRadians(angle), rotMAR) };
		float* iteratorGLM{ glm::value_ptr(transformGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == transformMAR[i]);
		}
	}
	{
		angle = 115.f;
		transformGLM = { glm::rotate(glm::mat4(1.0f), glm::radians(angle), rotGLM) };
		transformMAR = { maths::mat4::rotation(trig::toRadians(angle), rotMAR) };
		float* iteratorGLM{ glm::value_ptr(transformGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == transformMAR[i]);
		}
	}
	{
		angle = 180.f;
		transformGLM = { glm::rotate(glm::mat4(1.0f), glm::radians(angle), rotGLM) };
		transformMAR = { maths::mat4::rotation(trig::toRadians(angle), rotMAR) };
		float* iteratorGLM{ glm::value_ptr(transformGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == transformMAR[i]);
		}
	}
}

TEST(MARMATHvsGLM, MAT4RotationYaxisComparison) {
	float angle;
	const glm::vec3 rotGLM{ 0.f, 1.f, 0.f };
	glm::mat4 transformGLM;
	const maths::vec3 rotMAR{ 0.f, 1.f, 0.f };
	maths::mat4 transformMAR;

	{
		angle = 45.f;
		transformGLM = { glm::rotate(glm::mat4(1.0f), glm::radians(angle), rotGLM) };
		transformMAR = { maths::mat4::rotation(trig::toRadians(angle), rotMAR) };
		float* iteratorGLM{ glm::value_ptr(transformGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == transformMAR[i]);
		}
	}
	{
		angle = 55.f;
		transformGLM = { glm::rotate(glm::mat4(1.0f), glm::radians(angle), rotGLM) };
		transformMAR = { maths::mat4::rotation(trig::toRadians(angle), rotMAR) };
		float* iteratorGLM{ glm::value_ptr(transformGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == transformMAR[i]);
		}
	}
	{
		angle = 115.f;
		transformGLM = { glm::rotate(glm::mat4(1.0f), glm::radians(angle), rotGLM) };
		transformMAR = { maths::mat4::rotation(trig::toRadians(angle), rotMAR) };
		float* iteratorGLM{ glm::value_ptr(transformGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == transformMAR[i]);
		}
	}
	{
		angle = 180.f;
		transformGLM = { glm::rotate(glm::mat4(1.0f), glm::radians(angle), rotGLM) };
		transformMAR = { maths::mat4::rotation(trig::toRadians(angle), rotMAR) };
		float* iteratorGLM{ glm::value_ptr(transformGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == transformMAR[i]);
		}
	}
}

TEST(MARMATHvsGLM, MAT4RotationZaxisComparison) {
	float angle;
	const glm::vec3 rotGLM{ 0.f, 0.f, 1.f };
	glm::mat4 transformGLM;
	const maths::vec3 rotMAR{ 0.f, 0.f, 1.f };
	maths::mat4 transformMAR;

	{
		angle = 45.f;
		transformGLM = { glm::rotate(glm::mat4(1.0f), glm::radians(angle), rotGLM) };
		transformMAR = { maths::mat4::rotation(trig::toRadians(angle), rotMAR) };
		float* iteratorGLM{ glm::value_ptr(transformGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == transformMAR[i]);
		}
	}
	{
		angle = 55.f;
		transformGLM = { glm::rotate(glm::mat4(1.0f), glm::radians(angle), rotGLM) };
		transformMAR = { maths::mat4::rotation(trig::toRadians(angle), rotMAR) };
		float* iteratorGLM{ glm::value_ptr(transformGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == transformMAR[i]);
		}
	}
	{
		angle = 115.f;
		transformGLM = { glm::rotate(glm::mat4(1.0f), glm::radians(angle), rotGLM) };
		transformMAR = { maths::mat4::rotation(trig::toRadians(angle), rotMAR) };
		float* iteratorGLM{ glm::value_ptr(transformGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == transformMAR[i]);
		}
	}
	{
		angle = 180.f;
		transformGLM = { glm::rotate(glm::mat4(1.0f), glm::radians(angle), rotGLM) };
		transformMAR = { maths::mat4::rotation(trig::toRadians(angle), rotMAR) };
		float* iteratorGLM{ glm::value_ptr(transformGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == transformMAR[i]);
		}
	}
}

TEST(MARMATHvsGLM, MAT4QuatCreation) {
	glm::vec3 rotGLM3;
	glm::vec4 rotGLM4;
	maths::vec3 rotMAR3;
	maths::vec4 rotMAR4;

	{
		rotGLM3 = { 5.f, 5.f, 5.f };
		rotGLM4 = { 5.f, 5.f, 5.f, 1.f };
		rotMAR3 = { 5.f, 5.f, 5.f };
		rotMAR4 = { 5.f, 5.f, 5.f, 1.f};
		
		const glm::quat qGLM3 = rotGLM3;
		const glm::quat qGLM4 = rotGLM4;

		const maths::quat qMAR3 = rotMAR3;
		const maths::quat qMAR4 = rotMAR4;

		ASSERT_TRUE(qGLM3.x == qMAR3.x);
		ASSERT_TRUE(qGLM3.y == qMAR3.y);
		ASSERT_TRUE(qGLM3.z == qMAR3.z);

		ASSERT_TRUE(qGLM4.x == qMAR4.x);
		ASSERT_TRUE(qGLM4.y == qMAR4.y);
		ASSERT_TRUE(qGLM4.z == qMAR4.z);
		ASSERT_TRUE(qGLM4.w == qMAR4.w);
	}
	{
		rotGLM3 = { 2.25f, 3.75f, 3.14f };
		rotGLM4 = { 2.25f, 3.75f, 3.14f, 1.f };
		rotMAR3 = { 2.25f, 3.75f, 3.14f };
		rotMAR4 = { 2.25f, 3.75f, 3.14f, 1.f };

		const glm::quat qGLM3 = rotGLM3;
		const glm::quat qGLM4 = rotGLM4;

		const maths::quat qMAR3 = rotMAR3;
		const maths::quat qMAR4 = rotMAR4;

		ASSERT_TRUE(qGLM3.x == qMAR3.x);
		ASSERT_TRUE(qGLM3.y == qMAR3.y);
		ASSERT_TRUE(qGLM3.z == qMAR3.z);

		ASSERT_TRUE(qGLM4.x == qMAR4.x);
		ASSERT_TRUE(qGLM4.y == qMAR4.y);
		ASSERT_TRUE(qGLM4.z == qMAR4.z);
		ASSERT_TRUE(qGLM4.w == qMAR4.w);
	}
	{
		rotGLM3 = { 11.23f, 6.05f, 1.234f };
		rotGLM4 = { 11.23f, 6.05f, 1.234f, 1.f };
		rotMAR3 = { 11.23f, 6.05f, 1.234f };
		rotMAR4 = { 11.23f, 6.05f, 1.234f, 1.f };

		const glm::quat qGLM3 = rotGLM3;
		const glm::quat qGLM4 = rotGLM4;

		const maths::quat qMAR3 = rotMAR3;
		const maths::quat qMAR4 = rotMAR4;

		ASSERT_TRUE(qGLM3.x == qMAR3.x);
		ASSERT_TRUE(qGLM3.y == qMAR3.y);
		ASSERT_TRUE(qGLM3.z == qMAR3.z);

		ASSERT_TRUE(qGLM4.x == qMAR4.x);
		ASSERT_TRUE(qGLM4.y == qMAR4.y);
		ASSERT_TRUE(qGLM4.z == qMAR4.z);
		ASSERT_TRUE(qGLM4.w == qMAR4.w);
	}
}

TEST(MARMATHvsGLM, MAT4QuatToRot) {
	glm::mat4 rotGLM;
	maths::mat4 rotMAR;

	{
		const glm::vec3 vGLM{ 0.25f, 0.25f, 0.25f };
		const maths::vec3 vMAR{ 0.25f, 0.25f, 0.25f };

		rotGLM = glm::toMat4(glm::quat(vGLM));
		rotMAR = quat::rotationFromQuat(maths::quat(vMAR));

		float* iteratorGLM{ glm::value_ptr(rotGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == rotMAR[i]);
		}
	}
	{
		const glm::vec3 vGLM{ 3.67f, 5.05f, 7.75f };
		const maths::vec3 vMAR{ 3.67f, 5.05f, 7.75f };

		rotGLM = glm::toMat4(glm::quat(vGLM));
		rotMAR = quat::rotationFromQuat(maths::quat(vMAR));

		float* iteratorGLM{ glm::value_ptr(rotGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == rotMAR[i]);
		}
	}
	{
		const glm::vec3 vGLM{ 7.75f, 6.63f, 11.4f };
		const maths::vec3 vMAR{ 7.75f, 6.63f, 11.4f };

		rotGLM = glm::toMat4(glm::quat(vGLM));
		rotMAR = quat::rotationFromQuat(maths::quat(vMAR));

		float* iteratorGLM{ glm::value_ptr(rotGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == rotMAR[i]);
		}
	}
}

TEST(MARMATHvsGLM, MAT4Recompose) {
	glm::mat4 recGLM;
	maths::mat4 recMAR;

	{
		constexpr float pos[3]{ 0.5f, 0.5f, 0.5f };
		constexpr float rot[3]{ 0.25f, 0.25f, 0.25f };
		constexpr float sca[3]{ 1.f, 1.f, 1.f };

		const glm::vec3 posGLM{ pos[0], pos[1], pos[2] };
		const glm::vec3 rotGLM{ rot[0], rot[1], rot[2] };
		const glm::vec3 scaGLM{ sca[0], sca[1], sca[2] };

		const maths::vec3 posMAR{ pos[0], pos[1], pos[2] };
		const maths::vec3 rotMAR{ rot[0], rot[1], rot[2] };
		const maths::vec3 scaMAR{ sca[0], sca[1], sca[2] };
			
		recGLM = glm::translate(glm::mat4(1.f), posGLM) * glm::toMat4(glm::quat(rotGLM)) * glm::scale(glm::mat4(1.f), scaGLM);
		recMAR = maths::mat4::translation(posMAR) * maths::quat::rotationFromQuat(maths::quat(rotMAR)) * maths::mat4::scale(scaMAR);

		float* iteratorGLM{ glm::value_ptr(recGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == recMAR[i]);
		}
	}
	{
		constexpr float pos[3]{ 21.37f, 45.245f, 456.1f };
		constexpr float rot[3]{ 6.19f, 1.66f, 10.25f };
		constexpr float sca[3]{ 25.f, 100.f, 3.f };

		const glm::vec3 posGLM{ pos[0], pos[1], pos[2] };
		const glm::vec3 rotGLM{ rot[0], rot[1], rot[2] };
		const glm::vec3 scaGLM{ sca[0], sca[1], sca[2] };

		const maths::vec3 posMAR{ pos[0], pos[1], pos[2] };
		const maths::vec3 rotMAR{ rot[0], rot[1], rot[2] };
		const maths::vec3 scaMAR{ sca[0], sca[1], sca[2] };

		recGLM = glm::translate(glm::mat4(1.f), posGLM) * glm::toMat4(glm::quat(rotGLM)) * glm::scale(glm::mat4(1.f), scaGLM);
		recMAR = maths::mat4::translation(posMAR) * maths::quat::rotationFromQuat(maths::quat(rotMAR)) * maths::mat4::scale(scaMAR);

		float* iteratorGLM{ glm::value_ptr(recGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == recMAR[i]);
		}
	}
	{
		constexpr float pos[3]{ 6.19f, 1.66f, 10.25f };
		constexpr float rot[3]{ 25.f, 100.f, 3.f };
		constexpr float sca[3]{ 21.37f, 45.245f, 456.1f };

		const glm::vec3 posGLM{ pos[0], pos[1], pos[2] };
		const glm::vec3 rotGLM{ rot[0], rot[1], rot[2] };
		const glm::vec3 scaGLM{ sca[0], sca[1], sca[2] };

		const maths::vec3 posMAR{ pos[0], pos[1], pos[2] };
		const maths::vec3 rotMAR{ rot[0], rot[1], rot[2] };
		const maths::vec3 scaMAR{ sca[0], sca[1], sca[2] };

		recGLM = glm::translate(glm::mat4(1.f), posGLM) * glm::toMat4(glm::quat(rotGLM)) * glm::scale(glm::mat4(1.f), scaGLM);
		recMAR = maths::mat4::translation(posMAR) * maths::quat::rotationFromQuat(maths::quat(rotMAR)) * maths::mat4::scale(scaMAR);

		float* iteratorGLM{ glm::value_ptr(recGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == recMAR[i]);
		}
	}
}

TEST(MARMATHvsGLM, MAT4Decompose) {
	// RECOMPOSE TEST IS PASSED, RESULTS ARE THE SAME SO I WILL TRY TO DECOMPOSE THOSE MATRICES

	glm::mat4 recGLM;
	maths::mat4 recMAR;

	{
		constexpr float pos[3]{ 0.5f, 0.5f, 0.5f };
		constexpr float rot[3]{ 0.25f, 0.25f, 0.25f };
		constexpr float sca[3]{ 1.f, 1.f, 1.f };

		const glm::vec3 posGLM{ pos[0], pos[1], pos[2] };
		const glm::vec3 rotGLM{ rot[0], rot[1], rot[2] };
		const glm::vec3 scaGLM{ sca[0], sca[1], sca[2] };

		const maths::vec3 posMAR{ pos[0], pos[1], pos[2] };
		const maths::vec3 rotMAR{ rot[0], rot[1], rot[2] };
		const maths::vec3 scaMAR{ sca[0], sca[1], sca[2] };

		recGLM = glm::translate(glm::mat4(1.f), posGLM) * glm::toMat4(glm::quat(rotGLM)) * glm::scale(glm::mat4(1.f), scaGLM);
		recMAR = maths::mat4::translation(posMAR) * maths::quat::rotationFromQuat(maths::quat(rotMAR)) * maths::mat4::scale(scaMAR);

		float* iteratorGLM{ glm::value_ptr(recGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == recMAR[i]);
		}

		glm::vec3 decPosGLM, decRotGLM, decScaGLM;
		maths::vec3 decPosMAR, decRotMAR, decScaMAR;
		
		test_glm::DecomposeTransform(recGLM, decPosGLM, decRotGLM, decScaGLM);
		maths::mat4::decompose(recMAR, decPosMAR, decRotMAR, decScaMAR);

		ASSERT_TRUE((decPosGLM.x - FLT_EPSILON) <= pos[0] && pos[0] <= (decPosGLM.x + FLT_EPSILON));
		ASSERT_TRUE((decPosGLM.y - FLT_EPSILON) <= pos[1] && pos[1] <= (decPosGLM.y + FLT_EPSILON));
		ASSERT_TRUE((decPosGLM.z - FLT_EPSILON) <= pos[2] && pos[2] <= (decPosGLM.z + FLT_EPSILON));
		ASSERT_TRUE((decPosMAR.x - FLT_EPSILON) <= decPosGLM.x && decPosGLM.x <= (decPosMAR.x + FLT_EPSILON));
		ASSERT_TRUE((decPosMAR.y - FLT_EPSILON) <= decPosGLM.y && decPosGLM.y <= (decPosMAR.y + FLT_EPSILON));
		ASSERT_TRUE((decPosMAR.z - FLT_EPSILON) <= decPosGLM.z && decPosGLM.z <= (decPosMAR.z + FLT_EPSILON));

		ASSERT_TRUE((decRotGLM.x - FLT_EPSILON) <= rot[0] && rot[0] <= (decRotGLM.x + FLT_EPSILON));
		ASSERT_TRUE((decRotGLM.y - FLT_EPSILON) <= rot[1] && rot[1] <= (decRotGLM.y + FLT_EPSILON));
		ASSERT_TRUE((decRotGLM.z - FLT_EPSILON) <= rot[2] && rot[2] <= (decRotGLM.z + FLT_EPSILON));
		ASSERT_TRUE((decRotMAR.x - FLT_EPSILON) <= decRotGLM.x && decRotGLM.x <= (decRotMAR.x + FLT_EPSILON));
		ASSERT_TRUE((decRotMAR.y - FLT_EPSILON) <= decRotGLM.y && decRotGLM.y <= (decRotMAR.y + FLT_EPSILON));
		ASSERT_TRUE((decRotMAR.z - FLT_EPSILON) <= decRotGLM.z && decRotGLM.z <= (decRotMAR.z + FLT_EPSILON));

		ASSERT_TRUE((decScaGLM.x - FLT_EPSILON) <= sca[0] && sca[0] <= (decScaGLM.x + FLT_EPSILON));
		ASSERT_TRUE((decScaGLM.y - FLT_EPSILON) <= sca[1] && sca[1] <= (decScaGLM.y + FLT_EPSILON));
		ASSERT_TRUE((decScaGLM.z - FLT_EPSILON) <= sca[2] && sca[2] <= (decScaGLM.z + FLT_EPSILON));
		ASSERT_TRUE((decScaMAR.x - FLT_EPSILON) <= decScaGLM.x && decScaGLM.x <= (decScaMAR.x + FLT_EPSILON));
		ASSERT_TRUE((decScaMAR.y - FLT_EPSILON) <= decScaGLM.y && decScaGLM.y <= (decScaMAR.y + FLT_EPSILON));
		ASSERT_TRUE((decScaMAR.z - FLT_EPSILON) <= decScaGLM.z && decScaGLM.z <= (decScaMAR.z + FLT_EPSILON));
	}
	{
		constexpr float pos[3]{ 21.37f, 45.245f, 456.1f };
		constexpr float rot[3]{ 6.19f, 1.66f, 8.25f };
		constexpr float sca[3]{ 25.f, 100.f, 3.f };

		const glm::vec3 posGLM{ pos[0], pos[1], pos[2] };
		const glm::vec3 rotGLM{ rot[0], rot[1], rot[2] };
		const glm::vec3 scaGLM{ sca[0], sca[1], sca[2] };

		const maths::vec3 posMAR{ pos[0], pos[1], pos[2] };
		const maths::vec3 rotMAR{ rot[0], rot[1], rot[2] };
		const maths::vec3 scaMAR{ sca[0], sca[1], sca[2] };

		recGLM = glm::translate(glm::mat4(1.f), posGLM) * glm::toMat4(glm::quat(rotGLM)) * glm::scale(glm::mat4(1.f), scaGLM);
		recMAR = maths::mat4::translation(posMAR) * maths::quat::rotationFromQuat(maths::quat(rotMAR)) * maths::mat4::scale(scaMAR);

		float* iteratorGLM{ glm::value_ptr(recGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == recMAR[i]);
		}

		glm::vec3 decPosGLM, decRotGLM, decScaGLM;
		maths::vec3 decPosMAR, decRotMAR, decScaMAR;

		test_glm::DecomposeTransform(recGLM, decPosGLM, decRotGLM, decScaGLM);
		maths::mat4::decompose(recMAR, decPosMAR, decRotMAR, decScaMAR);

		ASSERT_TRUE((decPosGLM.x - FLT_EPSILON) <= pos[0] && pos[0] <= (decPosGLM.x + FLT_EPSILON));
		ASSERT_TRUE((decPosGLM.y - FLT_EPSILON) <= pos[1] && pos[1] <= (decPosGLM.y + FLT_EPSILON));
		ASSERT_TRUE((decPosGLM.z - FLT_EPSILON) <= pos[2] && pos[2] <= (decPosGLM.z + FLT_EPSILON));
		ASSERT_TRUE((decPosMAR.x - FLT_EPSILON) <= decPosGLM.x && decPosGLM.x <= (decPosMAR.x + FLT_EPSILON));
		ASSERT_TRUE((decPosMAR.y - FLT_EPSILON) <= decPosGLM.y && decPosGLM.y <= (decPosMAR.y + FLT_EPSILON));
		ASSERT_TRUE((decPosMAR.z - FLT_EPSILON) <= decPosGLM.z && decPosGLM.z <= (decPosMAR.z + FLT_EPSILON));

		ASSERT_TRUE((decRotGLM.x - FLT_EPSILON) <= rot[0] && rot[0] <= (decRotGLM.x + FLT_EPSILON));
		ASSERT_TRUE((decRotGLM.y - FLT_EPSILON) <= rot[1] && rot[1] <= (decRotGLM.y + FLT_EPSILON));
		ASSERT_TRUE((decRotGLM.z - FLT_EPSILON) <= rot[2] && rot[2] <= (decRotGLM.z + FLT_EPSILON));
		ASSERT_TRUE((decRotMAR.x - FLT_EPSILON) <= decRotGLM.x && decRotGLM.x <= (decRotMAR.x + FLT_EPSILON));
		ASSERT_TRUE((decRotMAR.y - FLT_EPSILON) <= decRotGLM.y && decRotGLM.y <= (decRotMAR.y + FLT_EPSILON));
		ASSERT_TRUE((decRotMAR.z - FLT_EPSILON) <= decRotGLM.z && decRotGLM.z <= (decRotMAR.z + FLT_EPSILON));

		ASSERT_TRUE((decScaGLM.x - FLT_EPSILON) <= sca[0] && sca[0] <= (decScaGLM.x + FLT_EPSILON));
		ASSERT_TRUE((decScaGLM.y - FLT_EPSILON) <= sca[1] && sca[1] <= (decScaGLM.y + FLT_EPSILON));
		ASSERT_TRUE((decScaGLM.z - FLT_EPSILON) <= sca[2] && sca[2] <= (decScaGLM.z + FLT_EPSILON));
		ASSERT_TRUE((decScaMAR.x - FLT_EPSILON) <= decScaGLM.x && decScaGLM.x <= (decScaMAR.x + FLT_EPSILON));
		ASSERT_TRUE((decScaMAR.y - FLT_EPSILON) <= decScaGLM.y && decScaGLM.y <= (decScaMAR.y + FLT_EPSILON));
		ASSERT_TRUE((decScaMAR.z - FLT_EPSILON) <= decScaGLM.z && decScaGLM.z <= (decScaMAR.z + FLT_EPSILON));
	}
	{
		constexpr float pos[3]{ 6.19f, 1.66f, 10.25f };
		constexpr float rot[3]{ 25.f, 100.f, 3.f };
		constexpr float sca[3]{ 21.37f, 45.245f, 456.1f };

		const glm::vec3 posGLM{ pos[0], pos[1], pos[2] };
		const glm::vec3 rotGLM{ rot[0], rot[1], rot[2] };
		const glm::vec3 scaGLM{ sca[0], sca[1], sca[2] };

		const maths::vec3 posMAR{ pos[0], pos[1], pos[2] };
		const maths::vec3 rotMAR{ rot[0], rot[1], rot[2] };
		const maths::vec3 scaMAR{ sca[0], sca[1], sca[2] };

		recGLM = glm::translate(glm::mat4(1.f), posGLM) * glm::toMat4(glm::quat(rotGLM)) * glm::scale(glm::mat4(1.f), scaGLM);
		recMAR = maths::mat4::translation(posMAR) * maths::quat::rotationFromQuat(maths::quat(rotMAR)) * maths::mat4::scale(scaMAR);

		float* iteratorGLM{ glm::value_ptr(recGLM) };
		for (size_t i = 0; i < 16; i++) {
			ASSERT_TRUE(iteratorGLM[i] == recMAR[i]);
		}

		glm::vec3 decPosGLM, decRotGLM, decScaGLM;
		maths::vec3 decPosMAR, decRotMAR, decScaMAR;

		test_glm::DecomposeTransform(recGLM, decPosGLM, decRotGLM, decScaGLM);
		maths::mat4::decompose(recMAR, decPosMAR, decRotMAR, decScaMAR);

		ASSERT_TRUE((decPosGLM.x - FLT_EPSILON) <= pos[0] && pos[0] <= (decPosGLM.x + FLT_EPSILON));
		ASSERT_TRUE((decPosGLM.y - FLT_EPSILON) <= pos[1] && pos[1] <= (decPosGLM.y + FLT_EPSILON));
		ASSERT_TRUE((decPosGLM.z - FLT_EPSILON) <= pos[2] && pos[2] <= (decPosGLM.z + FLT_EPSILON));
		ASSERT_TRUE((decPosMAR.x - FLT_EPSILON) <= decPosGLM.x && decPosGLM.x <= (decPosMAR.x + FLT_EPSILON));
		ASSERT_TRUE((decPosMAR.y - FLT_EPSILON) <= decPosGLM.y && decPosGLM.y <= (decPosMAR.y + FLT_EPSILON));
		ASSERT_TRUE((decPosMAR.z - FLT_EPSILON) <= decPosGLM.z && decPosGLM.z <= (decPosMAR.z + FLT_EPSILON));

		ASSERT_TRUE((decRotGLM.x - FLT_EPSILON) <= rot[0] && rot[0] <= (decRotGLM.x + FLT_EPSILON));
		ASSERT_TRUE((decRotGLM.y - FLT_EPSILON) <= rot[1] && rot[1] <= (decRotGLM.y + FLT_EPSILON));
		ASSERT_TRUE((decRotGLM.z - FLT_EPSILON) <= rot[2] && rot[2] <= (decRotGLM.z + FLT_EPSILON));
		ASSERT_TRUE((decRotMAR.x - FLT_EPSILON) <= decRotGLM.x && decRotGLM.x <= (decRotMAR.x + FLT_EPSILON));
		ASSERT_TRUE((decRotMAR.y - FLT_EPSILON) <= decRotGLM.y && decRotGLM.y <= (decRotMAR.y + FLT_EPSILON));
		ASSERT_TRUE((decRotMAR.z - FLT_EPSILON) <= decRotGLM.z && decRotGLM.z <= (decRotMAR.z + FLT_EPSILON));

		ASSERT_TRUE((decScaGLM.x - FLT_EPSILON) <= sca[0] && sca[0] <= (decScaGLM.x + FLT_EPSILON));
		ASSERT_TRUE((decScaGLM.y - FLT_EPSILON) <= sca[1] && sca[1] <= (decScaGLM.y + FLT_EPSILON));
		ASSERT_TRUE((decScaGLM.z - FLT_EPSILON) <= sca[2] && sca[2] <= (decScaGLM.z + FLT_EPSILON));
		ASSERT_TRUE((decScaMAR.x - FLT_EPSILON) <= decScaGLM.x && decScaGLM.x <= (decScaMAR.x + FLT_EPSILON));
		ASSERT_TRUE((decScaMAR.y - FLT_EPSILON) <= decScaGLM.y && decScaGLM.y <= (decScaMAR.y + FLT_EPSILON));
		ASSERT_TRUE((decScaMAR.z - FLT_EPSILON) <= decScaGLM.z && decScaGLM.z <= (decScaMAR.z + FLT_EPSILON));
	}
}

#endif
