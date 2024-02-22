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
    int n, k; cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int> (2, 1e18));
    dp[0][0] = 0;
    dp[0][1] = 0;
    deque<pii> dq, dq2;
    for(int i = 1; i <= n; ++i){
        char c; cin >> c;
        while(dq.size() && dq.front().ss < i - k) dq.pop_front();
        while(dq2.size() && dq2.front().ss < i - 2 * k - 1) dq2.pop_front();
        if(c == '0'){
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + i;
            if(!dq.empty()) dp[i][0] = dq.front().ff, dp[i][1] = min(dp[i][1], dq.front().ff + i);
        }else{
            dp[i][1] = dp[max(0ll, i - k - 1)][1] + i;
            if(!dq.empty()){
                dp[i][0] = dq.front().ff;
            }
            if(!dq2.empty()){
                dp[i][1] = min(dp[i][1], dq2.front().ff + i);
            }
            while(dq.size() && dq.back().ff >= dp[i][1]) dq.pop_back();
            while(dq2.size() && dq2.back().ff >= dp[i][1]) dq2.pop_back();
            dq.pb(mp(dp[i][1], i));
            dq2.pb(mp(dp[i][1], i));
        }
    }
    cout << min(dp[n][0], dp[n][1]) << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
