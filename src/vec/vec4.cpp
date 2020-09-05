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


namespace mar { 
	namespace maths {

		vec4::vec4() {
			this->x = 0.0f;
			this->y = 0.0f;
			this->z = 0.0f;
			this->w = 0.0f;
		}

		vec4::vec4(const vec3& v, float w) {
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			this->w = w;
		}

		vec4::vec4(float x, float y, float z, float w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		vec4& vec4::add(float f) {
			x += f;
			y += f;
			z += f;
			w += f;

			return *this;
		}

		vec4& vec4::subtract(float f) {
			x -= f;
			y -= f;
			z -= f;
			w -= f;

			return *this;
		}

		vec4& vec4::multiply(float f) {
			x *= f;
			y *= f;
			z *= f;
			w *= f;

			return *this;
		}

		vec4& vec4::divide(float f) {
			if (f == 0.f) return *this;

			x /= f;
			y /= f;
			z /= f;
			w /= f;

			return *this;
		}

		vec4& vec4::add(const vec4& other) {
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return *this;
		}

		vec4& vec4::subtract(const vec4& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;

			return *this;
		}

		vec4& vec4::multiply(const vec4& other) {
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;

			return *this;
		}

		vec4& vec4::divide(const vec4& other) {
			if (other.x == 0 || other.y == 0 || other.z == 0 || other.w == 0) {
				return *this;
			}

			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;

			return *this;
		}

		float vec4::dot(const vec4& other) {
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

		vec4 vec4::normalize(const vec4& other) {
			float magnitude = other.length();

			vec4 rtn{ other.x / magnitude, other.y / magnitude, other.z / magnitude, other.w / magnitude };

			return rtn;
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

		bool vec4::operator==(const vec4& other) {
			return x == other.x && y == other.y && z == other.z && w == other.w;
		}

		bool vec4::operator!=(const vec4& other) {
			return !(*this == other);
		}

		const float& vec4::operator[](unsigned int index) const {
			switch (index) {
			case 0: return x; break;
			case 1: return y; break;
			case 2: return z; break;
			case 3: return w; break;
			default:
				static_assert(true, "[MARMath Error] Trying to call index > 3!");
				return x;
			}
		}

		float& vec4::operator[](unsigned int index) {
			switch (index) {
			case 0: return x; break;
			case 1: return y; break;
			case 2: return z; break;
			case 3: return w; break;
			default:
				static_assert(true, "[MARMath Error] Trying to call index > 3!");
				return x;
			}
		}

		std::ostream& operator<<(std::ostream& stream, const vec4& vector) {
			stream << "vec4: ( " << vector.x << " , " << vector.y << " , " << 
				vector.z << " , " << vector.w << " )";

			return stream;
		}

	}
}
