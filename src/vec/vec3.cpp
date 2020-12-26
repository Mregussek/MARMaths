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


#include "vec3.h"
#include "vec4.h"
#include "../math_func/basic.h"


namespace marengine::maths {


	vec3::vec3() {
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
	}

	vec3::vec3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3::vec3(const vec4& v) {
		x = v.x;
		y = v.y;
		z = v.z;
	}

	vec3& vec3::add(float f) {
		x += f;
		y += f;
		z += f;

		return *this;
	}

	vec3& vec3::subtract(float f) {
		x -= f;
		y -= f;
		z -= f;
	
		return *this;
	}

	vec3& vec3::multiply(float f) {
		x *= f;
		y *= f;
		z *= f;

		return *this;
	}

	vec3& vec3::divide(float f) {
		if (f == 0.f) return *this;

		x /= f;
		y /= f;
		z /= f;

		return *this;
	}


	vec3& vec3::add(const vec3& other) {
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	vec3& vec3::subtract(const vec3& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	vec3& vec3::multiply(const vec3& other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;
	}

	vec3& vec3::divide(const vec3& other) {
		if (other.x == 0 || other.y == 0 || other.z == 0) {
			return *this;
		}

		x /= other.x;
		y /= other.y;
		z /= other.z;

		return *this;
	}

	vec3 vec3::cross(const vec3& other) const {
		return cross(*this, other);
	}
	
	vec3 vec3::cross(const vec3& x, const vec3& y) {
		return {
			x.y * y.z - y.y * x.z,
			x.z * y.x - y.z * x.x,
			x.x * y.y - y.x * x.y
		};
	}

	float vec3::dot(const vec3& other) const {
		return dot(*this, other);
	}

	float vec3::dot(const vec3& left, const vec3& right) {
		return left.x * right.x + left.y * right.y + left.z * right.z;
	}

	float vec3::length() const {
		return basic::square( dot(*this, *this) );
	}

	float vec3::length(vec3& v) {
		return v.length();
	}

	vec3 vec3::normalize(const vec3& other) {
		const float inverse_square = 1.f / basic::square(dot(other, other));

		return other * inverse_square;
	}

	float vec3::angleBetween(const vec3& other) const {
		return angleBetween(*this, other);
	}

	float vec3::angleBetween(const vec3& left, const vec3& right) {
		float angle{ dot(left, right) };
		angle /= (left.length() * right.length());
		return acosf(angle);
	}

	vec3 vec3::projectOnto(const vec3& other) const {
		return projectOnto(*this, other);
	}

	vec3 vec3::projectOnto(const vec3& left, const vec3& right) {
		const auto normalized{ right / right.length() };
		return normalized * dot(left, right);
	}

	bool vec3::sameSide(const vec3& p1, const vec3& p2, const vec3& a, const vec3& b) {
		const vec3 cp1{ cross(b - a, p1 - a) };
		const vec3 cp2{ cross(b - a, p2 - a) };

		if (dot(cp1, cp2) >= 0.f) { return true; }
		else { return false; }
	}

	vec3 vec3::getTriangleNormal(const vec3& t1, const vec3& t2, const vec3& t3) {
		const vec3 u{ t2 - t1 };
		const vec3 v{ t3 - t1 };

		return cross(u, v);
	}

	bool vec3::inTriangle(const vec3& point, const vec3& t1, const vec3& t2, const vec3& t3) {
		const bool withTrianglePrism{
			sameSide(point, t1, t2, t3) &&
			sameSide(point, t2, t1, t3) &&
			sameSide(point, t3, t1, t2)
		};

		if (!withTrianglePrism) { return false; }

		const auto normal{ getTriangleNormal(t1, t2, t3) };
		const auto proj{ projectOnto(point, normal) };

		if (proj.length() == 0.f) { return true; }
		else { return false; }
	}

	const float* vec3::value_ptr(const std::vector<vec3>& vec) {
		return &(*vec.data()).x;
	}

	const float* vec3::value_ptr(const vec3& vec) {
		return &vec.x;
	}

	float* vec3::value_ptr_nonconst(vec3& vec) {
		return  &vec.x;
	}

	vec3 operator+(vec3 left, float right) {
		return left.add(right);
	}

	vec3 operator-(vec3 left, float right) {
		return left.subtract(right);
	}

	vec3 operator*(vec3 left, float right) {
		return left.multiply(right);
	}

	vec3 operator/(vec3 left, float right) {
		return left.divide(right);
	}

	vec3 operator+(vec3 left, const vec3& right) {
		return left.add(right);
	}

	vec3 operator-(vec3 left, const vec3& right) {
		return left.subtract(right);
	}

	vec3 operator*(vec3 left, const vec3& right) {
		return left.multiply(right);
	}

	vec3 operator/(vec3 left, const vec3& right) {
		return left.divide(right);
	}

	vec3& vec3::operator+=(float other) {
		return add(other);
	}

	vec3& vec3::operator-=(float other) {
		return subtract(other);
	}

	vec3& vec3::operator*=(float other) {
		return multiply(other);
	}

	vec3& vec3::operator/=(float other) {
		return divide(other);
	}

	vec3& vec3::operator+=(const vec3& other) {
		return add(other);
	}

	vec3& vec3::operator-=(const vec3& other) {
		return subtract(other);
	}

	vec3& vec3::operator*=(const vec3& other) {
		return multiply(other);
	}

	vec3& vec3::operator/=(const vec3& other) {
		return divide(other);
	}

	bool vec3::operator==(const vec3& other) const {
		return x == other.x && y == other.y && z == other.z;
	}

	bool vec3::operator!=(const vec3& other) const {
		return !(*this == other);
	}


}
