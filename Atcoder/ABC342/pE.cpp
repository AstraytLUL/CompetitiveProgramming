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

struct EDGE{
    int l, d, k, c, to;
}edg[maxn];

vector<int> adj[maxn];

void solve(){
    int n, m; cin >> n >> m;
    vector<int> reach(n + 1, -8e18);
    reach[n] = 8e18;
    for(int e = 1; e <= m; ++e){
        cin >> edg[e].l >> edg[e].d >> edg[e].k >> edg[e].c;
        int u, v; cin >> u >> v;
        adj[v].pb(e);
        edg[e].to = u;
    }
    priority_queue<pii> pq;
    pq.push(mp(8e18, n));
    while(pq.size()){
        pii tmp = pq.top();
        pq.pop();
        int D = tmp.ff, u = tmp.ss;
        if(D < reach[u]) continue;
        for(auto e:adj[u]){
            auto [l, d, k, c, v] = edg[e];
            if(l + c > D){
                continue;
            }
            int k0 = (D - l - c) / d;
            k0 = min(k0, k - 1);
            int time = l + k0 * d;
            if(time > reach[v]){
                reach[v] = time;
                pq.push(mp(reach[v], v));
            }
        }
    }
    for(int i = 1; i <= n - 1; ++i){
        if(reach[i] == -8e18) cout << "Unreachable\n";
        else cout << reach[i] << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
