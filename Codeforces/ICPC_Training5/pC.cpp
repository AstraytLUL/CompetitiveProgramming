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
//#define int ll
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define maxn 200005
#define mod 1000000007

int val[305][305], dp[605][305][305];

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> val[i][j];
        }
    }
    for(auto &a:dp){
        for(auto &b:a){
            for(auto &c:b){
                c = -598000;
            }
        }
    }
    dp[2][1][1] = val[1][1];
    for(int s = 3; s <= 2 * n; ++s){
        for(int i = min(1, s - n); i <= min(s - 1, n); ++i){
            for(int j = min(1, s - n); j <= min(s - 1, n); ++j){
                int xi = i, yi = s - i;
                int xj = j, yj = s - j;
                int point = 0;
                if(xi == xj && yi == yj) point = val[xi][yi];
                else point = val[xi][yi] + val[xj][yj];
                dp[s][i][j] = max({dp[s - 1][i][j], dp[s - 1][i - 1][j], dp[s - 1][i][j - 1], dp[s - 1][i - 1][j - 1]}) + point;
            }
        }
    }
    cout << dp[2 * n][n][n] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
