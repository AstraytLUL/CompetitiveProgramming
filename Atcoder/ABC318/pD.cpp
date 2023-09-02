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

int adj[20][20];
int dp[1<<20];

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            cin >> adj[i][j];
            adj[j][i] = adj[i][j];
        }
    }
    for(int s = 0; s < (1<<n); ++s){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == j || (s & (1<<i)) == 0 || (s & (1<<j)) == 0) continue;
                dp[s] = max(dp[s ^ (1<<i) ^ (1<<j)] + adj[i][j], dp[s]);
            }
        }
    }
    cout << dp[(1<<n) - 1] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
