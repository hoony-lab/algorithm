#include <iostream>
#include <string>

int main() {
	std::string a, b, aa, bb;
	std::cin >> a >> b;
	
	for (int i = a.size() - 1; i >= 0; --i)
		aa += a[i];

	for (int i = b.size() - 1; i >= 0; --i)
		bb += b[i];

	stoi(aa) > stoi(bb) ?
		std::cout << stoi(aa) :
		std::cout << stoi(bb);
	
	return 0;
}