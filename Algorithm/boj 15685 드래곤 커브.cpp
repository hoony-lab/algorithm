// https://www.acmicpc.net/problem/15685
// 20200521 1419
//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//using vii = vector<pair<int, int>>;
//#define F(i, n) for(int i = 0 ; i < n ; ++i)
//#define MAX 101
//// R U L D
//int dy[] = { 0,-1,0,1 }, dx[] = { 1,0,-1,0 };
//
//int map[MAX][MAX];
//int n, x, y, d, g;
//void print() {
//	F(y, 10) {
//		F(x, 10) {
//			cout << map[y][x];
//		}cout << '\n';
//	}cout << "\n\n";
//}
//int count_square() {
//	int ans = 0;
//	F(y, MAX) F(x, MAX) {
//		if (!map[y][x] || !map[y][x + 1] ||
//			!map[y + 1][x] || !map[y + 1][x + 1]) continue;
//		ans++;
//	}
//	return ans;
//}
//void check_square(int cmap[][MAX]) {
//	F(y, MAX) F(x, MAX) {
//		map[y][x] = map[y][x] | cmap[y][x];
//	}
//}
//void rotate(vii v) {
//	int y = v.back().first, x = v.back().second;
//	int way;
//	int vsize = v.size();
//	for(int i = vsize - 2; i >= 0 ; --i){
//
//		int by = v[i + 1].first, bx = v[i + 1].second;
//		int ty = v[i].first, tx = v[i].second;
//		
//		F(a, 4) {
//			if (dx[a] != tx - bx || dy[a] != ty - by) continue;
//
//			way = a - 1;
//			way = (way + 4) % 4;
//			
//			break;
//		}
//		int ny = y + dy[way], nx = x + dx[way];
//
//		v.push_back({ nx, ny });
//		map[ny][nx] = true;
//	}
//}
//int main() {
//	// x,y 드래곤 커브 시작점, d 방향, g 세대
//	int t; cin >> t;
//	while (t--) {
//		cin >> x >> y >> d >> g;
//
//		vii v;
//		int ny = y + dy[d], nx = x + dx[d];
//		v.push_back({ x, y });
//		v.push_back({ nx, ny });
//		map[y][x] = map[ny][nx] = true;
//
//		F(i, g) rotate(v);
//	}
//
//	print();
//
//	cout << count_square() << '\n';
//	return 0;
//}






#include <iostream>
#include <vector>
#define MAX 101
#define F(i, n) for(int i = 0 ; i < n ; ++i)
using namespace std;
using vi = vector<int>;
// R U L D
int dx[] = { 0, -1, 0, 1 }, dy[] = { 1, 0, -1, 0 };
int nx, ny;
bool map[MAX][MAX];
vi v;

void dragon_curve(vi &v) {

	int vsize = (int)v.size();

	for (int i = vsize - 1; i >= 0; i--) {
		int way = (v[i] + 1) % 4;

		nx += dx[way];
		ny += dy[way];

		map[nx][ny] = true;

		v.push_back(way);
	}
}

int count_square() {
	int ans = 0;
	F(x, MAX - 1) {
		F(y, MAX - 1) {
			if (!map[x][y] || !map[x][y + 1] ||
				!map[x + 1][y] || !map[x + 1][y + 1]) continue;
			ans++;
		}
	}
	return ans;
}


int main() {
	int t, x, y, d, g;	cin >> t;
	F(a, t) {
		cin >> y >> x >> d >> g;
		v.clear();

		map[x][y] = true;

		nx = x + dx[d];
		ny = y + dy[d];
		map[nx][ny] = true;

		v.push_back(d);

		F(i, g) dragon_curve(v);
	}

	cout << count_square();

	return 0;
}

// https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-15685-%EB%93%9C%EB%9E%98%EA%B3%A4-%EC%BB%A4%EB%B8%8C
//#include <iostream>
//#include <vector>
//#define max_int 101
//using namespace std;
//
////시간 복잡도: O(n*2^g + xy)
////공간 복잡도: O(xy + n)
////사용한 알고리즘: 반복문
////사용한 자료구조: 스택(벡터), 2차원 배열
//
//int n, x, y, d, g, result;
//
////끝점의 정보
//int end_x, end_y;
//
//bool map[max_int][max_int];
//
////왼쪽, 위쪽, 오른쪽, 아래쪽
//int dx[] = { 0, -1, 0, 1 }, dy[] = { 1, 0, -1, 0 };
//
//
////이전 세대의 방향정보를 저장하는 스택
////stl 스택쓰면 귀찮으니까 인덱스로 접근 할 수 있는 벡터를 사용한다.
//vector<int> dragon;
//
////스택을 조사하면서 드래곤 커브를 만드는 함수
//void make_generation(vector<int>& dragon) {
//
//    //현재 스택의 크기를 먼저 계산해 놓는다.
//    int size = (int)dragon.size();
//
//    //스택의 뒤에서 부터 꺼내면서
//    //다음세대의 방향정보를 dir = (dragon[i] + 1)%4; 규칙에 따라 생성한다.
//    for (int i = size - 1; i >= 0; i--) {
//        int dir = (dragon[i] + 1) % 4;
//
//        //다음 세대의 방향정보를 바탕으로 다음 x,y를 찾고 이를 갱신한다.
//        end_x = end_x + dx[dir];
//        end_y = end_y + dy[dir];
//
//        //만들어진 드래곤 커브를 지도에 놓아준다.
//        map[end_x][end_y] = true;
//
//        //다음세대를 위하 스택에 방향정보를 넣어준다.
//        dragon.push_back(dir);
//    }
//}
//
//int main() {
//
//    scanf_s("%d", &n);
//
//    for (int i = 0; i < n; i++) {
//        //x, y의 순서를 바꿔서 입력받는다.
//        int y, x, d, g;
//        scanf_s("%d %d %d %d", &y, &x, &d, &g);
//
//        //기존 드래곤 커브의 스택을 비워준다.
//        dragon.clear();
//
//        //시작점에에 드래곤 커브가 놓여있으므로 지도에 표시해준다.
//        map[x][y] = true;
//
//        //0세대는 미리 만들어 놓는다.
//        end_x = x + dx[d];
//        end_y = y + dy[d];
//
//        //0세대를 만든 이후에도 지도에 표시해준다.
//        map[end_x][end_y] = true;
//
//        //0세대의 방향정보를 스택에 넣어준다.
//        dragon.push_back(d);
//
//        //반복문을 통해 0부터 차례차례 드래곤 커브를 만들면서 g세대까지 만든다.
//        for (int i = 0; i < g; i++) {
//
//            //드래곤 커브를 만들자
//            make_generation(dragon);
//        }
//
//    }
//
//    //100*100 2차원 행렬을 2중 for문 사용한 단순한 탐색
//    //인접한 4칸이 모두 true이면, 4칸이 모두 드래곤 커브의 일부인것
//    //갯수를 1증가시킨다.
//    for (int i = 0; i <= max_int - 2; i++) {
//        for (int j = 0; j <= max_int - 2; j++) {
//
//            //인접한 4칸의 정사각형이 모두 드래곤의 일부이면
//            if (map[i][j] == true && map[i][j + 1] == true && map[i + 1][j] == true && map[i + 1][j + 1] == true) {
//
//                //갯수를 1 증가시킨다.
//                result++;
//            }
//        }
//    }
//
//    //갯수 출력
//    printf("%d\n", result);
//    return 0;
//}