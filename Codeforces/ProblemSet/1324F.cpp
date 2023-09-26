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

vector<int> adj[maxn];
int col[maxn], dpw[maxn], dpb[maxn], ans[maxn];

void dfs1(int u, int p){
    if(col[u] == 0) dpb[u]++;
    else dpw[u]++;
    for(auto v:adj[u]){
        if(v == p) continue;
        dfs1(v, u);
        if(dpw[v] >= dpb[v]){
            dpw[u] += dpw[v];
            dpb[u] += dpb[v];
        }
    }
    ans[u] = dpw[u] - dpb[u];
}

void dfs2(int u, int p){
    int uw = dpw[u], ub = dpb[u], pw = dpw[p], pb = dpb[p];
    if(u != 1){
        if(uw >= ub){
            dpw[p] -= uw;
            dpb[p] -= ub;
        }
        if(dpw[p] >= dpb[p]){
            dpw[u] += dpw[p];
            dpb[u] += dpb[p];
        }
        ans[u] = dpw[u] - dpb[u];
    }
    for(auto v:adj[u]){
        if(v == p) continue;
        dfs2(v, u);
    }
    dpw[u] = uw;
    dpb[u] = ub;
    dpw[p] = pw;
    dpb[p] = pb;
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> col[i];
    for(int i = 1; i <= n - 1; ++i){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    for(int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
