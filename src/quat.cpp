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
#include "trig.h"
#include "basic.h"
#include "mat4.h"
#include "vec4.h"
#include "vec3.h"


namespace marengine::maths {


	quat::quat() :
		w(0.f),
		x(0.f),
		y(0.f),
		z(0.f)
	{}

	quat::quat(float _w, float _x, float _y, float _z) :
		w(_w),
		x(_x),
		y(_y),
		z(_z)
	{}

	quat::quat(vec3 eulerAngles) {
		*this = eulerAnglesToQuat(eulerAngles);
	}

	quat::quat(vec4 eulerAngles) {
		*this = eulerAnglesToQuat(vec3(eulerAngles));
	}

	quat quat::eulerAnglesToQuat(vec3 eulerAngles) {
		eulerAngles = eulerAngles * 0.5f;
		const vec3 c{
			trig::cosine(eulerAngles.x),
			trig::cosine(eulerAngles.y),
			trig::cosine(eulerAngles.z)
		};
		const vec3 s{
			trig::sine(eulerAngles.x),
			trig::sine(eulerAngles.y),
			trig::sine(eulerAngles.z)
		};

		return {
			c.x * c.y * c.z + s.x * s.y * s.z,
			s.x * c.y * c.z - c.x * s.y * s.z,
			c.x * s.y * c.z + s.x * c.y * s.z,
			c.x * c.y * s.z - s.x * s.y * c.z
		};
	}

	mat4 quat::rotationFromQuat(quat q) {
		const float qxx(q.x * q.x);
		const float qyy(q.y * q.y);
		const float qzz(q.z * q.z);
		const float qxz(q.x * q.z);
		const float qxy(q.x * q.y);
		const float qyz(q.y * q.z);
		const float qwx(q.w * q.x);
		const float qwy(q.w * q.y);
		const float qwz(q.w * q.z);
		mat4 rtn(1.f);

		rtn[0 + 0 * 4] = 1.f - 2.f * (qyy + qzz);
		rtn[0 + 1 * 4] = 2.f * (qxy + qwz);
		rtn[0 + 2 * 4] = 2.f * (qxz - qwy);

		rtn[1 + 0 * 4] = 2.f * (qxy - qwz);
		rtn[1 + 1 * 4] = 1.f - 2.f * (qxx + qzz);
		rtn[1 + 2 * 4] = 2.f * (qyz + qwx);
	
		rtn[2 + 0 * 4] = 2.f * (qxz + qwy);
		rtn[2 + 1 * 4] = 2.f * (qyz - qwx);
		rtn[2 + 2 * 4] = 1.f - 2.f * (qxx + qyy);
		return rtn;
	}


}
