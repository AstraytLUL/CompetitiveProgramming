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

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int G[1005][1005], vis[1005][1005];

void solve(){
    int n, m, Y; cin >> n >> m >> Y;
    set<pair<int, pii>> s;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> G[i][j];
        }
    }
    for(int i = 1; i <= n; ++i){
        s.insert(mp(G[i][1], mp(i, 1)));
        s.insert(mp(G[i][m], mp(i, m)));
        vis[i][1] = vis[i][m] = 1;
    }
    for(int i = 1; i <= m; ++i){
        s.insert(mp(G[1][i], mp(1, i)));
        s.insert(mp(G[n][i], mp(n, i)));
        vis[1][i] = vis[n][i] = 1;
    }
    int cur = n * m;
    for(int y = 1; y <= Y; ++y){
        while(s.size() && (*s.begin()).ff <= y){
            auto [x, y] = (*s.begin()).ss;
            s.erase(s.begin());
            cur--;
            for(int i = 0; i < 4; ++i){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
                if(vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                s.insert(mp(G[nx][ny], mp(nx, ny)));
            }
        }
        cout << cur << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
