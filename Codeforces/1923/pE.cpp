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
#include <unordered_map>
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

int ans = 0;
unordered_map<int, int> dp[maxn];
vector<int> adj[maxn];
int col[maxn];

void init(int n){
    for(int i = 1; i <= n; ++i){
        adj[i].clear();
        col[i] = 0;
        dp[i].clear();
    }
    ans = 0;
}

void dfs(int u, int p = 0){
    dp[u][col[u]] = 1;
    for(auto v:adj[u]){
        if(v == p) continue;
        dfs(v, u);
        bool swapped = 0;
        if(dp[v].size() > dp[u].size()) swap(dp[u], dp[v]), swapped = 1;
        for(auto [x, y]:dp[v]){
            if(x == col[u]){
                if(swapped) ans += dp[u][x];
                else ans += y;
            }else{
                ans += y * dp[u][x];
                dp[u][x] += y;
            }
        }
        dp[v].clear();
    }
    dp[u][col[u]] = 1;
}

void solve(){
    int n; cin >> n;
    init(n);
    for(int i = 1; i <= n; ++i) cin >> col[i];
    for(int i = 1; i <= n - 1; ++i){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}