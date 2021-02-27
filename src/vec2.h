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


#ifndef MAR_MATH_VEC2_H
#define MAR_MATH_VEC2_H


#include "../maths.h"


namespace marengine::maths {


	/*
	2-dimensional vector.
	*/
	struct vec2 {
		
		// -------------------------------
		float x; /* x value of vec2 */
		float y; /* y value of vec2 */
		// -------------------------------

		// Default constructor, creates vec2(0, 0).
		vec2();

		/*
		Constructor, that can create vec2 from given 2 floats (l-values).

			\param x - x value, that will be prescribed to vec2(x, y)
			\param y - y value, that will be prescribed to vec2(x, y)
		*/
		vec2(const float& x, const float& y);

		/*
		Constructor, that can create vec2 from given 2 floats (r-values).

			\param x - x value, that will be prescribed to vec2(x, y)
			\param y - y value, that will be prescribed to vec2(x, y)
		*/
		vec2(const float&& x, const float&& y);

		/*
		Addition method of vec2 and float value. 
		vec2(x, y) + float = vec2(x + float, y + float)

			\param f - float value, which will be added
			\return vec2 - returns modified *this
		*/
		vec2& add(const float& f);

		/*
		Subtraction method of vec2 and float value. 
		vec2(x, y) - float = vec2(x - float, y - float)

			\param f - float value, which will be subtracted
			\return vec2 - returns modified *this
		*/
		vec2& subtract(const float& f);

		/*
		Multiplication method of vec3 and float value. 
		vec2(x, y) * float = vec2(x * float, y * float)

			\param f - float value, which will be multiplied
			\return vec2 - returns modified *this
		*/
		vec2& multiply(const float& f);

		/*
		Division method of vec2 and float value. 
		vec2(x, y) / float = vec2(x / float, y / float)

		If user send f as 0, it will return unmodified *this!

			\param f - float value, which will be divided
			\return vec2 - returns modified *this
		*/
		vec2& divide(const float& f);

		/*
		Addition method of vec2 and vec2.
		v1 + v2 = vec2(v1.x + v2.x, v1.y + v2.y)

			\param other - second vec2, which will be added to *this
			\return vec2 - computed *this
		*/
		vec2& add(const vec2& other);

		/*
		Subtraction method of vec2 and vec2.
		v1 - v2 = vec2(v1.x - v2.x, v1.y - v2.y)

			\param other - second vec2, which will be subtracted from *this
			\return vec2 - computed *this
		*/
		vec2& subtract(const vec2& other);

		/*
		Multiplication method of vec2 and vec2.
		v1 * v2 = vec2(v1.x * v2.x, v1.y * v2.y)

			\param other - second vec2, which will be mutliplied with *this
			\return vec2 - computed *this
		*/
		vec2& multiply(const vec2& other);

		/*
		Division method of vec2 and vec2.
		v1 / v2 = vec3(v1.x / v2.x, v1.y / v2.y)

		Please make sure, that other vec2 isn't equal to 0 (any of its values). If so,
		method returns unmodified *this.

			\param other - second vec2
			\return vec2 - computed *this
		*/
		vec2& divide(const vec2& other);

		/*
		Computes dot product of *this and other vec2.

			\param other - vec2
			\return float - calculated dot product
		*/
		float dot(const vec2& other);

		/*
		Static method, which computes dot product of 2 given vec2's.

			\param left - first vec2
			\param right - second vec2
			\return float - calculated dot product
		*/
		static float dot(const vec2& left, const vec2& right);

		/*
		Calculate length / magnitude of a vector.

			\return float - its magnitude
		*/
		float length() const;

		/*
		Computes length of given vector as a paramater (l-value).

			\param v - vec2, which length will be calculated
			\return float - calculated length
		*/
		static float length(vec2& v);

		/*
		Computes length of given vector as a paramater (r-value).

			\param v - vec2, which length will be calculated
			\return float - calculated length
		*/
		static float length(vec2&& v);

		/*
		Computes normalized vec2. Firstly it calculates length of vector, 
		then it divides every value with length.

		If magnitude is equal to 0, we have debug break.

			\param other - vec2, which will be normalized
			\return vec2 - normalized vec2
		*/
		static vec2 normalize(const vec2& other);

		// -------------------------------------------
		// Overloaded operators, I think they are self-explanatory.
		// -------------------------------------------

		friend vec2 operator+(vec2 left, float right);
		friend vec2 operator-(vec2 left, float right);
		friend vec2 operator*(vec2 left, float right);
		friend vec2 operator/(vec2 left, float right);

		friend vec2 operator+(vec2 left, const vec2& right);
		friend vec2 operator-(vec2 left, const vec2& right);
		friend vec2 operator*(vec2 left, const vec2& right);
		friend vec2 operator/(vec2 left, const vec2& right);

		vec2& operator+=(const float& other);
		vec2& operator-=(const float& other);
		vec2& operator*=(const float& other);
		vec2& operator/=(const float& other);

		vec2& operator+=(const vec2& other);
		vec2& operator-=(const vec2& other);
		vec2& operator*=(const vec2& other);
		vec2& operator/=(const vec2& other);

		bool operator==(const vec2& other) const;
		bool operator!=(const vec2& other) const;

	};


}


#endif // !MAR_MATH_VEC2_H
