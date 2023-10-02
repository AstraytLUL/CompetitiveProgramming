#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;
#define pii pair<int, int>
#define ff first
#define ss second
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pb push_back

vector<pii> adj[100005];
int L[21][21];
double dp[21][1<<21];
bool connected = 1;

void dijkstra(int s, int n, vector<pii> sp, int id){
    vector<int> dist(n + 1, 1e10);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, s));
    while(pq.size()){
        pii p = pq.top(); pq.pop();
        if(dist[p.ss] < p.ff) continue;
        auto [d, u] = p;
        for(auto [v, w]:adj[u]){
            if(dist[v] > d + w){
                dist[v] = d + w;
                pq.push(pii(dist[v], v));
            }
        }
    }
    for(int i = 0; i < sp.size(); ++i){
        L[id][i] = L[i][id] = dist[sp[i].ff];
    }
    if(s == 1 && dist[n] == 1e10) connected = 0;
}

void solve(){
    int t, r; cin >> t >> r;
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u, v, l; cin >> u >> v >> l;
        adj[u].pb(pii(v, l));
        adj[v].pb(pii(u, l));
    }
    int k; cin >> k;
    vector<pii> sp(k);
    for(auto &[v, p]:sp){
        cin >> v >> p;
    }
    int fin = 0, fin2 = 0;
    for(auto pa : sp){
        if(pa.first == 1){
            fin = 1;
        }
        if(pa.ff == n){
            fin2 = 1;
        }
    }
    if(!fin) sp.pb(pii(1, 100));
    if(!fin2) sp.pb(pii(n, 100));
    sort(sp.begin(), sp.end());
    for(int i = 0; i < sp.size(); ++i){
        int u = sp[i].ff;
        dijkstra(u, n, sp, i);
    }
    if(connected == 0) {
        cout << -1 << '\n';
        return;
    }
    if(k == 0){
        cout << fixed << setprecision(7) << 1.0 * L[0][1] / t << '\n';
        return;
    }
    int sz = sp.size();
    for(auto &x:dp){
        for(auto &y:x){
            y = 1e18;
        }
    }
    vector<int> v;
    for(int s = 0; s < (1<<sz) - 1; s++){
        v.pb(s);
    }
    sort(v.begin(), v.end(), [](int a, int b){return __builtin_popcount(a) > __builtin_popcount(b);});
    dp[sz - 1][(1<<sz) - 1] = 0;
    for(auto s:v){
        for(int i = 0; i < sz; ++i){
            for(int j = 0; j < sz; ++j){
                if((s & (1<<i)) == 0 || (s & (1<<j)) || i == j) continue;
                double p = sp[i].ss / 100.00, pp = 1.0 - p;
                dp[i][s] = min(dp[i][s], pp * L[i][sz - 1] / r + p * min(dp[j][s ^ (1 << j)] + (1.0 * L[i][j] / t), 1.0 * L[i][sz - 1] / (double)t));
            }
        }
    }
    cout << fixed << setprecision(7) << dp[0][1] << '\n';
}

signed main(){
    io
    int t = 1; //cin >> t;
    while(t--) solve();
}