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

vector<vector<int>> I, adj;

vector<vector<int>> MUL(vector<vector<int>> A, vector<vector<int>> B){
    int n = A.size();
    vector<vector<int>> ret(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k){
                ret[i][j] = (ret[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return ret;
}

vector<vector<int>> fastpow(vector<vector<int>> A, int b){
    vector<vector<int>> ret = I;
    for(; b; b >>= 1){
        if(b & 1) ret = MUL(A, ret);
        A = MUL(A, A);
    }
    return ret;
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    I.assign(n, vector<int>(n, 0));
    adj.assign(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i){
        I[i][i] = 1;
    }
    for(int i = 1; i <= m; ++i){
        int u, v; cin >> u >> v;
        adj[u - 1][v - 1]++;
    }
    vector<vector<int>> ans = fastpow(adj, k);
    cout << ans[0][n - 1] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
