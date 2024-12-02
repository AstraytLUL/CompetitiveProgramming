//君の手を握ってしまったら
//孤独を知らないこの街には
//もう二度と帰ってくることはできないのでしょう
//君が手を差し伸べた 光で影が生まれる
//歌って聞かせて この話の続き
//連れて行って見たことない星まで
//さユリ - 花の塔
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <bitset>
#include <climits>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cstring>
#include <fstream>
using namespace std;
typedef long long ll;
#define int ll
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define maxn 200005
#define mod 1000000007

int E[205][205], vis[205][205];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
char G[205][205];

void solve(){
    int n, m; cin >> n >> m;

    int sx, sy, ex, ey;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> G[i][j];
            if(G[i][j] == 'S') sx = i, sy = j;
            if(G[i][j] == 'T') ex = i, ey = j;
            vis[i][j] = -1;
        }
    }

    int N; cin >> N;
    for(; N; --N){
        int r, c; cin >> r >> c;
        int e; cin >> e;
        E[r][c] += e;
    }

    queue<pair<int, pii>> bfs;
    bfs.push(mp(E[sx][sy], mp(sx, sy)));
    vis[sx][sy] = E[sx][sy]; 
    E[sx][sy] = 0;

    while(bfs.size()){
        int e = bfs.front().ff;
        int x = bfs.front().ss.ff, y = bfs.front().ss.ss;
        e = max(e, E[x][y]);
        E[x][y] = 0;
        bfs.pop();
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 1 || ny < 1 || nx > n || ny > m || G[nx][ny] == '#') continue;
            if(e - 1 <= vis[nx][ny]) continue;
            vis[nx][ny] = e - 1;
            bfs.push(mp(e - 1, mp(nx, ny)));
        }
    }
    cout << (vis[ex][ey] != -1 ? "Yes": "No") << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
