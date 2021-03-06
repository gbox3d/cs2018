// _8_irrlicht_binding.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../engine/irrlicht/include/irrlicht.h"

int main()
{
	irr::core::vector2df test;
	test = irr::core::vector2df(10, 0);

	printf_s("원본 : %lf %lf \n", test.X, test.Y);

	test.normalize();
	printf_s("정규화 : %lf %lf \n", test.X, test.Y);

	test.rotateBy(45);
	printf_s("회전 : %lf %lf \n", test.X, test.Y);

    return 0;
}

