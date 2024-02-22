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

char G[505][505];
int d[4] = {1, -1, 0, 0};

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> G[i][j];
        }
    }
    vector<string> ans;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(G[i][j] != '.') continue;
            queue<pii> bfs;
            vector<pii> tmp;
            bfs.push(mp(i, j));
            ans.pb("B " + to_string(i) + " " + to_string(j));
            G[i][j] = 'B';
            while(bfs.size()){
                pii p = bfs.front(); bfs.pop();
                int x = p.ff, y = p.ss;
                for(int k = 0; k < 4; ++k){
                    int nx = x + d[k], ny = y + d[3 - k];
                    if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
                    if(G[nx][ny] != '.') continue;
                    tmp.pb(mp(nx, ny));
                    G[nx][ny] = 'B';
                    bfs.push(mp(nx, ny));
                    ans.pb("B " + to_string(nx) + " " + to_string(ny));
                }
            }
            while(tmp.size()){
                pii p = tmp.back();
                tmp.pop_back();
                ans.pb("D " + to_string(p.ff) + " " + to_string(p.ss));
                ans.pb("R " + to_string(p.ff) + " " + to_string(p.ss));
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto s:ans) cout << s << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
