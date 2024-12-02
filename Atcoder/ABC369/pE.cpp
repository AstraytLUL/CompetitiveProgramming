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

struct edge{
    int u, v, w;
};

int adj[405][405];

void solve(){
    int n, m; cin >> n >> m;
    vector<edge> e(m);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j) 
            if(i != j) adj[i][j] = 1e18;
    }
    for(auto &[u, v, w]:e){
        cin >> u >> v >> w;
        adj[u][v] = min(adj[u][v], w);
        adj[v][u] = min(adj[v][u], w);
    }
    for(int _ = 0; _ < 3; ++_){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                for(int k = 1; k <= n; ++k){
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }
    int q; cin >> q;
    for(; q; q--){
        int k; cin >> k;
        vector<int> b(k);
        for(auto &x:b) cin >> x, x--;
        sort(b.begin(), b.end());
        int cost = 1e18;
        do{
            for(int s = 0; s < (1<<k); ++s){
                int t = e[b[k - 1]].w;
                if(s & 1){
                    int from = 1, to = e[b[0]].u;
                    //cout << from << ' '  << to << ' ' << adj[from][to] << '\n';
                    t += adj[from][to];
                }else{
                    int from = 1, to = e[b[0]].v;
                    //cout << from << ' '  << to << ' ' << adj[from][to] << '\n';
                    t += adj[from][to];
                }
                for(int i = 0; i < k - 1; ++i){
                    t += e[b[i]].w;
                    int from = (s & (1<<i) ? e[b[i]].v : e[b[i]].u), to = (s & (1<<(i + 1)) ? e[b[i + 1]].u : e[b[i + 1]].v);
                    t += adj[from][to];
                }
                if(s & (1<<(k - 1))){
                    int from = e[b[k - 1]].v, to = n;
                    //cout << from << ' '  << to << ' ' << adj[from][to] << '\n';
                    t += adj[from][to];
                }else{
                    int from = e[b[k - 1]].u, to = n;
                    //cout << from << ' '  << to << ' ' << adj[from][to] << '\n';
                    t += adj[from][to];
                }
                //cout << t << '\n';
                cost = min(cost, t);
            }
        }while(next_permutation(b.begin(), b.end()));
        cout << cost << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
