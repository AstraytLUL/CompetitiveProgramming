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
#define maxn 300005
#define mod 998244353

int dp[maxn][2];
vector<int> adj[maxn];

void dfs(int u, int p){
    dp[u][0] = 1;
    for(int v:adj[u]){
        if(v == p) continue;
        dfs(v, u);
        dp[u][1] += (1 + dp[v][0]);
        dp[u][1] %= mod;
        dp[u][0] *= (dp[v][0] + 2);
        dp[u][0] %= mod;
    }
    dp[u][0] -= 1;
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        adj[i].clear();
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
    for(int i = 1; i <= n - 1; ++i){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans = 0;
    dfs(1, 1);
    for(int i = 1; i <= n; ++i) ans = (ans + dp[i][1]) % mod;
    cout << (ans + 2 + dp[1][0]) % mod << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
