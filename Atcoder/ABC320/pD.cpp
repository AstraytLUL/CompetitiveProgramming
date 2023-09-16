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

struct edge{
    int to, dx, dy;
    edge(int a, int b, int c){
        to = a, dx = b, dy = c;
    }
};

vector<edge> adj[maxn];

void solve(){
    int n, m; cin >> n >> m;
    vector<pii> p(n, pii(1e18, 1e18));
    p[0] = pii(0, 0);
    for(int i = 0; i < m; ++i){
        int a, b, x, y; cin >> a >> b >> x >> y;
        a--, b--;
        adj[a].pb(edge(b, x, y));
        adj[b].pb(edge(a, -x, -y));
    }
    vector<int> vis(n);
    queue<int> bfs;
    bfs.push(0);
    while(bfs.size()){
        int u = bfs.front(); bfs.pop();
        vis[u] = 1;
        for(auto [v, dx, dy]:adj[u]){
            if(vis[v]) continue;
            p[v] = pii(p[u].ff + dx, p[u].ss + dy);
            bfs.push(v);
        }
    }
    for(auto &[x, y]:p){
        if(x == 1e18 || y == 1e18) cout << "undecidable\n";
        else cout << x << ' ' << y << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
