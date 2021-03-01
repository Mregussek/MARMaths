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


#ifndef MAR_MATH_QUAT_H
#define MAR_MATH_QUAT_H


#include "maths.h"


namespace marengine::maths {

	struct vec3;
	struct vec4;
	struct mat4;


	/**
	 * \struct quat quat.h "quat.h"
	 * \brief quat is a structure written as a abstraction of quanternion. 
	 */
	struct quat {

		/// \brief w value of quat
		float w;
		/// \brief x (roll) value of quat
		float x;
		/// \brief y (pitch) value of quat
		float y;
		/// \brief z (yaw) value of quat
		float z;

		/// \brief Default constructor, creates quat(0.f, 0.f, 0.f, 0.f).
		quat();

		/**
		 * \brief Constructor, that can create quat from given 4 floats.
		 * \param _x x value, that will be prescribed to quat(x, y, z, w)
		 * \param _y y value, that will be prescribed to quat(x, y, z, w)
		 * \param _z z value, that will be prescribed to quat(x, y, z, w)
		 * \param _w w value, that will be prescribed to quat(x, y, z, w)
		 */
		quat(float _w, float _x, float _y, float _z);

		/**
		 * \brief Constructor, that converts euler angles vec3 to quanterion
		 * \param eulerAngles euler angles in vec3
		 */
		quat(vec3 eulerAngles);
		
		/**
		 * \brief Constructor, that converts euler angles vec4 to quanterion
		 * \param eulerAngles euler angles in vec4
		 */
		quat(vec4 eulerAngles);

		/**
		 * \brief Converts euler angles to quanterion.
		 * \param eulerAngles euler angles in vec3
		 * \return newly created quanternion
		 */
		static quat eulerAnglesToQuat(vec3 eulerAngles);

		/**
		 * \brief Creates rotation matrix from given quanternion
		 * \param q quat that is quanternion
		 * \return newly created rotation matrix
		 */
		static mat4 rotationFromQuat(quat q);

	};


}


#endif // !MAR_MATH_QUAT_H
