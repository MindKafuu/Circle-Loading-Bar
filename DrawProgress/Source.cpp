#include <windows.h>
#include<iostream>
#include<string>
#include<math.h>

void main() {
	Sleep(1000);

	const HWND handle = GetConsoleWindow();
	const HDC dc = GetDC(handle);

	SetTextColor(dc, RGB(255, 255, 255));
	SetBkColor(dc, RGB(0, 0, 0));

	SelectObject(dc, GetStockObject(DC_BRUSH));
	SetDCBrushColor(dc, RGB(255, 0, 0));

	const int off_x = 150,
		off_y = 150,
		pr = 20,
		r = 100;

	const float round = 2 * 3.14,
		step = pr / 100.0;

	for (register float i = 0; i < round; i += step) {
		RECT rect;
		rect.left = off_x;
		rect.top = off_y;
		int percen = (int)((i + step) / round * 100.0);
		std::string p_text = std::to_string(percen > 100 ? 100 : percen) + "%";
		std::wstring w_text(p_text.begin(), p_text.end());
		LPCTSTR t = w_text.c_str();
		DrawText(dc,t, -1, &rect, DT_SINGLELINE | DT_NOCLIP);
		int x = off_x + cos(i) * r;
		int y = off_y + sin(i) * r;
		Ellipse(dc, x, y, x + pr, y + pr);
		Sleep(200);
		// done.
	} 

	std::cin.get();
}