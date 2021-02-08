#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <cstdlib>
#include <string>
#include "valve_sdk/Classes/Vector.hpp"
#include "Interfaces.hpp"

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

class CRender
{
private:
	int width, height;
	IDirect3DDevice9* dx_Device;
	LPD3DXFONT dx_Font;

public:
	void Init(IDirect3DDevice9* dev);
	LPD3DXFONT createFont(std::string font, int size, UINT weight = FW_BOLD);
	void SetFont(LPD3DXFONT font);
	void DrawCenterLine(float x, float y, int r, int g, int b, int a);
	void DrawLine(float x, float y, float xx, float yy, int r, int g, int b, int a);
	void FillRGB(float x, float y, float w, float h, int r, int g, int b, int a);
	void DrawBox(float x, float y, float width, float height, float px, int r, int g, int b, int a);
	void DrawGUIBox(float x, float y, float w, float h, int r, int g, int b, int a, int rr, int gg, int bb, int aa);
	int DrawFont(std::string String, int x, int y, int r, int g, int b);
	int DrawShadowFont(std::string String, int x, int y, int r, int g, int b);
}inline Render;