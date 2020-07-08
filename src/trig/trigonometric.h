/*
 *	Mateusz Rzeczyca
 *	Copyright (C) 2020 Mateusz Rzeczyca <info@mateuszrzeczyca.pl>
 */

#ifndef MAR_MATH_TRIGONOMETRIC_H
#define MAR_MATH_TRIGONOMETRIC_H

#define _USE_MATH_DEFINES
#include <cmath>
#include "../maths.h"

namespace mar {
    namespace maths {

        struct Trig {

            static float toRadians(float degrees) {
                return degrees * 0.01745329251f;
            }

            static float toDegrees(float radians) {
                return radians * 57.29577951308f;
            }

            static float sine(float degrees) {
                return sin(toRadians(degrees));
            }

            static float cosine(float degrees) {
                return cos(toRadians(degrees));
            }

            static float tangent(float degrees) {
                return tan(toRadians(degrees));
            }

        };

    }
}


#endif // !MAR_MATH_TRIGONOMETRIC_H
