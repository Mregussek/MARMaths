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


#include "vec2.h"
#include "basic.h"


namespace marengine::maths {


	vec2::vec2() {
		this->x = 0.0f;
		this->y = 0.0f;
	}

	vec2::vec2(float _x, float _y) {
		x = _x;
		y = _y;
	}

	vec2 vec2::add(float f) const {
		return {
			x + f,
			y + f
		};
	}

	vec2 vec2::subtract(float f) const {
		return {
			x - f,
			y - f
		};
	}

	vec2 vec2::multiply(float f) const {
		return {
			x * f,
			y * f
		};
	}

	vec2 vec2::divide(float f) const {
		if (f == 0.f) {
			static_assert(true, "vec2::divide(0.f) - cannot divide by zero!");
		};
		return {
			x / f,
			y / f
		};
	}

	vec2 vec2::add(vec2 other) const {
		return {
			x + other.x,
			y + other.y
		};
	}

	vec2 vec2::subtract(vec2 other) const {
		return {
			x - other.x,
			y - other.y
		};
	}

	vec2 vec2::multiply(vec2 other) const {
		return {
			x * other.x,
			y * other.y
		};
	}

	vec2 vec2::divide(vec2 other) const {
		if (other.x == 0.f || other.y == 0.f) {
			static_assert(true, "vec2::divide({0.f, 0.f}) - cannot divide by zero!");
		}
		return {
			x / other.x,
			y / other.y
		};
	}

	float vec2::dot(vec2 other) const {
		return dot(*this, other);
	}

	float vec2::dot(vec2 left, vec2 right) {
		return left.x * right.x + left.y * right.y;
	}

	float vec2::length() const {
		return length(*this);
	}

	float vec2::length(vec2 v) {
		return basic::square(dot(v, v));
	}

	vec2 vec2::normalize() const {
		return normalize(*this);
	}

	vec2 vec2::normalize(vec2 other) {
		const float magnitude{ length(other) };
		if (magnitude == 0.f) {
			static_assert(true, "vec2::normalize(magnitude=0.f) - cannot divide by zero!");
		}
		const float inverseMagnitude{ 1.f / magnitude };
		return other * inverseMagnitude;
	}

	vec2 operator+(vec2 left, float right) {
		return left.add(right);
	}

	vec2 operator-(vec2 left, float right) {
		return left.subtract(right);
	}

	vec2 operator*(vec2 left, float right) {
		return left.multiply(right);
	}

	vec2 operator/(vec2 left, float right) {
		return left.divide(right);
	}

	vec2 operator+(vec2 left, vec2 right) {
		return left.add(right);
	}

	vec2 operator-(vec2 left, vec2 right) {
		return left.subtract(right);
	}

	vec2 operator*(vec2 left, vec2 right) {
		return left.multiply(right);
	}

	vec2 operator/(vec2 left, vec2 right) {
		return left.divide(right);
	}

	vec2 vec2::operator+=(float other) const {
		return add(other);
	}

	vec2 vec2::operator-=(float other) const {
		return subtract(other);
	}

	vec2 vec2::operator*=(float other) const {
		return multiply(other);
	}

	vec2 vec2::operator/=(float other) const {
		return divide(other);
	}

	vec2 vec2::operator+=(vec2 other) const {
		return add(other);
	}

	vec2 vec2::operator-=(vec2 other) const {
		return subtract(other);
	}

	vec2 vec2::operator*=(vec2 other) const {
		return multiply(other);
	}

	vec2 vec2::operator/=(vec2 other) const {
		return divide(other);
	}

	bool vec2::operator==(vec2 other) const {
		return x == other.x && y == other.y;
	}

	bool vec2::operator!=(vec2 other) const {
		return !(*this == other);
	}


} 
