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
#define maxn 500005
#define mod 998244353

int L[maxn], R[maxn], val[maxn];
vector<int> a;

void dfs(int v){
    if(L[v] != -1) dfs(L[v]);
    a.pb(val[v]);
    if(R[v] != -1) dfs(R[v]);
}

int fastpow(int n, int m){
    int ret = 1;
    for(; m; m >>= 1){
        if(m & 1) ret = ret * n % mod;
        n = n * n % mod;
    }
    return ret;
}

int nCr(int n, int r){
    int ret = n;
    for(int i = 2; i <= r; ++i){
        ret *= (n - i + 1);
        ret %= mod;
        ret *= fastpow(i, mod - 2);
        ret %= mod;
    }
    return ret;
}

void solve(){
    int n, C; cin >> n >> C;
    a.clear();
    a.pb(1);
    for(int i = 1; i <= n; ++i){
        cin >> L[i] >> R[i] >> val[i];
    }
    dfs(1);
    a.pb(C);
    int ans = 1;
    for(int i = 1; i <= n; ++i) {
        int l = i, r = i;
        if(a[l] != -1) continue;
        while(a[r] == -1) r++;
        int lb = a[l - 1], rb = a[r];
        int x = rb - lb + 1, y = r - l;
        ans = ans * nCr(x + y - 1, y) % mod;
        i = r;
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
