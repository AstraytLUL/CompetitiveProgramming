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

vector<int> ans;
set<int> adj[maxn];

void deconstruct(int u, int p){
    ans.pb(u);
    for(int v:adj[u]){
        if(v == p) continue;
        adj[v].erase(u);
        deconstruct(v, u);
    }
    adj[u].clear();
}

void dfs(int u, int p){
    for(int v:adj[u]){
        if(v == p) continue;
        dfs(v, u);
    }
    vector<int> tmp;
    for(auto v:adj[u]){
        if(v == p) continue;
        if(adj[v].empty()) tmp.pb(v);
    }
    for(auto x:tmp) adj[u].erase(x);
    if(adj[u].size() % 2 == 0){
        cerr << u << '\n';
        ans.pb(u);
        for(int v:adj[u]){
            if(v == p) continue;
            adj[v].erase(u);
            deconstruct(v, u);
        }
        adj[u].clear();
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        int p; cin >> p;
        if(p == 0) continue;
        adj[i].insert(p);
        adj[p].insert(i);
    }
    if(n % 2 == 0){
        cout << "NO\n";
        return;
    }
    dfs(1, 0);
    cout << "YES\n";
    for(auto v:ans){
        cout << v << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
