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

int a[maxn], nxt[maxn][64];

void solve(){
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> nxt[i][0];
    }
    for(int j = 1; j <= 63; ++j){
        for(int i = 1; i <= n; ++i){
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
        }
    }
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i){
        int t = i;
        for(int j = 63; j >= 0; --j){
            if(k & (1ll<<j)) t = nxt[t][j];
        }
        cout << a[t] << ' ';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
