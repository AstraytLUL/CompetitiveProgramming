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

vector<int> v;

int mysqrt(int a){
    int l = 1, r = 1e9;
    while(l != r){
        int mid = 1 + (l + r) / 2;
        if(mid * mid <= a) l = mid;
        else r = mid - 1;
    }
    return l;
}

int fastpow(int a, int b){
    int ret = 1;
    for(; b; b >>= 1){
        if(b & 1) ret *= a;
        a *= a;
    }
    return ret;
}

void solve(){
    int l, r; cin >> l >> r;
    int cl = mysqrt(l), cr = floor(mysqrt(r));
    if(cl * cl == l) cl--;
    int ans = cr - cl;
    ans += ((upper_bound(v.begin(), v.end(), r) - 1) - lower_bound(v.begin(), v.end(), l)) + 1;
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    for(int j = 3; j <= 60; ++j){
        for(int i = 2; i <= floor(pow(1e18, 1.0 / j)); ++i){
            int t = fastpow(i, j), sqt = mysqrt(t);
            if(sqt * sqt == t) continue;
            v.pb(t);
        }
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    while(t--) solve();
}
