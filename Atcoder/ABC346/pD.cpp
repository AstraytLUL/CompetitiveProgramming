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
    string s; cin >> s;
    vector<int> c(n), to_010(n, 0), to_101(n, 0);
    for(auto &x:c) cin >> x;
    for(int i = 0; i < n; ++i){
        if(s[i] - '0' == i % 2){
            to_101[i] += c[i];
        }else{
            to_010[i] += c[i];
        }
    }
    int ans = 9e18;
    for(int i = 1; i < n; ++i) to_010[i] += to_010[i - 1], to_101[i] += to_101[i - 1];
    for(int x = 0, y = 1; y < n; ++x, ++y){
        // xy = 00
        int c11 = (s[x] == '1' ? c[x] : 0) + (s[y] == '1' ? c[y] : 0);
        int c00 = (s[x] == '0' ? c[x] : 0) + (s[y] == '0' ? c[y] : 0);
        if(x % 2 == 1){
            // 0101 00 1010
            int lc = (x == 0 ? 0 : to_010[x - 1]);
            int rc = to_101[n - 1] - to_101[y];
            ans = min(ans, c00 + lc + rc);
            lc = (x == 0 ? 0 : to_101[x - 1]);
            rc = to_010[n - 1] - to_010[y];
            ans = min(ans, c11 + lc + rc);
        }else{
            // 01010 11 0101
            int lc = (x == 0 ? 0 : to_010[x - 1]);
            int rc = to_101[n - 1] - to_101[y];
            ans = min(ans, c11 + lc + rc);
            lc = (x == 0 ? 0 : to_101[x - 1]);
            rc = to_010[n - 1] - to_010[y];
            ans = min(ans, c00 + lc + rc);
        }
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
