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


#include "mat4.h"
#include "vec4.h"
#include "vec3.h"
#include "trig.h"
#include "basic.h"
#include "quat.h"


namespace marengine::maths {


	mat4::mat4() {
		for (int i = 0; i < 4 * 4; i++) {
			elements[i] = 0.0f;
		}
	}

	mat4::mat4(float diagonal) {
		for (int i = 0; i < 4 * 4; i++) {
			elements[i] = 0.0f;
		}
		for (int i = 0; i < 4; i++) {
			elements[i + i * 4] = diagonal;
		}
	}

	vec4 mat4::getColumn4(size_t index) const {
		return {
			elements[0 + index * 4],
			elements[1 + index * 4],
			elements[2 + index * 4],
			elements[3 + index * 4]
		};
	}

	vec3 mat4::getColumn3(size_t index) const {
		return {
			elements[0 + index * 4],
			elements[1 + index * 4],
			elements[2 + index * 4]
		};
	}

	vec4 mat4::getRow4(size_t index) const {
		return {
			elements[index + 0 * 4],
			elements[index + 1 * 4],
			elements[index + 2 * 4],
			elements[index + 3 * 4]
		};
	}

	vec3 mat4::getRow3(size_t index) const {
		return {
			elements[index + 0 * 4],
			elements[index + 1 * 4],
			elements[index + 2 * 4]
		};
	}

	mat4 mat4::identity() {
		return mat4(1.0f);
	}

	mat4 mat4::multiply(const mat4& other) const {
		mat4 rtn;

		const vec4 left_one{ getColumn4(0) };
		const vec4 left_two{ getColumn4(1) };
		const vec4 left_three{ getColumn4(2) };
		const vec4 left_four{ getColumn4(3) };

		const vec4 col1{ left_one * other[0 + 0 * 4] + left_two * other[1 + 0 * 4] + left_three * other[2 + 0 * 4] + left_four * other[3 + 0 * 4] };
		const vec4 col2{ left_one * other[0 + 1 * 4] + left_two * other[1 + 1 * 4] + left_three * other[2 + 1 * 4] + left_four * other[3 + 1 * 4] };
		const vec4 col3{ left_one * other[0 + 2 * 4] + left_two * other[1 + 2 * 4] + left_three * other[2 + 2 * 4] + left_four * other[3 + 2 * 4] };
		const vec4 col4{ left_one * other[0 + 3 * 4] + left_two * other[1 + 3 * 4] + left_three * other[2 + 3 * 4] + left_four * other[3 + 3 * 4] };

		rtn[0 + 0 * 4] = col1.x;
		rtn[1 + 0 * 4] = col1.y;
		rtn[2 + 0 * 4] = col1.z;
		rtn[3 + 0 * 4] = col1.w;

		rtn[0 + 1 * 4] = col2.x;
		rtn[1 + 1 * 4] = col2.y;
		rtn[2 + 1 * 4] = col2.z;
		rtn[3 + 1 * 4] = col2.w;

		rtn[0 + 2 * 4] = col3.x;
		rtn[1 + 2 * 4] = col3.y;
		rtn[2 + 2 * 4] = col3.z;
		rtn[3 + 2 * 4] = col3.w;

		rtn[0 + 3 * 4] = col4.x;
		rtn[1 + 3 * 4] = col4.y;
		rtn[2 + 3 * 4] = col4.z;
		rtn[3 + 3 * 4] = col4.w;

		return rtn;
	}

	vec4 mat4::multiply(const vec4& other) const {
		return {
			elements[0 + 0 * 4] + other.x + elements[0 + 1 * 4] + other.y + elements[0 + 2 * 4] + other.z + elements[0 + 3 * 4] + other.w,
			elements[1 + 0 * 4] + other.x + elements[1 + 1 * 4] + other.y + elements[1 + 2 * 4] + other.z + elements[1 + 3 * 4] + other.w,
			elements[2 + 0 * 4] + other.x + elements[2 + 1 * 4] + other.y + elements[2 + 2 * 4] + other.z + elements[2 + 3 * 4] + other.w,
			elements[3 + 0 * 4] + other.x + elements[3 + 1 * 4] + other.y + elements[3 + 2 * 4] + other.z + elements[3 + 3 * 4] + other.w
		};
	}

	mat4 mat4::multiply(float other) const {
		mat4 rtn{ *this };
		for (size_t i = 0; i < 16; i++) {
			rtn.elements[i] *= other;
		}
		return rtn;
	}

	mat4 mat4::orthographic(float left, float right, float top, float bottom, float near, float far) {
		mat4 result(1.0f);

		result.elements[0 + 0 * 4] = 2.0f / (right - left);
		result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
		result.elements[2 + 2 * 4] = 2.0f / (near - far);

		result.elements[0 + 3 * 4] = (left + right) / (left - right);
		result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
		result.elements[2 + 3 * 4] = (far + near) / (far - near);

		return result;
	}

