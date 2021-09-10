#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 101
using namespace std;
int r, c, gr, gc, pr, pc;
char map[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> gr >> gc >> pr >> pc;
	for (int x = 0; x < r; ++x)
		for (int y = 0; y < c; ++y)
			cin >> map[x][y];

	bool find_g = false;
	for (int x = 0; x < r, !find_g; ++x) {
		for (int y = 0; y < c, !find_g; ++y) {

			if (map[x][y] == 'G') {
				find_g = true;
				for (int tx = x; tx < x + gr; ++tx) {
					for (int ty = y; ty < y + gc; ++ty) {
						if (map[tx][ty] == 'P') {
							cout << 0;
							return 0;
						}
					}
				}
			}
		}
	}

	for (int x = 0; x < r; ++x) {
		for (int y = 0; y < c; ++y) {
			if (map[x][y] == 'P') {
				for (int tx = x; tx < x + pr; ++tx) {
					for (int ty = y; ty < y + pc; ++ty) {
						if (map[tx][ty] == 'G') {
							cout << 0;
							return 0;
						}
					}
				}
			}
			else if (map[x][y] == 'G') {
				for (int tx = x; tx < x + gr; ++tx) {
					for (int ty = y; ty < y + gc; ++ty) {
						if (map[tx][ty] == 'G') {
							cout << 0;
							return 0;
						}
					}
				}
			}
		}
	}




}