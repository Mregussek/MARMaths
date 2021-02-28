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
		 * \param _x x value, that will be prescribed to vec3(x, y, z)
		 * \param _y y value, that will be prescribed to vec3(x, y, z)
		 * \param _z z value, that will be prescribed to vec3(x, y, z)
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

		/**
		 * \brief Computes cross Product of *this and other vec3.
		 * \param other vec3
		 * \return result of cross product
		 */
		vec3 cross(vec3 other) const;

		/**
		 * \brief Static method, Computes cross Product of 2 given vec3's.
		 * \param x first vec3
		 * \param y second vec3
		 * \return  result of cross product
		 */
		static vec3 cross(vec3 x, vec3 y);

		/**
		 * \brief Computes dot product of *this and other vec3.
		 * \param other vec3
		 * \return calculated dot product
		 */
		float dot(vec3 other) const;

		/**
		 * \brief Static method, which computes dot product of 2 given vec3's.
		 * \param left first vec3
		 * \param right second vec3
		 * \return calculated dot product
		 */
		static float dot(vec3 left, vec3 right);

		/**
		 * \brief Calculate length / magnitude of a vector.
		 * \return its magnitude
		 */
		float length() const;

		/**
		 * \brief Computes length of given vector as a paramater.
		 * \param v vec3, which length will be calculated
		 * \return calculated length
		 */
		static float length(vec3 v);

		/**
		 * \brief Computes normalized vec3. Firstly it calculates length of vector,
		 * then it divides every value with length.
		 * If magnitude is equal to 0.f, we have debug break.
		 * \return normalized vec3
		 */
		vec3 normalize() const;

		/**
		 * \brief Computes normalized vec3. Firstly it calculates length of vector,
		 * then it divides every value with length.
		 * If magnitude is equal to 0.f, we have debug break.
		 * \param other vec3, which will be normalized
		 * \return normalized vec3
		 */
		static vec3 normalize(vec3 other);

		/**
		 * \brief Calculates angle between 'this' vec3 and other
		 * If (*this.length)*(other.length) is equal to 0.f, we have debug break.
		 * \param other vec3 between which angle will be calculated
		 * \return angle in radians
		 */
		float angleBetween(vec3 other) const;

		/**
		 * \brief Calculates angle between left and right vec3
		 * If (left.length)*(right.length) is equal to 0.f, we have debug break.
		 * \param left vec3
		 * \param right vec3
		 * \return angle in radians
		 */
		static float angleBetween(vec3 left, vec3 right);

		/**
		 * \brief Calculates projection vec3 of *this and other
		 * If magnitude is equal to 0.f, we have debug break.
		 * \param other vec3, to be computed with *this
		 * \return projected vec3
		 */
		vec3 projectOnto(vec3 other) const;

		/**
		 * \brief Calculates projection vec3 of left and right
		 * If magnitude is equal to 0.f, we have debug break.
		 * \param left - vec3
		 * \param right - vec3
		 * \return projected vec3
		 */
		static vec3 projectOnto(vec3 left, vec3 right);

		/**
		 * \brief Checks, if P1 is on the same side as P2 of a line segment A <-> B
		 * \param p1 point1
		 * \param p2 point2
		 * \param a vec3
		 * \param b	vec3
		 * \return true if P1 is on the same side as P2
		 */
		static bool sameSide(vec3 p1, vec3 p2, vec3 a, vec3 b);

		/**
		 * Compute triangle normal from given 3 vec3.
		 * \param t1 vec3
		 * \param t2 vec3
		 * \param t3 vec3
		 * \return calculated triangle normal
		 */
		static vec3 getTriangleNormal(vec3 t1, vec3 t2, vec3 t3);

		/**
		 * \brief Check to see if a vec3 Point is within a 3 Vector3 Triangle
		 * \param point vec3 point, that needs to be checked, if it is withing triangle
		 * \param t1 first point of triangle in vec3 format
		 * \param t2 second point of triangle in vec3 format
		 * \param t3 third point of triangle in vec3 format
		 * \return True, if point is withing t1 t2 t3 triangle
		 */
		static bool inTriangle(vec3 point, vec3 t1, vec3 t2, vec3 t3);

		/**
		 * \brief Returns value_ptr to first vec3 at vector. Used especially in shaders.
		 * \param vec vector of vec3
		 * \return value pointer
		 */
		static const float* value_ptr(const std::vector<vec3>& vec);

		/**
		 * \brief Returns const value_ptr to vec3. Used especially in shaders.
		 * \param vec vector of vec3
		 * \return value pointer
		 */
		static const float* value_ptr(const vec3& vec);

		/**
		 * \brief Returns value_ptr to vec3. Used especially in shaders.
		 * \param vec vector of vec3
		 * \return value pointer
		 */
		static float* value_ptr_nonconst(vec3& vec);

		/// \brief self-explanatory
		friend vec3 operator+(vec3 left, float right);
		/// \brief self-explanatory
		friend vec3 operator-(vec3 left, float right);
		/// \brief self-explanatory
		friend vec3 operator*(vec3 left, float right);
		/// \brief self-explanatory
		friend vec3 operator/(vec3 left, float right);
		/// \brief self-explanatory
		friend vec3 operator+(vec3 left, vec3 right);
		/// \brief self-explanatory
		friend vec3 operator-(vec3 left, vec3 right);
		/// \brief self-explanatory
		friend vec3 operator*(vec3 left, vec3 right);
		/// \brief self-explanatory
		friend vec3 operator/(vec3 left, vec3 right);
		/// \brief self-explanatory
		bool operator==(vec3 other) const;
		/// \brief self-explanatory
		bool operator!=(vec3 other) const;

	};


}


#endif // !MAR_MATH_VEC3_H
