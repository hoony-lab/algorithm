#include <iostream>
#include <string>
#define FOR(i, n) for(i = 0 ; i < n ; ++i)
#define ONE '1'
#define TWO '2'
/*
튀어나온 것이 이
들어간곳이 홈
서로 맞물리게 끼우는것이 킥다운 장치
맞물리게하는 가장 짧은 가로 너비
       2212112
2112112112

2212122
2112112112

2112212
2112112112
*/

int main() {
	char kick, down;
	int start, len, end = 0, mid = 0, count = 0, ans = 1e9;
	int is_kick, is_down;

	std::string shorts, longs, stack;
	std::cin >> shorts >> longs;

	if (shorts.size() > longs.size())
		std::swap(shorts, longs);



	while (count < shorts.size() + longs.size() - 1) {
		count++;
		len = 0;
		stack = "";

		// 끝
		//	  1212
		//121212
		if (count < shorts.size()) {
			end++;

			stack += longs[longs.size() - end - 1];

			FOR(start, end) {
				kick = shorts[start];
				down = longs[longs.size() - end + start];

				if (kick == TWO && down == TWO) break;

				if (kick == TWO && down == ONE)			stack.append("k");
				else if (kick == ONE && down == TWO)	stack.append("d");
				else if (kick == ONE && down == ONE)	stack.append("x");

				//std::cout << "END : " << start << " : " << longs.size() - end + start << '\n';
			}

			
		}
		// 처음
		//1212 
		// 121212
		else if (longs.size() < count) {

			end--;

			FOR(start, end + 1) {
				kick = shorts[shorts.size() - end - 1 + start];
				down = longs[start];

				if (kick == TWO && down == TWO) break;

				if (kick == TWO && down == ONE)			stack.append("k");
				else if (kick == ONE && down == TWO)	stack.append("d");
				else if (kick == ONE && down == ONE)	stack.append("x");

				//std::cout << "START : " << shorts.size() - end + start << " : " << start << '\n';
			}

			stack += longs[start + 1];
			
		}
		// 중간
		//  1212
		//121212
		else {
			len = -1;
			mid++;

			FOR(start, end) {
				kick = shorts[start];
				down = longs[longs.size() - shorts.size() + start - mid + 1];

				if (kick == TWO && down == TWO) break;

				if (kick == TWO && down == ONE)			stack.append("k");
				else if (kick == ONE && down == TWO)	stack.append("d");
				else if (kick == ONE && down == ONE)	stack.append("x");

				//std::cout << "MID : " << start << " : " << longs.size() - shorts.size() - mid + start << '\n';
			}

			
		}

		if (start == end) {
			int ind = 0, kickdown = false;
			
			std::cout << stack << '\n';
			//while (ind < shorts.length()) {

			//	if (stack[ind] == TWO || stack[ind] == 'd') {
			//		while (stack[ind + 1] == 'k')
			//			ind++;
			//		if (stack[ind + 1] == TWO || stack[ind + 1] == 'd') kickdown = true;
			//	}
			//	
			//	else if (stack[ind] == 'k') {
			//		while (stack[ind + 1] == 'd' || stack[ind + 1] == TWO)
			//			ind++;
			//		if (stack[ind + 1] == 'k') kickdown = true;
			//	}

			//}

			//if(kickdown)
				len += shorts.size() + longs.size() - end;
		}

		if (len > 0) {
			if (ans < len)
				break;
			ans = len;
		}

	}

	std::cout << ans;
	return 0;
}