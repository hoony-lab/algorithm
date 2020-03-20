#include <iostream>
#include <string>

int ans;

void dfs(int num, int one, int two, int three,int goal) {
	if (num == goal) {
		ans++; return;
	}
	if (num > goal) return;

	dfs(num + 1, one + 1, two, three, goal);
	dfs(num + 2, one, two + 1, three, goal);
	dfs(num + 3, one, two, three + 1, goal);
}

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		int n;
		ans = 0;
		std::cin >> n;

		dfs(0,0,0,0,n);

		std::cout << ans << '\n';
	}


	return 0;
}