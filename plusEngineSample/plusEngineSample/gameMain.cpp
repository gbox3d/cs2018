#include "stdafx.h"
#include "gameMain.h"

Image *g_pImage;
void OnGdiplusSetup()
{
	//Image _tmp(L"../../pub_res/ww2/Fighters/p38g.png");
	g_pImage = new Image(L"../../pub_res/ww2/Fighters/p38g.png");//_tmp.Clone();

}

void OnGdiplusFinish()
{
	delete g_pImage;

}


void OnGdiplusRender(double fDelta, Graphics *pGrp)
{

	pGrp->Clear(Color(200, 200, 200));

	Pen penRed(Color(255, 0, 0));
	Pen penBlack(Color(0, 0, 0));
	Gdiplus::SolidBrush brushBalck(Color(0, 255, 0));

	pGrp->DrawLine(&penBlack, 160, 0, 160, 240);
	pGrp->DrawLine(&penBlack, 0, 120, 320, 120);
	pGrp->DrawRectangle(&penBlack, Rect(0, 0, 320, 240));

	pGrp->TranslateTransform(160, 120);

	pGrp->DrawImage(g_pImage, 0, 0);

	pGrp->ResetTransform();

}