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

int deg[maxn], vis[maxn];
vector<int> G[maxn], R[maxn];

void solve(){
    int n; cin >> n;
    queue<int> q, top;
    vector<int> ans;
    for(int i = 1; i <= n; ++i){
        int k; cin >> k;
        for(int j = 1; j <= k; ++j){
            int p; cin >> p;
            G[p].pb(i);
            deg[i]++;
            R[i].pb(p);
        }
    }
    q.push(1);
    while(q.size()){
        int u = q.front(); q.pop();
        for(auto v:R[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            q.push(v);
        }
        if(deg[u] == 0) top.push(u);
    }
    while(top.size()){
        int u = top.front(); top.pop();
        if(u == 1) break;
        ans.pb(u);
        for(auto v:G[u]){
            deg[v]--;
            if(vis[v] == 0) continue;
            if(deg[v] == 0) top.push(v);
        }
    }
    for(auto x:ans) cout << x << ' ';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
