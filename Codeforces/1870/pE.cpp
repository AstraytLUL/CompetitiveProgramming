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

void solve(){
    int n; cin >> n;
    vector<int> v(n + 1), cur(n + 1, 0);
    vector<vector<int>> dp(n + 1, vector<int> (8192, 0));
    vector<bitset<8192>> done(n + 1);
    for(int i = 1; i <= n; ++i) cin >> v[i], done[i][0] = 1, dp[i][0] = 1;
    done[0][0] = 1;
    dp[0][0] = 1;
    int ans = 0;
    vector<int> tmp(8192, 0), cnt(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        cnt.assign(n + 1, 0);
        int mex = 0;
        for(int j = i; j > 0; --j){
            cnt[v[j]] = 1;
            while(cnt[mex]){mex++;}
            tmp[mex] = 1;
            if(mex > cur[j - 1]){
                cur[j - 1] = mex;
                if(done[j - 1][mex]) continue;
                for(int k = 0; k < j; ++k) done[k][mex] = 1;
                for(int t = 0; t < 8192; ++t){
                    tmp[t] |= dp[j - 1][t ^ mex];
                }
            }
        }
        dp[i] = tmp;
    }
    for(int i = 0; i < 8192; ++i){
        if(dp[n][i]) ans = i;
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
