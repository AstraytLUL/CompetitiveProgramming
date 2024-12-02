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

int dsu[maxn * 2];

int find(int u){
    return u == dsu[u] ? u : (dsu[u] = find(dsu[u]));
}

int join(int u, int v){
    int uu = find(u), vv = find(v);
    if(uu == vv) return 0;
    if(uu < vv) swap(uu, vv);
    dsu[uu] = vv;
    return 1;
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n + m; ++i) dsu[i] = i;
    vector<pii> C(m);
    vector<vector<int>> A(m);
    for(int i = 0; i < m; ++i){
        int k; cin >> k;
        cin >> C[i].ff;
        C[i].ss = i;
        A[i].assign(k, 0);
        for(auto &x:A[i]) cin >> x;
    }
    int ans = 0;
    sort(C.begin(), C.end());
    for(int i = 0; i < m; ++i){
        int id = C[i].ss, cnt = 0;
        for(int j = 0; j < A[id].size(); ++j){
            cnt += join(A[id][j], n + id + 1);
        }
        if(cnt != 0) ans += (cnt - 1) * C[i].ff;
    }
    for(int i = 1; i <= n; ++i){
       if(find(1) != find(i)) ans = -1;
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
