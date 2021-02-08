#include "IEngineClient.hpp"

Vector IEngineClient::CalcAngle(Vector src, Vector dst)
{
	Vector angles;
	Vector delta = dst - src;

	VectorAngles(delta, angles);

	angles.Clamp();

	return angles;
}

void IEngineClient::VectorAngles(Vector& forward, Vector& angles)
{
	if (forward.y == 0 && forward.x == 0) {
		angles.x = forward.z > 0.f ? 270.f : 90.f;
		angles.y = 0;
	}

	else {
		angles.x = (atan2(-forward.z, forward.Length2D()) * 180 / 3.14159265358979323846);
		if (angles.x < 0)
			angles.x += 360;

		angles.y = (atan2(forward.y, forward.x) * 180 / 3.14159265358979323846);
		if (angles.y < 0)
			angles.y += 360;
	}

	angles.z = 0;
}

bool IEngineClient::ScreenTransform(Vector in, Vector& out)
{
	matrix3x4& w2sMatrix = *reinterpret_cast<matrix3x4*>(Modules::Client + Offsets::ViewMatrix);

	out.x = w2sMatrix[0][0] * in.x + w2sMatrix[0][1] * in.y + w2sMatrix[0][2] * in.z + w2sMatrix[0][3];
	out.y = w2sMatrix[1][0] * in.x + w2sMatrix[1][1] * in.y + w2sMatrix[1][2] * in.z + w2sMatrix[1][3];
	out.z = 0.0f;

	float w = w2sMatrix[3][0] * in.x + w2sMatrix[3][1] * in.y + w2sMatrix[3][2] * in.z + w2sMatrix[3][3];

	if (w < 0.001f) {
		out.x *= 100000;
		out.y *= 100000;
		return false;
	}

	out.x /= w;
	out.y /= w;

	return true;
}

bool IEngineClient::WorldToScreen(Vector in, Vector& out)
{
	static int w, h;

	if (!w || !h)
		getScreenSize(&w, &h);

	if (ScreenTransform(in, out)) {
		out.x = (w / 2.0f) + (out.x * w) / 2.0f;
		out.y = (h / 2.0f) - (out.y * h) / 2.0f;

		return true;
	}
	return false;
}