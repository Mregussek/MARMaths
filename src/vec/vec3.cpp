/*
 *	Mateusz Rzeczyca
 *	Copyright (C) 2020 Mateusz Rzeczyca <info@mateuszrzeczyca.pl>
 */

#include "vec3.h"

namespace mar {
	namespace maths {

		vec3::vec3() {
			this->x = 0.0f;
			this->y = 0.0f;
			this->z = 0.0f;
		}

		vec3::vec3(const float& x, const float& y, const float& z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		vec3::vec3(const float&& x, const float&& y, const float&& z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		vec3& vec3::add(const float& f) {
			x += f;
			y += f;
			z += f;

			return *this;
		}

		vec3& vec3::subtract(const float& f) {
			x -= f;
			y -= f;
			z -= f;
		
			return *this;
		}

		vec3& vec3::multiply(const float& f) {
			x *= f;
			y *= f;
			z *= f;

			return *this;
		}

		vec3& vec3::divide(const float& f) {
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
		
		vec3 vec3::cross(const vec3& left, const vec3& right) {
			vec3 rtn;

			rtn.x = left.y * right.z - left.z * right.y;
			rtn.y = left.z * right.x - left.x * right.z;
			rtn.z = left.x * right.y - left.y * right.x;

			return rtn;
		}

		float vec3::dot(const vec3& other) {
			return dot(*this, other);
		}

		float vec3::dot(const vec3& left, const vec3& right) {
			return left.x * right.x + left.y * right.y + left.z * right.z;
		}

		vec3 vec3::normalize(const vec3& other) {
			float magnitude = sqrt((other.x * other.x) + (other.y * other.y) + (other.z * other.z));

			vec3 rtn{other.x / magnitude, other.y / magnitude, other.z / magnitude};

			return rtn;
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

		vec3& vec3::operator+=(const float& other) {
			return add(other);
		}

		vec3& vec3::operator-=(const float& other) {
			return subtract(other);
		}

		vec3& vec3::operator*=(const float& other) {
			return multiply(other);
		}

		vec3& vec3::operator/=(const float& other) {
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
