/*
 *	Mateusz Rzeczyca
 *	Copyright (C) 2020 Mateusz Rzeczyca <info@mateuszrzeczyca.pl>
 */

#include "mat4.h"

namespace mar {
    namespace maths {

		mat4::mat4() {
			for (int i = 0; i < 4 * 4; i++)
				elements[i] = 0.0f;
		}

		mat4::mat4(float diagonal) {
			for(int i = 0; i < 4 * 4; i++)
				elements[i] = 0.0f;

			for (int i = 0; i < 4; i++)
				elements[i + i * 4] = diagonal;
		}

		mat4 mat4::identity() {
			return mat4(1.0f);
		}

		mat4& mat4::multiply(const mat4& other) {
			mat4 result;

			for (int y = 0; y < 4; y++) {
				for (int x = 0; x < 4; x++) {
					float sum = 0.0f;

					for (int i = 0; i < 4; i++) {
						sum += elements[x + i * 4] * other.elements[i + y * 4];
					}

					elements[x + y * 4] = sum;
				}
			}

			return *this;
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

			float tanfov2 = tan(fov / 2);

			result.elements[0 + 0 * 4] = 1 / (aspectRatio * tanfov2);
			result.elements[1 + 1 * 4] = 1 / tanfov2;
			result.elements[2 + 2 * 4] = - ((far + near) / (far - near));
			result.elements[3 + 2 * 4] = -1.0f;
			result.elements[2 + 3 * 4] = - ((2 * far * near) / (far - near));

			return result;
		}

		mat4 mat4::lookAt(const vec3&& eye, const vec3&& center, const vec3&& up) {
			vec3 e = eye;
			vec3 c = center;
			vec3 u = up;

			return lookAt(e, c, u);
		}

		mat4 mat4::lookAt(const vec3& eye, const vec3& center, const vec3& y) {
			vec3 fwd = vec3::normalize(center - eye);
			vec3 side = vec3::normalize(vec3::cross(fwd, y));
			vec3 up = vec3::cross(side, fwd);

			mat4 rtn;

			rtn[0 + 0 * 4] = side.x;
			rtn[1 + 0 * 4] = side.y;
			rtn[2 + 0 * 4] = side.z;
			rtn[3 + 0 * 4] = 0.f;
			rtn[0 + 1 * 4] = up.x;
			rtn[1 + 1 * 4] = up.y;
			rtn[2 + 1 * 4] = up.z;
			rtn[3 + 1 * 4] = 0.f;
			rtn[0 + 2 * 4] = -fwd.x;
			rtn[1 + 2 * 4] = -fwd.y;
			rtn[2 + 2 * 4] = -fwd.z;
			rtn[3 + 2 * 4] = 0.f;
			rtn[0 + 3 * 4] = -vec3::dot(side, eye);
			rtn[1 + 3 * 4] = -vec3::dot(up, eye);
			rtn[2 + 3 * 4] = vec3::dot(fwd, eye);
			rtn[3 + 3 * 4] = 1.0f;

			return rtn;
		}

		mat4 mat4::translation(const vec3& trans) {
			mat4 result(1.0f);

			result.elements[0 + 3 * 4] = trans.x;
			result.elements[1 + 3 * 4] = trans.y;
			result.elements[2 + 3 * 4] = trans.z;

			return result;
		}

		mat4 mat4::rotation(float angle, const vec3& axis) {
			mat4 result(1.0f);

			float r = Trig::toRadians(angle);
			float cosine = cos(r);
			float neg_cosine = 1.0f - cosine;
			float sine = sin(r);

			float x = axis.x;
			float y = axis.y;
			float z = axis.z;

			result.elements[0 + 0 * 4] = x * neg_cosine + cosine;
			result.elements[1 + 0 * 4] = y * x * neg_cosine + z * sine;
			result.elements[2 + 0 * 4] = x * z * neg_cosine - y * sine;

			result.elements[0 + 1 * 4] = x * y * neg_cosine - z * sine;
			result.elements[1 + 1 * 4] = y * neg_cosine + cosine;
			result.elements[2 + 1 * 4] = y * z * neg_cosine + x * sine;

			result.elements[0 + 2 * 4] = x * z * neg_cosine + y * sine;
			result.elements[1 + 2 * 4] = y * z * neg_cosine - x * sine;
			result.elements[2 + 2 * 4] = z * neg_cosine + cosine;

			return result;
		}

		mat4 mat4::scale(const vec3& scal) {
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = scal.x;
			result.elements[1 + 1 * 4] = scal.y;
			result.elements[2 + 2 * 4] = scal.z;

			return result;
		}

		mat4 operator*(mat4 left, const mat4& right) {
			return left.multiply(right);
		}

		mat4& mat4::operator*=(const mat4& other) {
			return multiply(other);
		}

		float& mat4::operator[](unsigned int index) {
			if (index >= 4 * 4) {
				std::cout << "Index out of bound!\n";
				return elements[0];
			}

			return elements[index];
		}

		const float& mat4::operator[](unsigned int index) const {
			if (index >= 4 * 4) {
				std::cout << "Index out of bound!\n";
				return elements[0];
			}

			return elements[index];
		}

		std::ostream& operator<<(std::ostream& stream, const mat4& matrix) {
			stream << "mat4:"
				<< " | " << matrix[0 + 0 * 4] << " " << matrix[0 + 1 * 4] << " " << matrix[0 + 2 * 4] << " " << matrix[0 + 3 * 4] << " |\n"
				<< "      | " << matrix[1 + 0 * 4] << " " << matrix[1 + 1 * 4] << " " << matrix[1 + 2 * 4] << " " << matrix[1 + 3 * 4] << " |\n"
				<< "      | " << matrix[2 + 0 * 4] << " " << matrix[2 + 1 * 4] << " " << matrix[2 + 2 * 4] << " " << matrix[2 + 3 * 4] << " |\n"
				<< "      | " << matrix[3 + 0 * 4] << " " << matrix[3 + 1 * 4] << " " << matrix[3 + 2 * 4] << " " << matrix[3 + 3 * 4] << " |";

			return stream;
		}
} }