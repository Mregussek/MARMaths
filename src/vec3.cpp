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


#include "vec3.h"
#include "vec4.h"
#include "basic.h"


namespace marengine::maths {


	vec3::vec3() {
		x = 0.f;
		y = 0.f;
		z = 0.f;
	}

	vec3::vec3(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}

	vec3::vec3(const vec4& v) {
		x = v.x;
		y = v.y;
		z = v.z;
	}

	vec3 vec3::add(float f) const {
		return {
			x + f,
			y + f,
			z + f
		};
	}

	vec3 vec3::subtract(float f) const {
		return {
			x - f,
			y - f,
			z - f
		};
	}

	vec3 vec3::multiply(float f) const {
		return {
			x * f,
			y * f,
			z * f
		};
	}

	vec3 vec3::divide(float f) const {
		if (f == 0.f) {
			static_assert(true, "vec3::divide(0.f) - cannot divide by zero!");
		};
		return {
			x / f,
			y / f,
			z / f
		};
	}


	vec3 vec3::add(vec3 other) const {
		return {
			x + other.x,
			y + other.y,
			z + other.z
		};
	}

	vec3 vec3::subtract(vec3 other) const {
		return {
			x - other.x,
			y - other.y,
			z - other.z
		};
	}

	vec3 vec3::multiply(vec3 other) const {
		return {
			x * other.x,
			y * other.y,
			z * other.z
		};
	}

	vec3 vec3::divide(vec3 other) const {
		if (other.x == 0.f || other.y == 0.f || other.z == 0.f) {
			static_assert(true, "vec3::divide({0.f, 0.f, 0.f}) - cannot divide by zero!");
		}
		return {
			x / other.x,
			y / other.y,
			z / other.z
		};
	}

	vec3 vec3::cross(vec3 other) const {
		return cross(*this, other);
	}
	
	vec3 vec3::cross(vec3 x, vec3 y) {
		return {
			x.y * y.z - y.y * x.z,
			x.z * y.x - y.z * x.x,
			x.x * y.y - y.x * x.y
		};
	}

	float vec3::dot(vec3 other) const {
		return dot(*this, other);
	}

	float vec3::dot(vec3 left, vec3 right) {
		const vec3 tmp{ left * right };
		return tmp.x + tmp.y + tmp.z;//left.x * right.x + left.y * right.y + left.z * right.z;
	}

	float vec3::length() const {
		return length(*this);
	}

	float vec3::length(vec3 v) {
		return basic::square(dot(v, v));
	}

	vec3 vec3::normalize() const {
		return normalize(*this);
	}

	vec3 vec3::normalize(vec3 other) {
		const float magnitude{ length(other) };
		if (magnitude == 0.f) {
			static_assert(true, "vec3::normalize(magnitude=0.f) - cannot divide by zero!");
		}
		const float inverseMagnitude{ 1.f / magnitude };
		return other * inverseMagnitude;
	}

	float vec3::angleBetween(vec3 other) const {
		return angleBetween(*this, other);
	}

	float vec3::angleBetween(vec3 left, vec3 right) {
		const float angle{ dot(left, right) };
		const float len{ left.length() * right.length() };
		if (len == 0.f) {
			static_assert(true, "vec3::angleBetween(len=0.f) - cannot divide by zero!");
		}
		return acosf(angle / len);
	}

	vec3 vec3::projectOnto(vec3 other) const {
		return projectOnto(*this, other);
	}

	vec3 vec3::projectOnto(vec3 left, vec3 right) {
		const float magnitude{ right.length() };
		if (magnitude == 0.f) {
			static_assert(true, "vec3::projectOnto(magnitude=0.f) - cannot divide by zero!");
		}
		const auto normalizedRight{ right / magnitude };
		return normalizedRight * dot(left, right);
	}

	bool vec3::sameSide(vec3 p1, vec3 p2, vec3 a, vec3 b) {
		const vec3 cp1{ cross(b - a, p1 - a) };
		const vec3 cp2{ cross(b - a, p2 - a) };
		const bool onTheSameSide{ dot(cp1, cp2) >= 0.f };
		if (onTheSameSide) { 
			return true; 
		}

		return false;
	}

	vec3 vec3::getTriangleNormal(vec3 t1, vec3 t2, vec3 t3) {
		const vec3 u{ t2 - t1 };
		const vec3 v{ t3 - t1 };
		return cross(u, v);
	}

	bool vec3::inTriangle(vec3 point, vec3 t1, vec3 t2, vec3 t3) {
		const bool withTrianglePrism{
			sameSide(point, t1, t2, t3) &&
			sameSide(point, t2, t1, t3) &&
			sameSide(point, t3, t1, t2)
		};
		if (!withTrianglePrism) { 
			return false; 
		}
		const vec3 normal{ getTriangleNormal(t1, t2, t3) };
		const vec3 proj{ projectOnto(point, normal) };

		const bool isWithinTriangle{ proj.length() == 0.f };
		if (isWithinTriangle) {
			return true; 
		}
		
		return false;
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

	vec3 operator+(vec3 left, vec3 right) {
		return left.add(right);
	}

	vec3 operator-(vec3 left, vec3 right) {
		return left.subtract(right);
	}

	vec3 operator*(vec3 left, vec3 right) {
		return left.multiply(right);
	}

	vec3 operator/(vec3 left, vec3 right) {
		return left.divide(right);
	}

	bool vec3::operator==(vec3 other) const {
		return x == other.x && y == other.y && z == other.z;
	}

	bool vec3::operator!=(vec3 other) const {
		return !(*this == other);
	}


}