	mat4 mat4::perspective(float fov, float aspectRatio, float near, float far) {
		mat4 result(1.0f);

		const float tanfov2{ trig::tangent(fov / 2) };

		result.elements[0 + 0 * 4] = 1 / (aspectRatio * tanfov2);
		result.elements[1 + 1 * 4] = 1 / tanfov2;
		result.elements[2 + 2 * 4] = - ((far + near) / (far - near));
		result.elements[3 + 2 * 4] = -1.0f;
		result.elements[2 + 3 * 4] = - ((2 * far * near) / (far - near));

		return result;
	}

	mat4 mat4::lookAt(vec3 eye, vec3 center, vec3 y) {
		const vec3 fwd{ vec3::normalize(center - eye) };
		const vec3 side{ vec3::normalize(vec3::cross(fwd, y)) };
		const vec3 up{ vec3::cross(side, fwd) };

		mat4 rtn;

		rtn[0 + 0 * 4] = side.x;
		rtn[1 + 0 * 4] = up.x;
		rtn[2 + 0 * 4] = -fwd.x;
		rtn[3 + 0 * 4] = 0.f;
		rtn[0 + 1 * 4] = side.y;
		rtn[1 + 1 * 4] = up.y;
		rtn[2 + 1 * 4] = -fwd.y;
		rtn[3 + 1 * 4] = 0.f;
		rtn[0 + 2 * 4] = side.z;
		rtn[1 + 2 * 4] = up.z;
		rtn[2 + 2 * 4] = -fwd.z;
		rtn[3 + 2 * 4] = 0.f;
		rtn[0 + 3 * 4] = -vec3::dot(side, eye);
		rtn[1 + 3 * 4] = -vec3::dot(up, eye);
		rtn[2 + 3 * 4] = vec3::dot(fwd, eye);
		rtn[3 + 3 * 4] = 1.0f;

		return rtn;
	}

	mat4 mat4::translation(vec3 trans) {
		mat4 result(1.0f);

		result.elements[0 + 3 * 4] = trans.x;
		result.elements[1 + 3 * 4] = trans.y;
		result.elements[2 + 3 * 4] = trans.z;

		return result;
	}

	mat4 mat4::rotation(float angle, vec3 axis) {
		mat4 result(1.0f);

		const float cosine{ trig::cosine(angle) };
		const float sine{ trig::sine(angle) };
		const float neg_cosine{ 1.0f - cosine };

		const vec3 ax{ vec3::normalize(axis) };
		const float x{ ax.x };
		const float y{ ax.y };
		const float z{ ax.z };

		result.elements[0 + 0 * 4] = cosine + x * x * neg_cosine;
		result.elements[1 + 0 * 4] = y * x * neg_cosine + z * sine;
		result.elements[2 + 0 * 4] = z * x * neg_cosine - y * sine;
			 
		result.elements[0 + 1 * 4] = x * y * neg_cosine - z * sine;
		result.elements[1 + 1 * 4] = cosine + y * y * neg_cosine;
		result.elements[2 + 1 * 4] = z * y * neg_cosine + x * sine;
		
		result.elements[0 + 2 * 4] = x * z * neg_cosine + y * sine;
		result.elements[1 + 2 * 4] = y * z * neg_cosine - x * sine;
		result.elements[2 + 2 * 4] = cosine + z * z * neg_cosine;

		return result;
	}

	mat4 mat4::scale(vec3 scal) {
		mat4 result(1.0f);

		result.elements[0 + 0 * 4] = scal.x;
		result.elements[1 + 1 * 4] = scal.y;
		result.elements[2 + 2 * 4] = scal.z;

		return result;
	}

