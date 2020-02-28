#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int r, c, t;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int map[51][51], copymap[51][51];
int conditionerY[2];

long long answer;
void print() {

	cout << "\nmap\n";
	for (int y = 0; y < r; y++)
	{
		for (int x = 0; x < c; x++)
		{
			cout << map[y][x] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int count;
	answer = 0;
	cin >> r >> c >> t;

	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			int temp;
			cin >> temp;
			map[y][x] = temp;

			if (temp == -1) {
				conditionerY[0] = y - 1;
				conditionerY[1] = y;
			}
		}
	}


	for (int time = 0; time < t; time++) {
		//cout << "!!!!!!!!!!!TIME : " << time << '\n';

		memset(copymap, 0, sizeof(copymap));

		//diffusion
		for (int y = 0; y < r; y++) {
			for (int x = 0; x < c; x++) {

				if (map[y][x] < 1) continue;

				count = 0;

				for (int a = 0; a < 4; a++){
					int ny = y + dy[a];
					int nx = x + dx[a];

					if (ny < 0 || nx < 0 || ny >= r || nx >= c || map[ny][nx] == -1) continue;
					
					copymap[ny][nx] = copymap[ny][nx] + map[y][x] / 5;
					count++;
				}

				map[y][x] = map[y][x] - map[y][x] / 5 * count;

			}
		}

		for (int y = 0; y < r; y++) {
			for (int x = 0; x < c; x++) {
				map[y][x] += copymap[y][x];
			}
		}



		//cout << "diffusion ";
		//print();
		





		//ventilation
		for (int way = 1; way > -2; way -= 2) {
			int ty = conditionerY[((way + 3) % 4) / 2];
			int tx = 0;
			int nny, nnx;

			//cout << way << " , " << ty << " ," << tx << '\n';

			for (int a = 0; a < 4; a++) {
				//int nny = ty + dy[a] * way;
				//int nnx = tx + dx[a];

				while (true) {
					nny = ty + dy[a] * way;
					nnx = tx + dx[a];
					
					if (nny < 0 || nnx < 0 || nny >= r || nnx >= c ) break;
					
					if (map[nny][nnx] == -1) {
						map[ty][tx] = 0;
						break;
					}
					if (way == 1) {
						if (nny > conditionerY[0]) break;
					}
					else {
						if (nny < conditionerY[1]) break;
					}

					//if (nny == conditionerY[((way + 3) % 4) / 2] && nnx == 0) break;

					//cout << nny << ", " << nnx << '\n';

					if (map[ty][tx] == -1) {
						map[nny][nnx] = 0;
					}
					else map[ty][tx] = map[nny][nnx];

					ty = nny;
					tx = nnx;

				}

			}

		}

		//cout << "ventilation ";
		//print();

	}




	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			answer += map[y][x];
		}
	}
	cout << answer+2;


}

