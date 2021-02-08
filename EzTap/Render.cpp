#include "Render.hpp"

void CRender::Init(IDirect3DDevice9* dev)
{
	dx_Device = dev;
	interfaces.Engine->getScreenSize(&width, &height);
}

LPD3DXFONT CRender::createFont(std::string font, int size, UINT weight)
{
	LPD3DXFONT tmpFont;
	D3DXCreateFontA(dx_Device, size, 0, weight, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, font.c_str(), &tmpFont);
	return tmpFont;
}

void CRender::SetFont(LPD3DXFONT font)
{
	dx_Font = font;
}

void CRender::DrawCenterLine(float x, float y, int r, int g, int b, int a)
{
	static ID3DXLine* pLine3;

	if (!pLine3)
		D3DXCreateLine(dx_Device, &pLine3);

	D3DXVECTOR2 dLine1[2];

	pLine3->SetWidth(1);
	pLine3->SetAntialias(true);
	pLine3->SetGLLines(true);

	dLine1[0].x = width / 2;
	dLine1[0].y = 0;

	dLine1[1].x = x;
	dLine1[1].y = y;

	pLine3->Draw(dLine1, 2, D3DCOLOR_ARGB(a, r, g, b));
}

void CRender::DrawLine(float x, float y, float xx, float yy, int r, int g, int b, int a)
{
	static ID3DXLine* pLine1;

	if (!pLine1)
		D3DXCreateLine(dx_Device, &pLine1);

	D3DXVECTOR2 dLine[2];

	pLine1->SetWidth(1);
	pLine1->SetAntialias(true);
	pLine1->SetGLLines(true);

	dLine[0].x = x;
	dLine[0].y = y;

	dLine[1].x = xx;
	dLine[1].y = yy;

	pLine1->Draw(dLine, 2, D3DCOLOR_ARGB(a, r, g, b));
}

void CRender::FillRGB(float x, float y, float w, float h, int r, int g, int b, int a)
{
	static ID3DXLine* pLine;

	if (!pLine)
		D3DXCreateLine(dx_Device, &pLine);

	D3DXVECTOR2 vLine[2];

	pLine->SetWidth(w);
	pLine->SetAntialias(false);
	pLine->SetGLLines(true);

	vLine[0].x = x + w / 2;
	vLine[0].y = y;
	vLine[1].x = x + w / 2;
	vLine[1].y = y + h;

	pLine->Begin();
	pLine->Draw(vLine, 2, D3DCOLOR_RGBA(r, g, b, a));
	pLine->End();
}

void CRender::DrawBox(float x, float y, float width, float height, float px, int r, int g, int b, int a)
{
	FillRGB(x, y + height, width, px, r, g, b, a);
	FillRGB(x - px, y, px, height, r, g, b, a);
	FillRGB(x, y - px, width, px, r, g, b, a);
	FillRGB(x + width, y, px, height, r, g, b, a);
}

void CRender::DrawGUIBox(float x, float y, float w, float h, int r, int g, int b, int a, int rr, int gg, int bb, int aa)
{
	DrawBox(x, y, w, h, 1, r, g, b, a);        // Body outline 
	FillRGB(x, y, w, h, rr, gg, bb, a);        // Body color 
}

int CRender::DrawFont(std::string String, int x, int y, int r, int g, int b)
{
	RECT Font;
	Font.bottom = 0;
	Font.left = x;
	Font.top = y;
	Font.right = 0;

	dx_Font->DrawTextA(0, String.c_str(), strlen(String.c_str()), &Font, DT_NOCLIP, D3DCOLOR_ARGB(255, r, g, b));

	return 0;
}

int CRender::DrawShadowFont(std::string String, int x, int y, int r, int g, int b)
{
	RECT Font;
	Font.bottom = 0;
	Font.left = x;
	Font.top = y;
	Font.right = 0;

	RECT Fonts;
	Fonts.bottom = 0;
	Fonts.left = x + 1;
	Fonts.top = y;
	Fonts.right = 0;

	RECT Fonts1;
	Fonts1.bottom = 0;
	Fonts1.left = x - 1;
	Fonts1.top = y;
	Fonts1.right = 0;

	RECT Fonts2;
	Fonts2.bottom = 0;
	Fonts2.left = x;
	Fonts2.top = y + 1;
	Fonts2.right = 0;

	RECT Fonts3;
	Fonts3.bottom = 0;
	Fonts3.left = x;
	Fonts3.top = y - 1;
	Fonts3.right = 0;

	dx_Font->DrawTextA(0, String.c_str(), strlen(String.c_str()), &Fonts3, DT_NOCLIP, D3DCOLOR_ARGB(255, 1, 1, 1));
	dx_Font->DrawTextA(0, String.c_str(), strlen(String.c_str()), &Fonts2, DT_NOCLIP, D3DCOLOR_ARGB(255, 1, 1, 1));
	dx_Font->DrawTextA(0, String.c_str(), strlen(String.c_str()), &Fonts1, DT_NOCLIP, D3DCOLOR_ARGB(255, 1, 1, 1));
	dx_Font->DrawTextA(0, String.c_str(), strlen(String.c_str()), &Fonts, DT_NOCLIP, D3DCOLOR_ARGB(255, 1, 1, 1));
	dx_Font->DrawTextA(0, String.c_str(), strlen(String.c_str()), &Font, DT_NOCLIP, D3DCOLOR_ARGB(255, r, g, b));

	return 0;
}