	mat4 mat4::inverse(const mat4& m) {
		mat4 inv;

		inv[0] = m[5]  * m[10] * m[15] - m[5]  * m[11] * m[14] -
				 m[9]  * m[6]  * m[15] + m[9]  * m[7]  * m[14] +
				 m[13] * m[6]  * m[11] - m[13] * m[7]  * m[10];

		inv[4] = -m[4]  * m[10] * m[15] + m[4]  * m[11] * m[14] +
				  m[8]  * m[6]  * m[15] - m[8]  * m[7]  * m[14] -
				  m[12] * m[6]  * m[11] + m[12] * m[7]  * m[10];

		inv[8] = m[4]  * m[9]  * m[15] - m[4]  * m[11] * m[13] -
				 m[8]  * m[5]  * m[15] + m[8]  * m[7]  * m[13] +
				 m[12] * m[5]  * m[11] - m[12] * m[7]  * m[9];

		inv[12] = -m[4]  * m[9]  * m[14] + m[4]  * m[10] * m[13] +
				   m[8]  * m[5]  * m[14] - m[8]  * m[6]  * m[13] -
				   m[12] * m[5]  * m[10] + m[12] * m[6]  * m[9];

		inv[1] = -m[1]  * m[10] * m[15] + m[1]  * m[11] * m[14] +
				  m[9]  * m[2]  * m[15] - m[9]  * m[3]  * m[14] -
				  m[13] * m[2]  * m[11] + m[13] * m[3]  * m[10];

		inv[5] = m[0]  * m[10] * m[15] - m[0]  * m[11] * m[14] -
				 m[8]  * m[2]  * m[15] + m[8]  * m[3]  * m[14] +
				 m[12] * m[2]  * m[11] - m[12] * m[3]  * m[10];

		inv[9] = -m[0]  * m[9]  * m[15] + m[0]  * m[11] * m[13] +
				  m[8]  * m[1]  * m[15] - m[8]  * m[3]  * m[13] -
				  m[12] * m[1]  * m[11] + m[12] * m[3]  * m[9];

		inv[13] = m[0]  * m[9]  * m[14] - m[0]  * m[10] * m[13] -
				  m[8]  * m[1]  * m[14] + m[8]  * m[2]  * m[13] +
				  m[12] * m[1]  * m[10] - m[12] * m[2]  * m[9];

		inv[2] = m[1]  * m[6] * m[15] - m[1]  * m[7] * m[14] -
				 m[5]  * m[2] * m[15] + m[5]  * m[3] * m[14] +
				 m[13] * m[2] * m[7]  - m[13] * m[3] * m[6];

		inv[6] = -m[0]  * m[6] * m[15] + m[0]  * m[7] * m[14] +
				  m[4]  * m[2] * m[15] - m[4]  * m[3] * m[14] -
				  m[12] * m[2] * m[7]  + m[12] * m[3] * m[6];

		inv[10] = m[0]  * m[5] * m[15] - m[0]  * m[7] * m[13] -
				  m[4]  * m[1] * m[15] + m[4]  * m[3] * m[13] +
				  m[12] * m[1] * m[7]  - m[12] * m[3] * m[5];

		inv[14] = -m[0]  * m[5] * m[14] + m[0]  * m[6] * m[13] +
				   m[4]  * m[1] * m[14] - m[4]  * m[2] * m[13] -
				   m[12] * m[1] * m[6]  + m[12] * m[2] * m[5];

		inv[3] = -m[1] * m[6] * m[11] + m[1] * m[7] * m[10] +
				  m[5] * m[2] * m[11] - m[5] * m[3] * m[10] -
				  m[9] * m[2] * m[7]  + m[9] * m[3] * m[6];

		inv[7] = m[0] * m[6] * m[11] - m[0] * m[7] * m[10] -
				 m[4] * m[2] * m[11] + m[4] * m[3] * m[10] +
				 m[8] * m[2] * m[7]  - m[8] * m[3] * m[6];

		inv[11] = -m[0] * m[5] * m[11] + m[0] * m[7] * m[9] +
				   m[4] * m[1] * m[11] - m[4] * m[3] * m[9] -
				   m[8] * m[1] * m[7]  + m[8] * m[3] * m[5];

		inv[15] = m[0] * m[5] * m[10] - m[0] * m[6] * m[9] -
				  m[4] * m[1] * m[10] + m[4] * m[2] * m[9] +
				  m[8] * m[1] * m[6]  - m[8] * m[2] * m[5];

		const float det{ m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12] };
		if (det == 0.f) {
			static_assert(true, "Mat4 determinant is equal to 0!\n");
		}

		const float invDet{ 1.f / det };
		for (size_t i = 0; i < 16; i++) {
			inv[i] *= invDet;
		}

