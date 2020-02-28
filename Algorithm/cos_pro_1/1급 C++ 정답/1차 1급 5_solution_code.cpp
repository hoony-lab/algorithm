#include <bits/stdc++.h>
#define pb push_back
#define sz(v) (int)(v).size()
#define all(v) (v).begin(),(v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int pane[103][103];
int inRange(int i, int j, int n){
    return 0 <= i && i < n && 0 <= j && j < n;
}
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int solution(int n){
    int ci = 0, cj = 0;
    int num = 1;
    while(inRange(ci, cj, n) && pane[ci][cj] == 0){
        for(int k = 0; k < 4; k++){
            if(!inRange(ci, cj, n) || pane[ci][cj] != 0) break;
            while(1){
                pane[ci][cj] = num++;
                int ni = ci + dy[k];
                int nj = cj + dx[k];
                if(!inRange(ni, nj, n) || pane[ni][nj] != 0){
                    ci += dy[(k + 1) % 4];
                    cj += dx[(k + 1) % 4];
                    break;
                } 
                ci = ni;
                cj = nj;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans += pane[i][i];
    return ans;
}
