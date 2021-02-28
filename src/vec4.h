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


#ifndef MAR_MATH_VEC4_H
#define MAR_MATH_VEC4_H


#include "maths.h"


namespace marengine::maths {

	struct vec3;


	/**
	 * \struct vec4 vec4.h "vec4.h"
	 * \brief 4-dimensional vector.
	 */
	struct vec4 {
		
		/// \brief x value of vec4
		float x;
		/// \brief y value of vec4
		float y; 
		/// \brief z value of vec4
		float z;
		/// \brief w value of vec4
		float w;


		/// \brief Default constructor, creates vec4(0.f, 0.f, 0.f, 0.f).
		vec4();

		/**
		 * \brief Constructor, that expands vec3 to vec4 with given w parameter.
		 * \param v vec3, which will be expanded
		 * \param w value, which is needed to create fourth dimension
		 */
		vec4(vec3 v, float w);

		/**
		 * \brief Constructor, that can create vec4 from given 4 floats.
		 * \param _x x value, that will be prescribed to vec4(x, y, z, w)
		 * \param _y y value, that will be prescribed to vec4(x, y, z, w)
		 * \param _z z value, that will be prescribed to vec4(x, y, z, w)
		 * \param _w w value, that will be prescribed to vec4(x, y, z, w)
		 */
		vec4(float _x, float _y, float _z, float _w);

		/**
		 * \brief Addition method of vec4 and float value.
		 * vec4(x, y, z, w) + float = vec4(x + float, y + float, z + float, w + float)
		 * \param f float value, which will be added
		 * \return modifed vec4 after addition
		 */
		vec4 add(float f) const;

		/**
		 * \brief Subtraction method of vec4 and float value.
		 * vec4(x, y, z, w) - float = vec4(x - float, y - float, z - float, w - float)
		 * \param f float value, which will be subtracted
		 * \return modifed vec4 after subtraction
		 */
		vec4 subtract(float f) const;

		/**
		 * \brief Multiplication method of vec4 and float value.
		 * vec4(x, y, z, w) * float = vec4(x * float, y * float, z * float, w * float)
		 * \param f float value, which will be multiplied
		 * \return modifed vec4 after multiplication
		 */
		vec4 multiply(float f) const;

		/**
		 * \brief Division method of vec4 and float value.
		 * vec4(x, y, z, w) / float = vec4(x / float, y / float, z / float, w / float)
		 * Cannot divide by zero = 0.f! If user passes 0.f, then
		 * debug break is called!
		 * \param f float value, which will be divided
		 * \return  modifed vec4 after division
		 */
		vec4 divide(float f) const;

		/**
		 * \brief Addition method of vec4 and vec4.
		 * v1 + v2 = vec4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w)
		 * \param other second vec4, which will be added to *this
		 * \return modifed vec4 after addition
		 */
		vec4 add(vec4 other) const;

		/**
		 * \brief Subtraction method of vec4 and vec4.
		 * v1 - v2 = vec4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w)
		 * \param other second vec4, which will be subtracted from *this
		 * \return modifed vec4 after subtraction
		 */
		vec4 subtract(vec4 other) const;

		/**
		 * \brief Multiplication method of vec4 and vec4.
		 * v1 * v2 = vec4(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w)
		 * \param other second vec4, which will be mutliplied with *this
		 * \return  modifed vec4 after multiplication
		 */
		vec4 multiply(vec4 other) const;

		/**
		 * \brief Division method of vec4 and vec4.
		 * v1 / v2 = vec4(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w)
		 * Please make sure, that other vec2 isn't equal to 0 (any of its values). If so,
		 * method calls debug break.
		 * \param other second vec4
		 * \return modifed vec4 after division
		 */
		vec4 divide(vec4 other) const;

		/**
		 * \brief Computes dot product of *this and other vec4.
		 * \param other vec4
		 * \return calculated dot product
		 */
		float dot(vec4 other) const;

		/**
		 * \brief Static method, which computes dot product of 2 given vec4's.
		 * 
		 * \param left first vec4
		 * \param right second vec4
		 * \return calculated dot product
		 */
		static float dot(vec4 left, vec4 right);

		/**
		 * Calculate length / magnitude of a vector.
		 * \return its magnitude
		 */
		float length() const;

		/**
		 * \brief Computes length of given vector as a paramater.
		 * \param v vec4, which length will be calculated
		 * \return calculated length
		 */
		static float length(vec4 v);

		/**
		 * \brief Computes normalized vec4. Firstly it calculates length of vector,
		 * then it divides every value with length.
		 * If magnitude is equal to 0, we have debug break.
		 * \return normalized vec4
		 */
		vec4 normalize() const;

		/**
		 * \brief Computes normalized vec4. Firstly it calculates length of vector,
		 * then it divides every value with length.
		 * If magnitude is equal to 0, we have debug break.
		 * \param other vec4, which will be normalized
		 * \return normalized vec4
		 */
		static vec4 normalize(vec4 other);

		/**
		 * \brief Returns value_ptr to first vec4 at vector. Used especially in shaders.
		 * \param vec vector of vec4
		 * \return value pointer
		 */
		static const float* value_ptr(const std::vector<vec4>& vec);

		/**
		 * \brief Returns const value_ptr to vec4. Used especially in shaders.
		 * \return value pointer
		 */
		const float* value_ptr() const;

		/**
		 * \brief Returns const value_ptr to vec4. Used especially in shaders.
		 * \param vec vec4
		 * \return value pointer
		 */
		static const float* value_ptr(const vec4& vec);

		/// \brief self-explanatory
		friend vec4 operator+(vec4 left, float right);
		/// \brief self-explanatory
		friend vec4 operator-(vec4 left, float right);
		/// \brief self-explanatory
		friend vec4 operator*(vec4 left, float right);
		/// \brief self-explanatory
		friend vec4 operator/(vec4 left, float right);
		/// \brief self-explanatory
		friend vec4 operator+(vec4 left, vec4 right);
		/// \brief self-explanatory
		friend vec4 operator-(vec4 left, vec4 right);
		/// \brief self-explanatory
		friend vec4 operator*(vec4 left, vec4 right);
		/// \brief self-explanatory
		friend vec4 operator/(vec4 left, vec4 right);
		/// \brief self-explanatory
		bool operator==(vec4 other) const;
		/// \brief self-explanatory
		bool operator!=(vec4 other) const;

	};


}


#endif // !MAR_MATH_VEC4_H
