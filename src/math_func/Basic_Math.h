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


#ifndef MAR_MATH_BASIC_MATH_H
#define MAR_MATH_BASIC_MATH_H


#include "../maths.h"
#include "../mat/mat4.h"
#include "../vec/vec3.h"


namespace mar {
	namespace maths {


		/*
		basic structure defines basic mathematical methods.
		*/
		struct basic {
		
			/*
			Calculates square root of given value.

				\param val - value, of which square root will be computed/
				\return float - calculated sqrt(val).
			*/
			static float square(float val) {
				return sqrt(val);
			}

		};


} }

#endif // !MAR_MATH_BASIC_MATH_H
