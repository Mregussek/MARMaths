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

	struct vec4;
	struct mat4;


	/**
	 * \brief quat is a structure written as a abstraction of quanternion. 
	 * I have wrote new struct that contains all needed functions for quanterion 
	 * implementation with no members, please use vec4 as quanternion and call needed methods.
	 */
	struct quat {

		/**
		 * \brief Retrieves quanternion from rotation matrix based on Mike Day's implementation:
		 * https://drive.google.com/file/d/1XfGftHswm-MBsIm2d2wPb8YG8TThiXi-/view?usp=sharing
		 * If you have issued with flipping, check if transposition will help (row-major vs column-major).
		 * \param transform rotation matrix, from which we want to retrieve quanterion
		 * \return retrieved quanterion in vec4 format
		 */
		static vec4 quatFromRotation1(const mat4& transform);

		/**
		 * \brief Retrieves quanterion from rotation matrix based on:
		 * <unknown URL hopefully I will find it soon
		 * \param transform rotation matrix, from which we want to retrieve quanterion
		 * \return retrieved quanterion in vec4 format
		 */
		static vec4 quatFromRotation2(const mat4& transform);

	};


}


#endif // !MAR_MATH_QUAT_H
