/*
 *	Mateusz Rzeczyca
 *	Copyright (C) 2020 Mateusz Rzeczyca <info@mateuszrzeczyca.pl>
 */

#ifndef MAR_MATH_TRIGONOMETRIC_H
#define MAR_MATH_TRIGONOMETRIC_H

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

            static float sine(float radians) {
                return sin(radians);
            }

            static float cosine(float radians) {
                return cos(radians);
            }

            static float tangent(float radians) {
                return tan(radians);
            }

        };

    }
}


#endif // !MAR_MATH_TRIGONOMETRIC_H
