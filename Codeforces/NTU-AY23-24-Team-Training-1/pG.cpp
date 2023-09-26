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
int L[25][25];
double dp[20][1<<20], dp2[20][1<<20];
bool connected = 1;

void dijkstra(int s, int n, vector<pii> sp, int id){
    vector<int> dist(n + 1, 1e9);
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
    if(s == 1 && dist[n] == 1e9) connected = 0;
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
    sp.pop_back();
    int sz = sp.size();
    for(auto &x:dp){
        for(auto &y:x){
            y = 1e18;
        }
    }
    for(auto &x:dp2){
        for(auto &y:x){
            y = 1;
        }
    }
    double p[sz];
    for(int i = 0; i < sz; ++i){
        p[i] = sp[i].ss / 100.00;
    }
    dp[n][(1<<sz) - 1] = 0;
    for(int s = 0; s < (1<<sz); s++){
        for(int x = 0; x < sz; x++){
            if((s & (1<<x)) == 0) continue;
            for(int y = 0; y < sz; ++y){
                if((s & (1<<y)) == 0 || x == y) continue;
                double d = dp[y][s ^ (1<<x)] + dp2[y][s ^ (1<<x)] * (p[y] * L[y][x] / t + (1.0 - p[y]) * L[y][sz] / r);
                if(d < dp[x][s]){
                    dp[x][s] = d;
                    dp2[x][s] = dp2[y][s^(1<<x)] * p[y];
                }
            }
        }
    }
    double ans = 1e18;
    for(int s = 0; s < (1<<sz); ++s){
        if((s & 1) == 0) continue;
        for(int i = 1; i < sz; ++i){
            if((s & (1 << i)) == 0) continue;
            ans = min(ans, dp[i][s] + dp2[i][s] * (p[i] * L[i][sz] / t + (1 - p[i]) * L[i][sz] / r));
        }   
    }
    cout << fixed << setprecision(7) << dp[0][0] << '\n';
}

signed main(){
    io
    int t = 1; //cin >> t;
    while(t--) solve();
}