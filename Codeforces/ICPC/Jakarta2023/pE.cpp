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

int dp[2005][2005], from[2005][2005];

void solve(){
    int k; cin >> k;
    int n = k * 2;
    vector<int> v(n + 5, 0), pos(n + 5, 0), len(n + 5, 0), taken(n + 5, 0);
    for(int i = 1; i <= n; ++i) cin >> v[i], pos[v[i]] = i;
    for(int i = n; i >= 1; --i){
        if(taken[pos[i]]) continue;
        int j = pos[i];
        while(j <= n && !taken[j]){
            len[i]++;
            taken[j] = 1;
            j++;
        }
    }
    dp[0][0] = 1;
    from[0][0] = 0;
    for(int i = 1; i <= n; ++i){
        int w = len[n - i + 1];
        for(int j = n; j >= 0; j--){
            if(j - w >= 0 && dp[i - 1][j - w]){
                dp[i][j] = 1;
                from[i][j] = n - i + 1;
            }
            if(dp[i - 1][j]){
                dp[i][j] = 1;
                from[i][j] = 0;
            }
        }
    }
    if(dp[n][k] == 0){
        cout << "-1\n";
        return;
    }
    vector<int> a, b;
    for(int i = n, cur = k; i >= 1; --i){
        if(from[i][cur] == 0) continue;
        int x = from[i][cur];
        b.pb(x);
        cur -= len[x];
    }
    for(int i = 1, j = 0; i <= n; ++i){
        if(len[i] == 0) continue;
        while(j <(int) b.size() && b[j] < i) j++;
        if(j <(int) b.size() && b[j] == i) continue;
        a.pb(i);
    }
    // for(auto &x:a) cout << x << ' ';
    // cout << '\n';
    // for(auto &x:b) cout << x << ' ';
    // cout << '\n';
    vector<int> A, B;
    for(int i = 0; i <(int) a.size(); ++i){
        for(int j = 0; j < len[a[i]]; ++j){
            A.pb(v[pos[a[i]] + j]);
        }
    }
    for(int i = 0; i <(int) b.size(); ++i){
        for(int j = 0; j < len[b[i]]; ++j){
            B.pb(v[pos[b[i]] + j]);
        }
    }
    for(int i = 0; i < k; ++i){
        cout << A[i] << " \n"[i == k - 1];
    }
    for(int i = 0; i < k; ++i){
        cout << B[i] << " \n"[i == k - 1];
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
