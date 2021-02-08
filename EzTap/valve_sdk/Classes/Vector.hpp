#pragma once
#include <Windows.h>
#include <float.h>
#include <math.h>

class Vector
{
public:
	float x; //0x0000 
	float y; //0x0004 
	float z; //0x0008 

	Vector() { x = 0; y = 0; z = 0; }
	Vector(float ix, float iy, float iz) { x = ix; y = iy; z = iz; }
	void Clamp()
	{
		if (x > 89.f && x <= 180.f)
			x = 89.f;
		if (x > 180.0f)
			x = x - 360.0f;
		if (x < -89.0f)
			x = -89.0f;
		if (y > 180.0f)
			y = y - 360.0f;
		if (y < -180.0f)
			y = y + 360.0f;
	}

	auto Clamped() {
		Vector tmp = *this;
		tmp.Clamp();
		return tmp;
	}

	void Normalize()
	{
		if (x > 180)
			x -= 360.0f;
		if (x < 180)
			x += 360.0f;
		if (y > 180)
			y -= 360.0f;
		if (y < 180)
			y += 360.0f;
	}

	Vector operator-(Vector angle)
	{
		return Vector(x - angle.x, y - angle.y, z - angle.z);
	}

	Vector operator+(Vector angle)
	{
		return Vector(x + angle.x, y + angle.y, z + angle.z);
	}

	Vector operator*(const float& f)
	{
		return Vector(x * f, y * f, z * f);
	}

	Vector operator/(Vector angle)
	{
		return Vector(x / angle.x, y / angle.y, z / angle.z);
	}

	Vector operator/(const float& f)
	{
		return Vector(x / f, y / f, z / f);
	}

	Vector operator/=(float& f)
	{
		return Vector(x / f, y / f, z / f);
	}

	bool operator==(Vector v)
	{
		return (v.x == x && v.y == y && v.z == z);
	}

	bool operator!=(Vector v)
	{
		return(v.x != x || v.y != y || v.z != z);
	}

	bool IsNan()
	{
		if (isnan(x) || isnan(y) || isnan(z))
			return true;

		return false;
	}

	auto LengthSqr() const {
		return (x * x + y * y + z * z);
	}

	auto Length2DSqr() const {
		return (x * x + y * y);
	}

	auto Length() const {
		return sqrt(LengthSqr());
	}

	auto Length2D() const {
		return sqrt(Length2DSqr());
	}

	constexpr auto notNull() const noexcept
	{
		return x || y || z;
	}

	bool isNull()
	{
		return (x < 1 && y < 1 && z < 1);
	}

	//to RGB decimals to ints
	Vector ToRGB(Vector & in)
	{
		return in = in * 255;
	}

	//to RGB ints to decimals
	Vector ToDRGB(Vector & in)
	{
		return in = in / 255;
	}

	Vector FloatToColor(float* color)
	{
		return Vector(color[0], color[1], color[2]);
	}
};