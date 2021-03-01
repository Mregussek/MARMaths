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


#include "quat.h"
#include "basic.h"
#include "mat4.h"
#include "vec4.h"
#include "vec3.h"


namespace marengine::maths {


	vec4 quat::quatFromRotation1(const mat4& transform) {
		float sumOfTerms{ 0.f };
		vec4 rtn;

		if (transform[2 + 2 * 4] < 0.f) {
			if (transform[0 + 0 * 4] > transform[1 + 1 * 4]) {
				sumOfTerms = 1 + transform[0 + 0 * 4] - transform[1 + 1 * 4] - transform[2 + 2 * 4];
				rtn = {
					sumOfTerms,
					transform[1 + 0 * 4] + transform[0 + 1 * 4],
					transform[0 + 2 * 4] + transform[2 + 0 * 4],
					transform[2 + 1 * 4] - transform[1 + 2 * 4]
				};
			}
			else {
				sumOfTerms = 1 - transform[0 + 0 * 4] + transform[1 + 1 * 4] - transform[2 + 2 * 4];
				rtn = {
					transform[1 + 0 * 4] + transform[0 + 1 * 4],
					sumOfTerms,
					transform[2 + 1 * 4] + transform[1 + 2 * 4],
					transform[0 + 2 * 4] - transform[2 + 0 * 4],
				};
			}
		}
		else {
			if (transform[0 + 0 * 4] < -transform[1 + 1 * 4]) {
				sumOfTerms = 1 - transform[0 + 0 * 4] - transform[1 + 1 * 4] + transform[2 + 2 * 4];
				rtn = {
					transform[0 + 2 * 4] + transform[2 + 0 * 4],
					transform[2 + 1 * 4] + transform[1 + 2 * 4],
					sumOfTerms,
					transform[1 + 0 * 4] - transform[0 + 1 * 4]
				};
			}
			else {
				sumOfTerms = 1 + transform[0 + 0 * 4] + transform[1 + 1 * 4] + transform[2 + 2 * 4];
				rtn = {
					transform[2 + 1 * 4] - transform[1 + 2 * 4],
					transform[0 + 2 * 4] - transform[2 + 0 * 4],
					transform[1 + 0 * 4] - transform[0 + 1 * 4],
					sumOfTerms
				};
			}
		}

		const vec4 quatRad{ rtn * 0.5f / basic::square(sumOfTerms) };
		return quatRad;
	}

	vec4 quat::quatFromRotation2(const mat4& transform) {
		const float m00{ transform[0 + 0 * 4] };
		const float m01{ transform[0 + 1 * 4] };
		const float m02{ transform[0 + 2 * 4] };
		const float m12{ transform[1 + 2 * 4] };
		const float m22{ transform[2 + 2 * 4] };

		return {
			atan2f(m12, m22),
			atan2f(-m02, sqrtf(m12 * m12 + m22 * m22)),
			atan2f(m01, m00),
			0.f
		};
	}

	vec4 quat::quatFromRotation3(const mat4& transform) {
		vec4 rtn;

		rtn.y = asin(-transform[0 + 2 * 4]);
		if (cos(rtn.y) != 0.f) {
			rtn.x = atan2(transform[1 + 2 * 4], transform[2 + 2 * 4]);
			rtn.z = atan2(transform[0 + 1 * 4], transform[0 + 0 * 4]);
		}
		else {
			rtn.x = atan2(-transform[2 + 0 * 4], transform[1 + 1 * 4]);
			rtn.z = 0.f;
		}

		return rtn;
	}

	vec4 quat::eulerAnglesToQuat(vec3 euler) {
		// euler (x, y, z, 0.f) -> x - roll, y - pitch, z - yaw

		euler = euler / 2.f;

		const float cosRoll{ cos(euler.x) };
		const float cosPitch{ cos(euler.y) };
		const float cosYaw{ cos(euler.z) };
		const float sinRoll{ sin(euler.x) };
		const float sinPitch{ sin(euler.y) };
		const float sinYaw{ sin(euler.z) };

		return {
			cosRoll * cosPitch * cosYaw + sinRoll * sinPitch * sinYaw,
			sinRoll * cosPitch * cosYaw - cosRoll * sinPitch * sinYaw,
			cosRoll * sinPitch * cosYaw + sinRoll * cosPitch * sinYaw,
			cosRoll * cosPitch * sinYaw - sinRoll * sinPitch * cosYaw
		};
	}

	vec3 quat::quatToEulerAngles(vec4 q) {
		const float numerator1{ 2.f * (q.x * q.y + q.z * q.w) };
		const float denumerator1{ 1.f - 2.f * (q.y * q.y + q.z * q.z) };

		const float numerator2{ 2.f * (q.x * q.z - q.w * q.y) };

		const float numerator3{ 2.f * (q.x * q.w + q.y * q.z) };
		const float denumerator3{ 1.f - 2.f * (q.z * q.z + q.w * q.w) };

		return {
			atan2(numerator1, denumerator1),
			asin(numerator2),
			atan2(numerator3, denumerator3)
		};
	}


}
