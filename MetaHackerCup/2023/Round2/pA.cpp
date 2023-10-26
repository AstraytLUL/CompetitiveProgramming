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

int n, m;
vector<int> d = {1, -1, 0, 0};
vector<vector<bool>> vis;
vector<vector<int>> cnt;
vector<vector<char>> g;

pii check(int i, int j){
    set<pii> st;
    queue<pii> bfs;
    bfs.push(pii(i, j));
    vis[i][j] = 1;
    int sz = 0;
    while(bfs.size()){
        auto [x, y] = bfs.front();
        bfs.pop();
        sz++;
        for(int i = 0; i < 4; ++i){
            int nx = x + d[i], ny = y + d[3 - i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny]) continue;
            if(g[nx][ny] == '.'){
                st.insert(pii(nx, ny));
                continue;
            }
            if(g[nx][ny] == 'B') continue;
            bfs.push(pii(nx, ny));
            vis[nx][ny] = 1;
        }
    }
    if(st.size() == 1){
        auto [x, y] = *st.begin();
        cnt[x][y] += sz;
    }
    return pii(sz, st.size());
}

void solve(int tc){
    cin >> n >> m;
    g.assign(n, vector<char>(m, '.'));
    vis.assign(n, vector<bool>(m, 0));
    cnt.assign(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> g[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(g[i][j] == 'W' && !vis[i][j]){
                pii cur = check(i, j);
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            ans = max(ans, cnt[i][j]);
        }
    }
    cout << "Case #" << tc << ": ";
    cout << ans << '\n';
}

signed main(){
    starburst
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 1; cin >> t;
    for(int i = 1; i <= t; ++i) solve(i);
}
