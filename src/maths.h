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


#ifndef MAR_MATH_H
#define MAR_MATH_H

#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>

#include <vector>

#include "trig/trigonometric.h"

#include "math_func/Basic_Math.h"

#include "vec/vec2.h"
#include "vec/vec3.h"
#include "vec/vec4.h"

#include "mat/mat4.h"

#define MAR_MATH_PI M_PI

namespace mar { 
    namespace maths {

        struct Trig;

		struct vec2;
		struct vec3;
		struct vec4;

        struct mat4;

		struct basic;


} }


#endif // !MAR_MATH_H