#pragma once

class Vector;

class matrix3x4 {
	float mat[3][4];
public:
	constexpr auto operator[](int i) const noexcept { return mat[i]; }
	Vector origin() const noexcept;
};

#include "Vector.hpp"

inline Vector matrix3x4::origin() const noexcept
{
	return Vector(mat[0][3], mat[1][3], mat[2][3]);
}