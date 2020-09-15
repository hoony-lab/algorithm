#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 300001
#define D cout << "D"
#define G cout << "G"
#define DG cout << "DUDUDUNGA"
int find_d() {

}
int find_g() {

}
int main() {
    int n, u, v;
    cin >> n;

    //vector<int> v(MAX); generate(v.begin(), v.end(), [num = 0]() mutable {return num++; });

    vector<int> graph[MAX];
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        
        find_g();
        find_d();
    }

	return 0;
}

/*
 D-트리 : ‘ㄷ’이 ‘ㅈ’의 3배보다 많은 트리                ㄷ > ㅈ * 3
 G-트리 : ‘ㄷ’이 ‘ㅈ’의 3배보다 적은 트리                ㄷ < ㅈ * 3
 DUDUDUNGA-트리 : ‘ㄷ’이 ‘ㅈ’의 정확히 3배만큼 있는 트리 ㄷ == ㅈ * 3
 */