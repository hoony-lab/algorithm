#include <iostream>
long long a, goal, ans = 1e9;
void dfs(long long num, long long count) {
	if (num == goal) {
		ans > count ? ans = count : ans;
		return;
	}
	if (num > goal) return;

	dfs(num * 2, count + 1);
	dfs((num * 10) + 1, count + 1);
}
int main() {

	std::cin >> a >> goal;
	dfs(a, 1);
	if (ans == 1e9) std::cout << -1;
	else std::cout << ans;

}