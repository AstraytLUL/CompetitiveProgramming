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

int a[maxn], ans[maxn];
vector<int> adj[maxn];

void solve(){
    int n; cin >> n;
    vector<int> odd, even;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i){
        int l = i - a[i], r = i + a[i];
        if(l > 0) adj[l].pb(i);
        if(r <= n) adj[r].pb(i);
        if(a[i] % 2) odd.pb(i);
        else even.pb(i);
    }
    queue<int> bfs;
    vector<int> dist(n + 1, 1e9);
    for(auto x:odd) bfs.push(x), dist[x] = 0;
    while(bfs.size()){
        int u = bfs.front();
        bfs.pop();
        for(auto v:adj[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                bfs.push(v);
            }
        }
    }
    for(auto x:even) ans[x] = dist[x];
    dist.assign(n + 1, 1e9);
    for(auto x:even) bfs.push(x), dist[x] = 0;
    while(bfs.size()){
        int u = bfs.front();
        bfs.pop();
        for(auto v:adj[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                bfs.push(v);
            }
        }
    }
    for(auto x:odd) ans[x] = dist[x];
    for(int i = 1; i <= n; ++i) cout << (ans[i] >= 1e9 ? -1 : ans[i]) << ' ';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
