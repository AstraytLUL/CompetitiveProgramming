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

void solve(){
    int n, x; cin >> n >> x;
    vector<int> p(n);
    for(auto &x:p) cin >> x;
    vector<double> dp(n + 1);
    dp[0] = 1;
    for(int i = 0; i < n; ++i){
        double P = 1.0 * p[i] / 100.00, nP = 1.0 - P;
        for(int j = n; j >= 1; --j){
            dp[j] = dp[j - 1] * P + dp[j] * nP;
        }
        dp[0] = dp[0] * nP;
    }
    vector<double> E(x + 1);
    E[0] = 0;
    for(int i = 1; i <= x; ++i){
        for(int j = i + 1; j <= n; ++j){
            E[i] += dp[j];
        }

        for(int j = 1; j <= min(i, n); ++j){
            E[i] += (E[i - j] + 1) * dp[j];
        }
        E[i] += dp[0];
        double P = 1 - dp[0];
        E[i] *= 1.0 / P;
        //cout << i << ' ' << fixed << setprecision(6) << E[i] << '\n';
    }
    cout << fixed << setprecision(6) << E[x] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
