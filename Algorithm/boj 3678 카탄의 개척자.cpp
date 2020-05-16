#include <iostream>
#include <queue>
#include <algorithm>

#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define FE(i, n, m) for(int i = m ; i < n ; ++i)
#define FR(i, n, m) for(int i = m ; i >= n ; --i)
#define FIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define MAX 81

using vi = std::vector<int>;

// 층, 변, 위치
int blocks[MAX][6][MAX];
int count[6], block[10001];

void out(std::string s, int a, int b, int c) {
	std::cout << s << a << ", " << b << ", " << c << '\n';
}
void out(int n, int a, int b, int c) {
	std::cout << n << " :: " << a << ", " << b << ", " << c << '\n';
}

int play(int num) {
	if (num <= 7) {
		if (num <= 5) return num;
		if (num == 6) return 2;
		return 3;
	}

	int start = 0, end = MAX, floor, side, place;
	while (start <= end) {
		floor = (start + end) / 2;
		int s = (floor - 1) * 3 * floor + 2, e = floor * 3 * (floor + 1) + 2;

		//std::cout << s << " < " << e << '\n';

		if (s <= num && num < e) break;
		else if (num < s) end = floor - 1;
		else if (e <= num) start = floor + 1;
	}

	num -= ((floor - 1) * 3 * floor) + 2;
	side = num / floor;
	place = num % floor;

	//out("Answer : ", floor, side, place);

	return blocks[floor][side][place];
}

int min_count_block(vi v) {
	//FE(a, 6, 1) std::cout << count[a] << ", ";
	//std::cout << "\n";

	int min_count = 1e9, min_index;
	FR(i, 1, 5) if (count[i] <= min_count) {
		bool nope = false;
		for (int num : v) {
			if (num == i) nope = true;
		}
		if (nope) continue;
		min_count = count[i];
		min_index = i;
	}
	return min_index;
}
/*
	//blocks[2][0][0] = 1;		//8		((floor - 1) * 6) + (floor * side) + (place + 2)
	//blocks[2][0][1] = 4;		//9

	//blocks[2][1][0] = 5;		//10
	//blocks[2][1][1] = 1;		//11	((floor - 1) * 6) + (floor * side) + (place + 2)

	//blocks[2][2][0] = 2;		//12
	//blocks[2][2][1] = 3;		//13

	//blocks[2][3][0] = 1;		//14
	//blocks[2][3][1] = ? ;		//15

	((floor - 1) * 3 * floor) + (floor * side) + (place + 2)
*/

vi check_adjust_block(int floor, int side, int place) {
	vi v;

	//out("Check : ", floor, side, place);

	if (side == 0 && place == 0) {		/// 새로운 시작

		v.push_back(blocks[floor - 1][0][0]);
		v.push_back(blocks[floor - 1][5][floor - 2]);

		//out(blocks[floor - 1][0][0], floor - 1, 0, 0);
		//out(blocks[floor - 1][5][floor - 2], floor -1, 5, floor - 2);
	}
	else if (place == floor - 1) {		/// 새로운 변의 꼭짓점 or 변의 마지막
		v.push_back(blocks[floor][side][place - 1]);
		v.push_back(blocks[floor - 1][side][floor - 2]);

		//out(blocks[floor][side][place - 1], floor, side, place -1);
		//out(blocks[floor - 1][side][floor - 2], floor - 1, side, floor - 2);


		if (side == 5) {			/// 마지막 꼭지점
			v.push_back(blocks[floor][0][0]);
			//out(blocks[floor][0][0], floor,  0, 0);
		}
	}
	else if (place == 0) {
		//std::cout << "???????????????\n";
		v.push_back(blocks[floor][side - 1][floor - 1]);

		//out(blocks[floor][side - 1][floor - 1], floor, side - 1, floor - 1);

		if (floor == 2) {
			v.push_back(blocks[floor - 1][side - 1][place]);

			//out(blocks[floor - 1][side - 1][place], floor - 1, side - 1, place);
		}
		else {
			v.push_back(blocks[floor - 1][side - 1][floor - 2]);

			//out(blocks[floor - 1][side - 1][floor - 2], floor - 1, side - 1, floor - 2);
			//std::cout << "#################\n";
		}

		v.push_back(blocks[floor - 1][side][place]);

		//out(blocks[floor - 1][side][place], floor - 1, side, place);
	}
	else {								/// 변 가운데
		v.push_back(blocks[floor][side][place - 1]);		/// 이전 블록
		v.push_back(blocks[floor - 1][side][place - 1]);	/// 아래층 블록 - 1
		v.push_back(blocks[floor - 1][side][place]);		/// 아래층 블록

		//out(blocks[floor][side][place - 1], floor, side, place - 1);
		//out(blocks[floor - 1][side][place - 1], floor - 1, side, place - 1);
		//out(blocks[floor - 1][side][place], floor - 1, side, place);
		//std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	}

	// int num = ((floor - 1) * 6) + (floor * side) + (place + 2);

	//std::cout << "Adjust nums : ";
	//for (int i : v) std::cout << i << ", ";
	//std::cout << '\n';
	return v;
}

void init() {
	blocks[0][0][0] = 1, count[1]++;

	blocks[1][0][0] = 2, count[2]++;
	blocks[1][1][0] = 3, count[3]++;
	blocks[1][2][0] = 4, count[4]++;
	blocks[1][3][0] = 5, count[5]++;
	blocks[1][4][0] = 2, count[2]++;
	blocks[1][5][0] = 3, count[3]++;

	int num = 8;
	int floor = 2;
	while (floor < MAX) {
		F(side, 6) {
			F(place, floor) {
				//std::cout << "\n\nNUM : " << num++ << "   BLOCK : " << floor << ", " << side << ", " << place << '\n';
				vi v = check_adjust_block(floor, side, place);
				int new_block = min_count_block(v);

				blocks[floor][side][place] = new_block;
				count[new_block]++;
				//std::cout << "ADD : " << new_block << '\n';
			}
		}
		floor++;
	}
}

int main() {
	FIO; init();
	int n; std::cin >> n;
	while (n--) {
		int num; std::cin >> num;
		std::cout << play(num) << '\n';
	}
	return 0;
}

/*
4
1
4
10
100

1
4
5
5
*/