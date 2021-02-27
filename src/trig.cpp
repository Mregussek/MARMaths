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


#include "trig.h"


namespace marengine::maths {


    float trig::toRadians(float degrees) {
        return degrees * MARMATH_DEG2RAD;
    }

    float trig::toDegrees(float radians) {
        return radians * MARMATH_RAD2DEG;
    }

    float trig::sine(float radians) {
        return sin(radians);
    }

    float trig::cosine(float radians) {
        return cos(radians);
    }

    float trig::tangent(float radians) {
        return tan(radians);
    }

    float trig::arcsine(float radians) {
        return asin(radians);
    }

    float trig::arccosine(float radians) {
        return acos(radians);
    }

    float trig::arctangent(float radians) {
        return atan(radians);
    }

    float trig::h_sine(float radians) {
        return sinh(radians);
    }

    float trig::h_cosine(float radians) {
        return cosh(radians);
    }

    float trig::h_tangent(float radians) {
        return tanh(radians);
    }

    float trig::h_arcsine(float radians) {
        return asinh(radians);
    }

    float trig::h_arccosine(float radians) {
        return acosh(radians);
    }

    float trig::h_arctangent(float radians) {
        return atanh(radians);
    }


}