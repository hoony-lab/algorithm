#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &parent, int u) {
	if(u == parent[u])
		return u;

	parent[u] = find(parent, parent[u]);
	return parent[u];
}

bool merge(vector<int> &parent, int u, int v) {
	u = find(parent, u);
	v = find(parent, v);

	if(u == v)
		return true;

	parent[u] = v;
	return false;
}

int solution(int vertex, vector<vector<int>> connections) {
	int answer = 0;

	vector<int> parent(vertex+1);
	for(int i = 1; i <= vertex; i++)
		parent[i] = i;

	for(int i = 0; i < connections.size(); i++)
		if(merge(parent, connections[i][0], connections[i][1])) {
			answer = i + 1;
			break;
		}

	return answer;
}