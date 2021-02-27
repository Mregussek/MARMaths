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


#ifndef MAR_MATH_VEC3_H
#define MAR_MATH_VEC3_H


#include "maths.h"


namespace marengine::maths {

	struct vec4;


	/**
	 * \struct vec3 vec3.h "vec3.h"
	 * \brief 3-dimensional vector.
	 */
	struct vec3 {

		float x; /// x value of vec3
		float y; /// y value of vec3
		float z; /// w value of vec3


		/// \brief Default constructor, creates vec3(0.f, 0.f, 0.f).
		vec3();

		/**
		 * \brief Constructor, that can create vec3 from given 3 floats.
		 * \param x x value, that will be prescribed to vec3(x, y, z)
		 * \param y y value, that will be prescribed to vec3(x, y, z)
		 * \param z z value, that will be prescribed to vec3(x, y, z)
		 */
		vec3(float _x, float _y, float _z);

		/**
		 * \brief Constructor, that takes values x, y, z from given vec4
		 * \param v vec4, which values x,y,z will be prescribed to new vec3
		 */
		vec3(const vec4& v);

		/**
		 * \brief Addition method of vec3 and float value.
		 * vec3(x, y, z) + float = vec3(x + float, y + float, z + float)
		 * \param f float value, which will be added
		 * \return modifed vec3 after addition
		 */
		vec3 add(float f) const;

		/**
		 * \brief Subtraction method of vec3 and float value.
		 * vec3(x, y, z) - float = vec3(x - float, y - float, z - float)
		 * \param f float value, which will be subtracted
		 * \return modifed vec3 after subtraction
		 */
		vec3 subtract(float f) const;

		/**
		 * \brief Multiplication method of vec3 and float value.
		 * vec3(x, y, z) * float = vec3(x * float, y * float, z * float)
		 * \param f float value, which will be multiplied
		 * \return modifed vec3 after multiplication
		 */
		vec3 multiply(float f) const;

		/**
		 * \brief Division method of vec3 and float value.
		 * vec3(x, y, z) / float = vec3(x / float, y / float, z / float)
		 * Cannot divide by zero = 0.f! If user passes 0.f, then
		 * debug break is called!
		 * \param f float value, which will be divided
		 * \return modifed vec3 after division
		 */
		vec3 divide(float f) const;

		/**
		 * \brief Addition method of vec3 and vec3.
		 * v1 + v2 = vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z)
		 * \param other second vec3, which will be added to *this
		 * \return computed vec3
		 */
		vec3 add(vec3 other) const;

		/**
		 * \brief Subtraction method of vec3 and vec3.
		 * v1 - v2 = vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z)
		 * \param other second vec3, which will be subtracted from *this
		 * \return computed vec3
		 */
		vec3 subtract(vec3 other) const;

		/**
		 * \brief Multiplication method of vec3 and vec3.
		 * v1 * v2 = vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z)
		 * \param other second vec3, which will be mutliplied with *this
		 * \return computed vec3
		 */
		vec3 multiply(vec3 other) const;

		/**
		 * \brief Division method of vec3 and vec3.
		 * v1 / v2 = vec3(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z)
		 * Please make sure, that other vec3 isn't equal to 0 (any of its values). If so,
		 * method calls debug break.
		 * \param other second vec3
		 * \return computed vec3
		 */
		vec3 divide(vec3 other) const;

		/*
		Computes cross Product of *this and other vec3.

			\param other - vec3
			\return vec3 - result of cross product
		*/
		vec3 cross(vec3 other) const;

		/*
		Static method, Computes cross Product of 2 given vec3's.

			\param x - first vec3
			\param y - second vec3
			\return vec3 - result of cross product
		*/
		static vec3 cross(vec3 x, vec3 y);

		/*
		Computes dot product of *this and other vec3.

			\param other - vec3
			\return float - calculated dot product
		*/
		float dot(vec3 other) const;

		/*
		Static method, which computes dot product of 2 given vec3's.

			\param left - first vec3
			\param right - second vec3
			\return float - calculated dot product
		*/
		static float dot(vec3 left, vec3 right);

