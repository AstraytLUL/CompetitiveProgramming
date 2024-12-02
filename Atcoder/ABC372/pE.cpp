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

int dsu[maxn];
set<int, greater<int>> st[maxn];

int ask(int u){
    return (u == dsu[u] ? u : dsu[u] = ask(dsu[u]));
}

void join(int u, int v){
    u = ask(u), v = ask(v);
    if(u == v) return;
    dsu[v] = u;
    if(st[v].size() > st[u].size()) swap(st[u], st[v]);
    for(auto x:st[v]) st[u].insert(x);
    st[v].clear();
}

void solve(){
    int n, q; cin >> n >> q; 
    for(int i = 1; i <= n; ++i) dsu[i] = i, st[i].insert(i);
    for(; q; q--){
        int op; cin >> op;
        if(op == 1){
            int u, v; cin >> u >> v;
            join(u, v);
        }else{
            int u, k; cin >> u >> k;
            u = ask(u);
            if(st[u].size() < k){
                cout << "-1\n";
                continue;
            }
            for(auto x:st[u]){
                k--;
                if(k == 0) {
                    cout << x << '\n';
                    break;
                }
            }
        }
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
