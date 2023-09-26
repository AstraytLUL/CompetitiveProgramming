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
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> dp(n + 2, vector<int>(3, 0)), tmp(2, {0, 0});
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = n; i >= 1; --i){
        dp[i][2] = max(tmp[0][0], tmp[1][1]);
        dp[i][0] = max(tmp[1][0], tmp[0][1]);
        dp[i][1] = a[i] + max(dp[i][0], dp[i][2]);
        tmp[i % 2][0] = max(tmp[i % 2][0], dp[i][0]);
        tmp[i % 2][1] = max(tmp[i % 2][1], dp[i][1]);
    }
    cout << max(dp[1][1], dp[1][2]) << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
