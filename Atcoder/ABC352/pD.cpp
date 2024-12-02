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
    int n, k; cin >> n >> k;
    vector<pii> p(n);
    int ans = n;
    for(int i = 0; i < n; ++i){
        cin >> p[i].ff;
        p[i].ss = i;
    }
    sort(p.begin(), p.end());
    deque<pii> mn, mx;
    for(int i = 0; i < n; ++i){
        if(mn.front().ss <= i - k) mn.pop_front();
        if(mx.front().ss <= i - k) mx.pop_front();
        while(mn.size() && p[i].ss < mn.back().ff) mn.pop_back();
        while(mx.size() && p[i].ss > mx.back().ff) mx.pop_back();
        mx.pb(mp(p[i].ss, i));
        mn.pb(mp(p[i].ss, i));
        if(i - k + 1 >= 0){
            //cerr << i + 1 << ' ' << mx.front().ff  << ' ' << mn.front().ff << '\n';
            ans = min(ans, mx.front().ff - mn.front().ff);
        }
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
