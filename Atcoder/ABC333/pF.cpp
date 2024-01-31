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
#define maxn 3005
#define mod 998244353

int fastpow(int a, int b){
    int ret = 1;
    for(; b; b>>=1){
        if(b & 1) ret = ret * a % mod;
        a = a * a % mod;
    }
    return ret;
}

int pw2[maxn], inv[maxn];
int dp[maxn][maxn];

void solve(){
    int n; cin >> n;
    pw2[0] = 1;
    inv[0] = 1;
    dp[1][1] = 1;
    for(int i = 1; i <= n; ++i){
        pw2[i] = pw2[i - 1] * 2 % mod;
        inv[i] = fastpow(pw2[i], mod - 2);
    }
    for(int i = 2; i <= n; ++i){
        for(int j = 2, cur = 0; j <= i; j++){
            cur = (cur * inv[1]) % mod + (dp[i - 1][j - 1] * inv[1]) % mod;
            cur %= mod;
            dp[i][j] += cur;
            dp[i][j] %= mod;
        }
        for(int j = i - 1, cur = 0; j >= 1; j--){
            cur = (cur * 2) % mod + (dp[i - 1][j] * inv[i]) % mod;
            cur %= mod;
            dp[i][j] += cur;
            dp[i][j] %= mod;
        }
        for(int j = 1; j <= i; ++j){
            dp[i][j] = dp[i][j] * pw2[i] % mod * fastpow(pw2[i] - 1, mod - 2) % mod;
        }
    }
    for(int i = 1; i <= n; ++i){
        cout << dp[n][i] << ' ';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
