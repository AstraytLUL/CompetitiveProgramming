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
    int h, w, m; cin >> h >> w >> m;
    int rem = h * w;
    vector<int> t(m), a(m), x(m);
    vector<int> r(h + 1), c(w + 1, 0);
    for(int i = 0; i < m; ++i){
        cin >> t[i] >> a[i] >> x[i];
    }
    int rc = 0, cc = 0;
    map<int, int> ans;
    for(int i = m - 1; i >= 0; --i){
        if(t[i] == 1){
            if(r[a[i]] || w - cc == 0) continue;
            rc++;
            rem -= (w - cc);
            ans[x[i]] += w - cc;
            r[a[i]] = 1;
        }else{
            if(c[a[i]] || h - rc == 0) continue;
            cc++;
            rem -= (h - rc);
            ans[x[i]] += h - rc;
            c[a[i]] = 1;
        }
    }
    if(rem != 0) ans[0] += rem;
    cout << ans.size() << '\n';
    for(auto [col, cnt]:ans){
        cout << col << ' ' << cnt << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
