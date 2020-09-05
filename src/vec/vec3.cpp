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


namespace mar {
	namespace maths {

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

		vec3 vec3::cross(const vec3& other) {
			return cross(*this, other);
		}
		
		vec3 vec3::cross(const vec3& x, const vec3& y) {
			return {
				x.y* y.z - y.y * x.z,
				x.z* y.x - y.z * x.x,
				x.x* y.y - y.x * x.y
			};
		}

		float vec3::dot(const vec3& other) {
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
			float inverse_square = 1 / basic::square(dot(other, other));

			return other * inverse_square;
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

		bool vec3::operator==(const vec3& other) {
			return x == other.x && y == other.y && z == other.z;
		}

		bool vec3::operator!=(const vec3& other) {
			return !(*this == other);
		}

		std::ostream& operator<<(std::ostream& stream, const vec3& vector) {
			stream << "vec3: ( " << vector.x << " , " << vector.y << " , " <<
				vector.z << " )";

			return stream;
		}

	}
}
