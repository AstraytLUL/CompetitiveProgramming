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

int val[205][205], dp[205][205];
pair<int, pii> dp1[205][205];

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> val[i][j];
            dp1[i][j].ff = val[i][j];
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i != 1){
                if(dp1[i][j].ff < dp1[i - 1][j].ff + val[i][j]) dp1[i][j] = mp(dp1[i - 1][j].ff + val[i][j], mp(i - 1, j));
            }
            if(j != 1){
                if(dp1[i][j].ff < dp1[i][j - 1].ff + val[i][j]) dp1[i][j] = mp(dp1[i][j - 1].ff + val[i][j], mp(i, j - 1));
            }
        }
    }
    val[1][1] = 0;
    pii cur(n, n);
    while(cur != pii(1, 1)){
        val[cur.ff][cur.ss] = 0;
        cur = dp1[cur.ff][cur.ss].ss;
    }
    for(int i = n; i >= 1; i--){
        for(int j = n; j >= 1; j--){
            dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]) + val[i][j];
        }
    }
    cout << dp[1][1] + dp1[n][n].ff << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
