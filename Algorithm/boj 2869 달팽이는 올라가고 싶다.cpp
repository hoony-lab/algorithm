#include <iostream>
int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);	std::cout.tie(NULL);

	int a, b, v, ans;
	std::cin >> a >> b >> v;	

	ans = (v - a) / (a - b) ;
	if ((v - a) % (a - b) != 0) ans++;

	if (a >= v) std::cout << 1;
	else std::cout << ans + 1;
	
}

/*
2 1 5	4
3 1 20	9=18 10=21,20
3 2 20	17=17 18=20,19
*/