#include <iostream>
#define MAX(x,y) x > y ? x : y

int main() {

	int card[101];
	int n, blackjack, max_card_sum = 0;

	std::cin >> n >> blackjack;

	for (int i = 0; i < n; ++i)
		std::cin >> card[i];

	for (int i = 0; i < n - 2; ++i) {
		for (int j = i + 1; j < n - 1; ++j) {
			for (int k = j + 1; k < n; ++k) {
				int tmp_max_card_sum = card[i] + card[j] + card[k];
				if (tmp_max_card_sum > blackjack) continue;
				max_card_sum = MAX(max_card_sum, tmp_max_card_sum);
			}
		}
	}

	std::cout << max_card_sum;

}