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

int in[maxn], dp[maxn], dp2[maxn][2], t = 1, cnt = 0, id[maxn], ans = 0;
vector<int> adj[maxn], stk;
set<int> bccadj[maxn];

void dfs(int u, int p){
    in[u] = dp[u] = t++;
    stk.pb(u);
    for(auto v:adj[u]){
        if(v == p) continue;
        if(in[v]) {
            dp[u] = min(in[v], dp[u]);
            continue;
        }
        dfs(v, u);
        dp[u] = min(dp[v], dp[u]);
    }
    if(in[u] == dp[u]) {
        int cur;
        cnt++;
        do{
            cur = stk.back();
            stk.pop_back();
            id[cur] = cnt;
        }while(cur != u);
    }
}

void dfs2(int u, int p){
    for(auto v:bccadj[u]){
        if(v == p) continue;
        dfs2(v, u);
        int len = dp2[v][0] + 1;
        if(len >= dp2[u][0]) swap(len, dp2[u][0]);
        if(len >= dp2[u][1]) swap(len, dp2[u][1]);
    }
    ans = max(ans, dp2[u][0] + dp2[u][1]);
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 1);
    for(int i = 1; i <= n; ++i){
        for(auto v:adj[i]){
            if(id[i] != id[v]){
                bccadj[id[i]].insert(id[v]);
                bccadj[id[v]].insert(id[i]);
            }
        }
    }
    dfs2(1, 1);
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
