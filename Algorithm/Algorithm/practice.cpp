#include <iostream>
using namespace std;





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

	cout << "WHAT << " << vvv << " >>" <<  endl;
	cout << "WHAT << " << aaaa << " >>" <<  endl;

	system("pause");
}