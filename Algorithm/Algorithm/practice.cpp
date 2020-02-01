#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>

#pragma warning( disable : 4996)

//typedef unsigned char  vuint8
//typedef vuint8 bbb;


#define KKK static
typedef unsigned char TYPE;

#define AAA(aaa,bbb,ccc)    aaa bbb

int main() {
	AAA(KKK, TYPE, MM) vvv;
	static unsigned char aaaa;
	vvv = 120;
	aaaa = vvv + 1;

	//cout << "WHAT << " << vvv << " >>" <<  endl;
	//cout << "WHAT << " << aaaa << " >>" <<  endl;

	int eng, math, sci, studentID;

	scanf("%d", &studentID);
	scanf("%d", &eng);
	scanf("%d", &math);
	scanf("%d", &sci);
	printf("학번은 %d\n", studentID);

	printf("영어 %d, 수학 %d, 과학 %d\n", eng, math, sci);
	printf("총점 %d, 평균 %.2f", eng + math + sci, (float)(eng + math + sci) / 3);

	
	system("pause");
}