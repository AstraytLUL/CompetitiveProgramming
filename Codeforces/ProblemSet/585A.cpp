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
    vector<int> v(n), d(n), c(n), gone(n);
    for(int i = 0; i < n; ++i) cin >> v[i] >> d[i] >> c[i];
    vector<int> ans;
    for(int i = 0; i < n; ++i){
        if(gone[i]) continue;
        ans.pb(i + 1);
        for(int j = i + 1, cur = v[i], cur2 = 0; j < n; ++j){
            if(gone[j]) continue;
            c[j] -= cur + cur2;
            cur = max(cur - 1, 0ll);
            if(c[j] < 0) gone[j] = 1, cur2 += d[j];
            if(cur == 0 && cur2 == 0) break;
        }
    }
    cout << ans.size() << '\n';
    for(auto x:ans) cout << x << ' ';
    cout << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