		return inv;
	}

	void mat4::orthonormalize(mat4& transform) {
		const vec4 col[]{
			transform.getColumn4(0).normalize(),
			transform.getColumn4(1).normalize(),
			transform.getColumn4(2).normalize()
		};

		transform[0 + 0 * 4] = col[0].x;
		transform[1 + 0 * 4] = col[0].x;
		transform[2 + 0 * 4] = col[0].x;

		transform[0 + 1 * 4] = col[1].x;
		transform[1 + 1 * 4] = col[1].x;
		transform[2 + 1 * 4] = col[1].x;

		transform[0 + 2 * 4] = col[2].x;
		transform[1 + 2 * 4] = col[2].x;
		transform[2 + 2 * 4] = col[2].x;
	}

	void mat4::orthonormalize() {
		orthonormalize(*this);
	}

	void mat4::decompose(const mat4& transform, vec3& translation, vec3& rotation, vec3& scale) {
		mat4 localMatrix(transform);

		if (basic::epsilonEqual(localMatrix[3 + 3 * 4], 0.f, FLT_EPSILON)) { return; }
		
		translation = localMatrix.getColumn3(3);
		scale = {
			localMatrix.getColumn3(0).length(),
			localMatrix.getColumn3(1).length(),
			localMatrix.getColumn3(2).length()
		};
		
		localMatrix[0 + 0 * 4] /= scale.x;
		localMatrix[1 + 0 * 4] /= scale.x;
		localMatrix[2 + 0 * 4] /= scale.x;
		
		localMatrix[0 + 1 * 4] /= scale.y;
		localMatrix[1 + 1 * 4] /= scale.y;
		localMatrix[2 + 1 * 4] /= scale.y;
		
		localMatrix[0 + 2 * 4] /= scale.z;
		localMatrix[1 + 2 * 4] /= scale.z;
		localMatrix[2 + 2 * 4] /= scale.z;

		rotation = vec3(quat::quatFromRotation1(localMatrix));
		//rotation = vec3(quat::quatFromRotation2(localMatrix));
	}

	void mat4::decompose(vec3& translation, vec3& rotation, vec3& scale) const {
		decompose(*this, translation, rotation, scale);
	}

	void mat4::recompose(mat4& transform, const vec3& translation, const vec3& rotation, const vec3& scale) {
		const vec4 rotRadians{ 
			trig::toRadians(rotation.x), 
			trig::toRadians(rotation.y), 
			trig::toRadians(rotation.z),
			0.f
		};
		transform = mat4::translation(translation) 
		//    * mat4::rotation(rotRadians.x, { 1.f, 0.f, 0.f })
		//    * mat4::rotation(rotRadians.y, { 0.f, 1.f, 0.f })
		//    * mat4::rotation(rotRadians.z, { 0.f, 0.f, 1.f })
			* mat4::rotationFromQuat(rotRadians) 
			* mat4::scale(scale);
	}

	void mat4::recompose(const vec3& translation, const vec3& rotation, const vec3& scale) {
		recompose(*this, translation, rotation, scale);
	}

	mat4 mat4::rotationFromQuat(const vec4& quat) {
		mat4 rtn(1.f);

		const float xx(quat.x * quat.x);
		const float yy(quat.y * quat.y);
		const float zz(quat.z * quat.z);

		const float xz(quat.x * quat.z);
		const float xy(quat.x * quat.y);
		const float yz(quat.y * quat.z);

		const float wx(quat.w * quat.x);
		const float wy(quat.w * quat.y);
		const float wz(quat.w * quat.z);

		rtn[0 + 0 * 4] = 1.f - 2.f * (yy + zz);
		rtn[1 + 0 * 4] = 2.f * (xy - wz);
		rtn[2 + 0 * 4] = 2.f * (xz + wy);

		rtn[0 + 1 * 4] = 2.f * (xy + wz);
		rtn[1 + 1 * 4] = 1.f - 2.f * (xx + zz);
		rtn[2 + 1 * 4] = 2.f * (yz - wx);

		rtn[0 + 2 * 4] = 2.f * (xz - wy);
		rtn[1 + 2 * 4] = 2.f * (yz + wx);
		rtn[2 + 2 * 4] = 1.f - 2.f * (xx + yy);

		return rtn;
	}

	const float* mat4::value_ptr(const std::vector<mat4>& matrices) {
		return &(*matrices.data())[0];
	}

	const float* mat4::value_ptr(const mat4& matrix4x4) {
		return matrix4x4.elements;
	}

	float* mat4::value_ptr_nonconst(mat4& matrix4x4) {
		return matrix4x4.elements;
	}

	const float* mat4::value_ptr() const {
		return value_ptr(*this);
	}

	float* mat4::value_ptr_nonconst() {
		return value_ptr_nonconst(*this);
	}

	mat4 operator*(mat4 left, const mat4& right) {
		return left.multiply(right);
	}

	vec4 operator*(mat4 left, const vec4& right) {
		return left.multiply(right);
	}

	mat4 operator*(mat4 left, float right) {
		return left.multiply(right);
	}

	mat4 mat4::operator*=(const mat4& other) {
		return multiply(other);
	}

	vec4 mat4::operator*=(const vec4& other) {
		return multiply(other);
	}

	mat4 mat4::operator*=(float other) {
		return multiply(other);
	}

	const float& mat4::operator[](unsigned int index) const {
		if (index >= 4 * 4) {
			static_assert(true, "matrix.elements[index] out of bound!\n");
		}

		return elements[index];
	}

	float& mat4::operator[](unsigned int index) {
		if (index >= 4 * 4) {
			static_assert(true, "const matrix.elements[index] out of bound!\n");
		}

		return elements[index];
	}

		
}