// https://www.acmicpc.net/problem/16235
// 20200604 2049
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 11
#define F(i, n) for(int i = 0 ; i < n ; ++i)
struct T { int x, y, z; };
using vT = std::vector<T>;
vT tree;
int dx[] = { -1,-1,-1,0,1,1,1,0 }, dy[] = { -1,0,1,1,1,0,-1,-1 };
int A[MAX][MAX], map[MAX][MAX];
int n, m, k;

void print(int map[][MAX]) {
	std::cout << "map \n";
	F(x, n) {
		F(y, n) {
			std::cout << map[x][y];
		}std::cout << '\n';
	};
}
void print_tree() {
	std::cout << "tree \n";
	for (auto t : tree) {
		std::cout << t.x << ", " << t.y << ", " << t.z << '\n';
	}
}
bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}

void spring() {
	// 나이가 어린 나무 부터 양분을 먹는다.
	std::sort(tree.begin(), tree.end(), [](T t1, T t2) {
		return t1.z < t2.z;
	});
	int tree_size = (int)tree.size();

	F(i, tree_size) {
		int tx = tree[i].x, ty = tree[i].y, tz = tree[i].z;
		if (tz < 0 ) continue;

		// 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다. (나이를 음수처리 함으로써 죽음 표시)
		if (tz > map[tx][ty]) tree[i].z *= -1;
		else	 map[tx][ty] -= tree[i].z;
		
	}
}
void summer() {
	int tree_size = (int)tree.size();
	F(i, tree_size) {
		// 봄에 죽은 나무가 양분으로 변하게 된다.
		int tx = tree[i].x, ty = tree[i].y, tz = tree[i].z;
		if (tz) continue;
		map[tx][ty] += (-tz) / 2;

		// tree.erase(tree.begin() + i);
	}
}
void autumn() {
	int tree_size = (int)tree.size();
	F(i, tree_size) {
		int tz = tree[i].z;
		// 번식하는 나무는 나이가 5의 배수이어야 하며,
		if (!tz || tz % 5 != 0) continue;

		// 인접한 8개의 칸에 나이가 1인 나무가 생긴다. 
		F(a, 8) {
			int nx = tree[i].x + dx[a], ny = tree[i].y + dy[a];
			if (!check(nx, ny)) continue;
			tree.push_back({ nx,ny,1 });
		}
	}
}
void winter() {
	F(x, n) F(y, n) map[x][y] += A[x][y];
}

int main() {
	std::cin >> n >> m >> k;
	// 가장 처음에 양분은 모든 칸에 5만큼
	F(x, n) F(y, n) std::cin >> A[x][y], map[x][y] = 5;
	F(i, m) {
		int x, y, z;
		std::cin >> x >> y >> z;
		//  r과 c는 1부터 시작한다.
		tree.push_back({ x - 1,y - 1,z });
	}
	
	F(year, k) {
		print(map);
		print_tree();
		std::cout << "\n\n";

		spring();
		summer();
		autumn();
		winter();


	}

	auto zz = std::count_if(tree.begin(), tree.end(), [](T t1) {
		return t1.z > 0;
	});

	std::cout << zz;
	return 0;
}