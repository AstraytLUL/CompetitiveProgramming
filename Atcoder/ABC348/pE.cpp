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

int ans;
vector<int> adj[maxn];
int C[maxn], subS[maxn], dp[maxn];

void init(int u, int p){
    subS[u] = C[u];
    dp[u] = 0;
    for(int v:adj[u]){
        if(v == p) continue;
        init(v, u);
        subS[u] += subS[v];
        dp[u] += dp[v] + subS[v];
    }
}

void dfs(int u, int p){
    if(u != 1){
        dp[p] -= dp[u] + subS[u];
        subS[p] -= subS[u];
        subS[u] += subS[p];
        dp[u] += dp[p] + subS[p];
    }
    ans = min(ans, dp[u]);
    for(int v:adj[u]){
        if(v == p) continue;
        dfs(v, u);
    }
    if(u != 1){
        dp[u] -= dp[p] + subS[p];
        subS[u] -= subS[p];
        subS[p] += subS[u];
        dp[p] += dp[u] + subS[u];
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i <= n; ++i) cin >> C[i];
    init(1, 1);
    ans = dp[1];
    dfs(1, 1);
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
