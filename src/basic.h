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


#include "maths.h"


namespace marengine::maths {

	
	/**
	 * @struct basic basic.h "basic.h"
	 * @brief basic structure defines basic mathematical methods,
	 * like square root, power and so on.
	 */
	struct basic {
	
		/**
		 * \brief Calculates square root of given value.
		 * \param val value, of which square root will be computed
		 * \return  float - calculated sqrt(val).
		 */
		static float square(float val);

		/**
		 * \brief Calculates power of given value.
		 * 
		 * \param val value, of which power will be computed
		 * \return float - calculated power
		 */
		static float power(float val);

		/**
		 * \brief Returns the component-wise compare of |x - y| < epsilon.
		 * \param x first value
		 * \param y second value
		 * \param epsilon some low float value, ex: FLT_EPSILON
		 * \return True, if equation is lower than given epsilon
		 */
		static bool epsilonEqual(float x, float y, float epsilon);

		/**
		 * \brief Returns the component-wise compare of |x - y| >= epsilon.
		 * 
		 * \param x
		 * \param y
		 * \param epsilon
		 * \return 
		 */
		static bool epsilonNotEqual(float x, float y, float epsilon);


	};


}

#endif // !MAR_MATH_BASIC_MATH_H