		/*
		Calculate length / magnitude of a vector.

			\return float - its magnitude
		*/
		float length() const;

		/*
		Computes length of given vector as a paramater (l-value).

			\param v - vec3, which length will be calculated
			\return float - calculated length
		*/
		static float length(vec3 v);

		/**
		 * \brief
		 * 
		 * \return 
		 */
		vec3 normalize() const;

		/*
		Computes normalized vec2. Firstly it calculates length of vector, 
		then it divides every value with length.

		If magnitude is equal to 0, we have debug break.

			\param other - vec3, which will be normalized
			\return vec3 - normalized vec3
		*/
		static vec3 normalize(vec3 other);

		/*
		Calculates angle between 'this' vec3 and other
			
			\param other - vec3 between which angle will be calculated
			\return angle - radians
		*/
		float angleBetween(const vec3& other) const;

		/*
		Calculates angle between left and right vec3
			
			\param left - vec3
			\param right - vec3
			\return angle - radians
		*/
		static float angleBetween(const vec3& left, const vec3& right);

		/*
		Calculates projection vec3 of *this and other
			
			\param other - vec3, to be computed with *this
			\return vec3 - projected vec3
		*/
		vec3 projectOnto(const vec3& other) const;

		/*
		Calculates projection vec3 of left and right
			
			\param left - vec3
			\param right - vec3
			\return vec3 - projected vec3
		*/
		static vec3 projectOnto(const vec3& left, const vec3& right);

		/*
		Test if P1 is on the same side as P2 of a line segment A <-> B

			\param P1 - point1
			\param P2 - point2
			\param A - vec3
			\param B - vec3
			\return true if yes
		*/
		static bool sameSide(const vec3& p1, const vec3& p2, const vec3& a, const vec3& b);

		/*
		Returns triangle normal from 3 vectors

			\param t1 - vec3
			\param t2 - vec3
			\param t3 - vec3
		*/
		static vec3 getTriangleNormal(const vec3& t1, const vec3& t2, const vec3& t3);

		/*
		Check to see if a vec3 Point is within a 3 Vector3 Triangle

			\param point - vec3
			\param t1
			\param t2
			\param t3
			\return true if is within
		*/
		static bool inTriangle(const vec3& point, const vec3& t1, const vec3& t2, const vec3& t3);

		/*
		Returns value_ptr to first vec3 at vector. Used especially in shaders.

			\param vec - vector of vec3
			\return const float* - value pointer
		*/
		static const float* value_ptr(const std::vector<vec3>& vec);

		/*
		Returns const value_ptr to vec3. Used especially in shaders.

			\param vec - vector of vec3
			\return float* - value pointer
		*/
		static const float* value_ptr(const vec3& vec);

		/*
		Returns value_ptr to vec3. Used especially in shaders.

			\param vec - vector of vec3
			\return float* - value pointer
		*/
		static float* value_ptr_nonconst(vec3& vec);

		// -------------------------------------------
		// Overloaded operators, I think they are self-explanatory.
		// -------------------------------------------

		friend vec3 operator+(vec3 left, float right);
		friend vec3 operator-(vec3 left, float right);
		friend vec3 operator*(vec3 left, float right);
		friend vec3 operator/(vec3 left, float right);

		friend vec3 operator+(vec3 left, const vec3& right);
		friend vec3 operator-(vec3 left, const vec3& right);
		friend vec3 operator*(vec3 left, const vec3& right);
		friend vec3 operator/(vec3 left, const vec3& right);

		vec3& operator+=(float other);
		vec3& operator-=(float other);
		vec3& operator*=(float other);
		vec3& operator/=(float other);

		vec3& operator+=(const vec3& other);
		vec3& operator-=(const vec3& other);
		vec3& operator*=(const vec3& other);
		vec3& operator/=(const vec3& other);

		bool operator==(const vec3& other) const;
		bool operator!=(const vec3& other) const;

	};


}


#endif // !MAR_MATH_VEC3_H
