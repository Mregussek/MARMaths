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


	/**
	 * \brief quat is a namespace as abstraction of quanternion. Because I don't
	 * want to create structure with the same members as vec4 contains, I have wrote
	 * new namespace that contains all needed functions for quanterion implementation.
	 */
	namespace quat {

		typedef ::marengine::maths::vec4 vec4;
		struct vec4;

		typedef ::marengine::maths::mat4 mat4;
		struct mat4;


		/**
		 * \brief Retrieves quanterion from rotation matrix based on Mike Day's implementation:
		 * https://drive.google.com/file/d/1XfGftHswm-MBsIm2d2wPb8YG8TThiXi-/view?usp=sharing
		 * \param transform rotation matrix, from which we want to retrieve quanterion
		 * \return retrieved quanterion in vec4 format
		 */
		vec4 quatFromRotation(const mat4& transform);



	}


}


#endif // !MAR_MATH_QUAT_H
