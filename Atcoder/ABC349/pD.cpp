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
    int L, R; cin >> L >> R;
    vector<pii> ans;
    while(L + (L & -L) <= R && L != 0){
        int lb = (L & -L);
        ans.pb(mp(L, L + lb));
        L += lb;
    }
    while(L < R){
        int t = L ^ R;
        int top = 0;
        for(int i = 0; i <= 62; ++i){
            if(t & (1ll<<i)) top = i;
        }
        ans.pb(mp(L, L + (1ll<<top)));
        L += (1ll<<top);
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for(auto [l, r]:ans) cout << l << ' ' << r << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
