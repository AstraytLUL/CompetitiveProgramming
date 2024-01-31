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
#define mod 1000000007

int dp[maxn];
vector<int> adj[maxn];

void dfs(int u, int p = -1){
    dp[u] = 1;
    for(auto v:adj[u]){
        if(v == p) continue;
        dfs(v, u);
        dp[u] += dp[v];
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i < n; ++i) {
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    int mx = 0;
    for(auto v:adj[1]){
        mx = max(mx, dp[v]);
    }
    cout << dp[1] - mx << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
