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

int a[maxn], b[maxn];
__int128_t ha[maxn], hb[maxn];
bool isprime[2750162];
vector<int> prime;
__int128_t mod = 10000000000000079;

void init(){
    fill(isprime, isprime + 2750162, 1);
    isprime[0] = isprime[1] = 0;
    for(int i = 2; i < 2750162; ++i){
        if(isprime[i]){
            prime.pb(i);
        }
        for(int p:prime){
            if(i * p >= 2750162) break;
            isprime[i * p] = 0;
            if(i % p == 0) break;
        }
    }
}
int t = 1e18;

__int128_t fastpow(__int128_t a, __int128_t b){
    __int128_t ret = 1;
    for(; b; b >>= 1){
        if(b & 1) ret = ret * a % mod;
        a = a * a % mod;
    }
    return ret;
}

void solve(){
    init();
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    ha[0] = hb[0] = 1;
    for(int i = 1; i <= n; ++i){
        ha[i] = ha[i - 1] * prime[a[i]] % mod;
        hb[i] = hb[i - 1] * prime[b[i]] % mod;
    }
    for(; q; q--){
        int l, r, L, R; cin >> l >> r >> L >> R;
        if(R - L != r - l){
            cout << "No\n";
            continue;
        }
        __int128_t x = ha[r], y = hb[R];
        x *= fastpow(ha[l - 1], mod - 2);
        y *= fastpow(hb[L - 1], mod - 2);
        auto tx = fastpow(ha[l - 1], mod - 2);
        auto ty = fastpow(hb[L - 1], mod - 2);
        x %= mod;
        y %= mod;
        cout << (x == y ? "Yes" : "No") << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
