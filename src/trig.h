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


#ifndef MAR_MATH_TRIGONOMETRIC_H
#define MAR_MATH_TRIGONOMETRIC_H


#include "maths.h"


namespace marengine::maths {


    /**
     * \struct trig trig.h "trig.h"
     * \brief Trig is a structure, that gives some trigonometric functions, such as sine,
     * tangent calculations (and many others).
     */
    struct trig {
        
        /// \brief self-explanatory
        static float toRadians(float degrees);
        /// \brief self-explanatory
        static float toDegrees(float radians);
        /// \brief self-explanatory
        static float sine(float radians);
        /// \brief self-explanatory
        static float cosine(float radians);
        /// \brief self-explanatory
        static float tangent(float radians);
        /// \brief self-explanatory
        static float arcsine(float radians);
        /// \brief self-explanatory
        static float arccosine(float radians);
        /// \brief self-explanatory
        static float arctangent(float radians);
        /// \brief self-explanatory
        static float h_sine(float radians);
        /// \brief self-explanatory
        static float h_cosine(float radians);
        /// \brief self-explanatory
        static float h_tangent(float radians);
        /// \brief self-explanatory
        static float h_arcsine(float radians);
        /// \brief self-explanatory
        static float h_arccosine(float radians);
        /// \brief self-explanatory
        static float h_arctangent(float radians);
    
    };


}

#endif // !MAR_MATH_TRIGONOMETRIC_H
