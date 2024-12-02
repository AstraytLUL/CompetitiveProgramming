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
    int n, m; cin >> n >> m;
    vector<bitset<2000>> v[n];
    for(int i = 0; i < n; ++i) v[i].assign(10, bitset<2000>());
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int x; cin >> x;
            for(int k = 0; k < 10; ++k){
                v[i][k] |= (x & 1);
                x >>= 1;
                if(j != m - 1) v[i][k] <<= 1;
            }
        }
    }
    bitset<2000> T;
    for(int i = 0; i < 2000; ++i) T[i] = 1;
    int C = 2000 - m, ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            bitset<2000> cur = T, n1 = T;
            for(int k = 0; k < 10; ++k){
                cur &= (v[i][k] ^ v[j][k] ^ n1);
            }
            int cnt = cur.count() - C;
            if(cnt % 2 == 1) ans++;
        }
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
