// exam4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

struct profile {
	char name[20];
	double grade;
	int english;
};

void input_data(profile *pStaff)
{
	for (int i = 0; i < 5; i++) {
		scanf_s("%s %lf %d",pStaff[i].name,20,&(pStaff[i].grade),&(pStaff[i].english) );
		
	
	}

}

void elite(profile *pStaff)
{

}

int main()
{
	struct profile new_staff[5];
	printf_s("데이터를 입력하세요 \n");
	input_data(new_staff);

    return 0;
}

