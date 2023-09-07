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
#include <unordered_map>
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

int x;
unordered_map<int, bool> vis;
unordered_map<int, double> dp[128];
void DnC(int n){
    if(vis[n]) {
        return;
    }
    cerr << n << '\n';
    int l = n / 2 + n % 2, r = n - l;
    vis[n] = 1;
    DnC(l);
    DnC(r);
    for(int i = 0; i <= 127; ++i){
        for(int j = 0; j <= 127; ++j){
            dp[i ^ j][n] += dp[i][l] * dp[j][r];
        }
    }
    return;
}

void solve(){
    int n; cin >> n >> x;
    vector<double> p(x + 1);
    for(auto &a:p) cin >> a;
    for(int i = 0; i <= x; ++i){
        dp[i][1] += p[i];
    }
    for(int i = 0; i <= x; ++i){
        for(int j = 0; j <= x; ++j){
            dp[i ^ j][2] += p[i] * p[j];
        }
    }
    for(int i = 0; i <= x; ++i){
        for(int j = 0; j <= x; ++j){
            for(int k = 0; k <= x; ++k){
                dp[i ^ j ^ k][3] += p[i] * p[j] * p[k];
            }
        }
    }
    vis[1] = 1;
    vis[2] = 1;
    vis[3] = 1;
    DnC(n);
    cout << fixed << setprecision(6) << 1 - dp[0][n] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
