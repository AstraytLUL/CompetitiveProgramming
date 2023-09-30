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

double dp[105][605];

void solve(){
    int n, a, b; cin >> n >> a >> b;
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 605; ++j){
            for(int k = 1; j + k <= min(j + 6, 604ll); ++k){
                dp[i][j + k] += 1.0 / 6.0 * dp[i - 1][j];
            }
        }
    }
    double ans = 0;
    for(int i = a; i <= b; ++i){
        ans += dp[n][i];
    }
    cout << fixed << setprecision(6) << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
