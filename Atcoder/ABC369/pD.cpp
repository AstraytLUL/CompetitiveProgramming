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

int dp[maxn][2];

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int mx0 = 0, mx1 = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(i == 0) dp[i][1] = a[i], mx1 = a[i];
        else{
            dp[i][1] = mx0 + a[i];
            dp[i][0] = mx1 + a[i] * 2;
            mx0 = max(dp[i][0], mx0);
            mx1 = max(dp[i][1], mx1);
        }
    }
    cout << max(mx0, mx1) << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
