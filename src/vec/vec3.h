/*
 *	Mateusz Rzeczyca
 *	Copyright (C) 2020 Mateusz Rzeczyca <info@mateuszrzeczyca.pl>
 */

#ifndef MAR_MATH_VEC3_H
#define MAR_MATH_VEC3_H

#include "../maths.h"

namespace mar {
	namespace maths {

		struct vec3 {

			float x;
			float y;
			float z;

			vec3();
			vec3(const float& x, const float& y, const float& z);
			vec3(const float&& x, const float&& y, const float&& z);

			vec3& add(const float& f);
			vec3& subtract(const float& f);
			vec3& multiply(const float& f);
			vec3& divide(const float& f);

			vec3& add(const vec3& other);
			vec3& subtract(const vec3& other);
			vec3& multiply(const vec3& other);
			vec3& divide(const vec3& other);

			vec3 cross(const vec3& other);
			static vec3 cross(const vec3& x, const vec3& y);

			float dot(const vec3& other);
			static float dot(const vec3& left, const vec3& right);

			static vec3 normalize(const vec3& other);

			friend vec3 operator+(vec3 left, float right);
			friend vec3 operator-(vec3 left, float right);
			friend vec3 operator*(vec3 left, float right);
			friend vec3 operator/(vec3 left, float right);

			friend vec3 operator+(vec3 left, const vec3& right);
			friend vec3 operator-(vec3 left, const vec3& right);
			friend vec3 operator*(vec3 left, const vec3& right);
			friend vec3 operator/(vec3 left, const vec3& right);

			vec3& operator+=(const float& other);
			vec3& operator-=(const float& other);
			vec3& operator*=(const float& other);
			vec3& operator/=(const float& other);

			vec3& operator+=(const vec3& other);
			vec3& operator-=(const vec3& other);
			vec3& operator*=(const vec3& other);
			vec3& operator/=(const vec3& other);

			bool operator==(const vec3& other);
			bool operator!=(const vec3& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);

		};

	}
}


#endif // !MAR_MATH_VEC3_H
