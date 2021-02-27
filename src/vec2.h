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


#ifndef MAR_MATH_VEC2_H
#define MAR_MATH_VEC2_H


#include "maths.h"


namespace marengine::maths {


	/**
	 * \struct vec2 vec2.h "vec2.h"
	 * \brief 2-dimensional vector.
	 */
	struct vec2 {
		
		float x; /// x value of vec2
		float y; /// y value of vec2

		/// \brief Default constructor, creates vec2(0, 0).
		vec2();

		/**
		 * \brief Constructor, that can create vec2 from given 2 floats.
		 * \param x x value, that will be prescribed to vec2(x, y)
		 * \param y y value, that will be prescribed to vec2(x, y)
		 */
		vec2(float _x, float _y);

		/**
		 * \brief Addition method of vec2 and float value.  
		 * vec2(x, y) + float = vec2(x + float, y + float) 
		 * \param f float value, which will be added
		 * \return modifed vec2 after addition
		 */
		vec2 add(float f) const;

		/**
		 * \brief Subtraction method of vec2 and float value.
		 * vec2(x, y) - float = vec2(x - float, y - float)
		 * \param f float value, which will be subtracted
		 * \return modifed vec2 after subtraction
		 */
		vec2 subtract(float f) const;

		/**
		 * \brief Multiplication method of vec3 and float value.
		 * vec2(x, y) * float = vec2(x * float, y * float)
		 * \param f float value, which will be multiplied
		 * \return modifed vec2 after multiplication
		 */
		vec2 multiply(float f) const;

		/**
		 * \brief Division method of vec2 and float value.
		 * vec2(x, y) / float = vec2(x / float, y / float)
		 * Cannot divide by zero = 0.f! If user passes 0.f, then
		 * debug break is called!
		 * \param f float value, which will be divided
		 * \return modifed vec2 after division
		 */
		vec2 divide(float f) const;

		/**
		 * \brief Addition method of vec2 and vec2.
		 * v1 + v2 = vec2(v1.x + v2.x, v1.y + v2.y)
		 * \param other second vec2, which will be added to *this
		 * \return modifed vec2 after addition
		 */
		vec2 add(vec2 other) const;

		/**
		 * \brief Subtraction method of vec2 and vec2.
		 * v1 - v2 = vec2(v1.x - v2.x, v1.y - v2.y)
		 * \param other second vec2, which will be subtracted from *this
		 * \return modifed vec2 after subtraction
		 */
		vec2 subtract(vec2 other) const;

		/**
		 * \brief Multiplication method of vec2 and vec2.
		 * v1 * v2 = vec2(v1.x * v2.x, v1.y * v2.y)
		 * \param other second vec2, which will be mutliplied with *this
		 * \return modifed vec2 after multiplication
		 */
		vec2 multiply(vec2 other) const;

		/**
		 * \brief Division method of vec2 and vec2.
		 * v1 / v2 = vec2(v1.x / v2.x, v1.y / v2.y)
		 * Please make sure, that other vec2 isn't equal to 0 (any of its values). If so,
		 * method calls debug break.
		 * \param other second vec2
		 * \return modifed vec2 after division
		 */
		vec2 divide(vec2 other) const;

		/**
		 * \brief Computes dot product of *this and other vec2.
		 * \param other other vec2, with which dot product must be calculated
		 * \return calculated dot product
		 */
		float dot(vec2 other) const;

		/**
		 * \brief Static method, which computes dot product of 2 given vec2's.
		 * 
		 * \param left first vec2
		 * \param right second vec2
		 * \return calculated dot product
		 */
		static float dot(vec2 left, vec2 right);

		/**
		 * \brief Calculate length / magnitude of a vector.
		 * \return its magnitude
		 */
		float length() const;

		/**
		 * \brief Computes length of given vector as a paramater.
		 * \param v vec2, which length will be calculated
		 * \return calculated length
		 */
		static float length(vec2 v);
		
		/**
		 * \brief Computes normalized vec2. Firstly it calculates length of vector,
		 * then it divides every value with length.
		 * If magnitude is equal to 0, we have debug break.
		 * \return normalized vec2
		 */
		vec2 normalize() const;

		/**
		 * \brief Computes normalized vec2. Firstly it calculates length of vector,
		 * then it divides every value with length.
		 * If magnitude is equal to 0, we have debug break.
		 * \param other vec2, which will be normalized
		 * \return normalized vec2
		 */
		static vec2 normalize(vec2 other);

		// -------------------------------------------
		// Overloaded operators, I think they are self-explanatory.
		// -------------------------------------------

		friend vec2 operator+(vec2 left, float right);
		friend vec2 operator-(vec2 left, float right);
		friend vec2 operator*(vec2 left, float right);
		friend vec2 operator/(vec2 left, float right);

		friend vec2 operator+(vec2 left, vec2 right);
		friend vec2 operator-(vec2 left, vec2 right);
		friend vec2 operator*(vec2 left, vec2 right);
		friend vec2 operator/(vec2 left, vec2 right);

		vec2 operator+=(float other) const;
		vec2 operator-=(float other) const;
		vec2 operator*=(float other) const;
		vec2 operator/=(float other) const;

		vec2 operator+=(vec2 other) const;
		vec2 operator-=(vec2 other) const;
		vec2 operator*=(vec2 other) const;
		vec2 operator/=(vec2 other) const;

		bool operator==(vec2 other) const;
		bool operator!=(vec2 other) const;

	};


}


#endif // !MAR_MATH_VEC2_H
