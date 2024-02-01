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

int fac[maxn], inv[maxn];

int fastpow(int a, int b){
    a %= mod;
    int ret = 1;
    for(; b; b>>=1){
        if(b & 1) ret = ret * a % mod;
        a = a * a % mod;
    }
    return ret;
}

int C(int n, int m){
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    int sum = 0;
    for(int i = 1; i <= m; ++i){
        int u, v, w; cin >> u >> v >> w;
        sum += w;
    }
    sum %= mod;
    int t = fastpow((n * (n - 1) / 2) % mod, mod - 2);
    int p1 = t, p2 = (n * (n - 1) / 2 - 1) % mod * t % mod;
    int ans = sum * t % mod * k % mod;
    for(int i = 1; i <= k; ++i){
        int add = i * (i - 1) / 2;
        add %= mod;
        int prob = C(k, i) * fastpow(p1, i) % mod * fastpow(p2, k - i) % mod;
        ans += (add * prob) % mod * m % mod;
        ans %= mod;
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    fac[0] = inv[0] = 1;
    for(int i = 1; i < maxn; ++i){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = fastpow(fac[i], mod - 2);
    }
    while(t--) solve();
}
