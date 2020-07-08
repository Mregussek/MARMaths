/*
 *	Mateusz Rzeczyca
 *	Copyright (C) 2020 Mateusz Rzeczyca <info@mateuszrzeczyca.pl>
 */

#ifndef MAR_MATH_VEC4_H
#define MAR_MATH_VEC4_H

#include "../maths.h"

namespace mar { 
	namespace maths {

		struct vec4 {

			float x;
			float y;
			float z;
			float w;

			vec4();
			vec4(const float& x, const float& y, const float& z, const float& w);
			vec4(const float&& x, const float&& y, const float&& z, const float&& w);

			vec4& add(const float& f);
			vec4& subtract(const float& f);
			vec4& multiply(const float& f);
			vec4& divide(const float& f);

			vec4& add(const vec4& other);
			vec4& subtract(const vec4& other);
			vec4& multiply(const vec4& other);
			vec4& divide(const vec4& other);

			static vec4 normalize(const vec4& other);

			friend vec4 operator+(vec4 left, float right);
			friend vec4 operator-(vec4 left, float right);
			friend vec4 operator*(vec4 left, float right);
			friend vec4 operator/(vec4 left, float right);

			friend vec4 operator+(vec4 left, const vec4& right);
			friend vec4 operator-(vec4 left, const vec4& right);
			friend vec4 operator*(vec4 left, const vec4& right);
			friend vec4 operator/(vec4 left, const vec4& right);

			vec4& operator+=(const float& other);
			vec4& operator-=(const float& other);
			vec4& operator*=(const float& other);
			vec4& operator/=(const float& other);

			vec4& operator+=(const vec4& other);
			vec4& operator-=(const vec4& other);
			vec4& operator*=(const vec4& other);
			vec4& operator/=(const vec4& other);

			const float& operator[](unsigned int index) const;
			float& operator[](unsigned int index);

			bool operator==(const vec4& other);
			bool operator!=(const vec4& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);

		};

	}
}


#endif // !MAR_MATH_VEC4_H
