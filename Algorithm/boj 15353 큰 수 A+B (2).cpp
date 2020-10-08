#include <iostream>
#include <string>
using namespace std;
string a, b, ans;
int alen, blen, upper;
int main() {
	cin >> a >> b; if (b.size() > a.size()) swap(a, b);

	alen = a.size(), blen = b.size();

	// a 가 항상 큰수
	for (int i = 0; i < alen - blen; ++i) b = "0" + b;

	//cout << a << " , " << b << '\n';

	for (int i = alen - 1; i >= 0; --i) {
		int aa = a[i] - '0', bb = b[i] - '0';

		if (upper) aa++, upper--;

		if (aa + bb > 9) {
			upper++;
			ans = to_string(aa + bb - 10) + ans;
		}
		else ans = to_string(aa + bb) + ans;
	}

	if (upper) ans = "1" + ans;

	cout << ans;
	return 0;
}
/*
92275807
4778


18446744073709551615
18446744073709551615

15
6
*/