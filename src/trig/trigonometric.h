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

            static float sin(float degrees) {
                return sin(toRadians(degrees));
            }

            static float cos(float degrees) {
                return cos(toRadians(degrees));
            }

            static float tan(float degrees) {
                return tan(toRadians(degrees));
            }

            static float ctan(float degrees) {
                return ctan(toRadians(degrees));
            }

        };

    }
}


#endif // !MAR_MATH_TRIGONOMETRIC_H
