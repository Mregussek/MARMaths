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


#include "vec4.h"
#include "vec3.h"
#include "basic.h"


namespace marengine::maths {


	vec4::vec4() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 0.0f;
	}

	vec4::vec4(vec3 v, float _w) {
		x = v.x;
		y = v.y;
		z = v.z;
		w = _w;
	}

	vec4::vec4(float _x, float _y, float _z, float _w) {
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	vec4 vec4::add(float f) const {
		return {
			x + f,
			y + f,
			z + f,
			w + f
		};
	}

	vec4 vec4::subtract(float f) const {
		return {
			x - f,
			y - f,
			z - f,
			w - f
		};
	}

	vec4 vec4::multiply(float f) const {
		return {
			x * f,
			y * f,
			z * f,
			w * f
		};
	}

	vec4 vec4::divide(float f) const {
		if (f == 0.f) {
			static_assert(true, "vec4::divide(0.f) - cannot divide by zero!");
		};
		return {
			x / f,
			y / f,
			z / f,
			w / f
		};
	}

	vec4 vec4::add(const vec4& other) const {
		return {
			x + other.x,
			y + other.y,
			z + other.z,
			w + other.w
		};
	}

	vec4 vec4::subtract(const vec4& other) const {
		return {
			x - other.x,
			y - other.y,
			z - other.z,
			w - other.w
		};
	}

	vec4 vec4::multiply(const vec4& other) const {
		return {
			x * other.x,
			y * other.y,
			z * other.z,
			w * other.w
		};
	}

	vec4 vec4::divide(const vec4& other) const {
		if (other.x == 0.f || other.y == 0.f || other.z == 0.f || other.w == 0.f) {
			static_assert(true, "vec4::divide({0.f, 0.f, 0.f, 0.f}) - cannot divide by zero!");
		}
		return {
			x / other.x,
			y / other.y,
			z / other.z,
			w / other.w
		};
	}

	float vec4::dot(const vec4& other) const {
		return dot(*this, other);
	}

	float vec4::dot(const vec4& left, const vec4& right) {
		return left.x * right.x + left.y * right.y + left.z * right.z + left.w * right.w;
	}

	float vec4::length() const {
		return basic::square(dot(*this, *this));
	}

	float vec4::length(const vec4& v) {
		return v.length();
	}

	vec4 vec4::normalize() const {
		return normalize(*this);
	}

	vec4 vec4::normalize(const vec4& other) {
		const float magnitude = other.length();

		vec4 rtn{ other.x / magnitude, other.y / magnitude, other.z / magnitude, other.w / magnitude };

		return rtn;
	}

	const float* vec4::value_ptr(const std::vector<vec4>& vec) {
		return &(*vec.data()).x;
	}

	const float* vec4::value_ptr(const vec4& vec) {
		return &vec.x;
	}

	vec4 operator+(vec4 left, float right) {
		return left.add(right);
	}

	vec4 operator-(vec4 left, float right) {
		return left.subtract(right);
	}

	vec4 operator*(vec4 left, float right) {
		return left.multiply(right);
	}

	vec4 operator/(vec4 left, float right) {
		return left.divide(right);
	}

	vec4 operator+(vec4 left, const vec4& right) {
		return left.add(right);
	}

	vec4 operator-(vec4 left, const vec4& right) {
		return left.subtract(right);
	}

	vec4 operator*(vec4 left, const vec4& right) {
		return left.multiply(right);
	}

	vec4 operator/(vec4 left, const vec4& right) {
		return left.divide(right);
	}

	vec4& vec4::operator+=(float other) {
		return add(other);
	}

	vec4& vec4::operator-=(float other) {
		return subtract(other);
	}

	vec4& vec4::operator*=(float other) {
		return multiply(other);
	}

	vec4& vec4::operator/=(float other) {
		return divide(other);
	}

	vec4& vec4::operator+=(const vec4& other) {
		return add(other);
	}

	vec4& vec4::operator-=(const vec4& other) {
		return subtract(other);
	}

	vec4& vec4::operator*=(const vec4& other) {
		return multiply(other);
	}

	vec4& vec4::operator/=(const vec4& other) {
		return divide(other);
	}

	bool vec4::operator==(const vec4& other) const {
		return x == other.x && y == other.y && z == other.z && w == other.w;
	}

	bool vec4::operator!=(const vec4& other) const {
		return !(*this == other);
	}


}
