// exam8.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

double getMinValue(double *ap,int nLength)
{
	double _min = 99999999;

	for (int i = 0; i < nLength; i++) {
		if (_min > ap[i]) {
			_min = ap[i];
		}
	}
	return _min;
}


int main()
{
	double ary[] = { 1.5,20.1,16.4,2.3,3.5 ,0.7,0.9,0.3};
	printf_s("%lf \n", getMinValue(ary, sizeof(ary)/sizeof(double)) );

    return 0;
}

