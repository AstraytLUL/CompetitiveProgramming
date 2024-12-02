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

vector<int> coin[maxn];

void solve(){
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < k; ++i){
        int x, y; cin >> x >> y;
        coin[x].pb(y);
    }
    vector<pii> dp;
    pii p = mp(1, 1);
    dp.pb(p);
    map<pii, pii> prev;
    map<pii, int> cnt;
    cnt[p] = 0;
    prev[p] = p;
    for(int i = 1; i <= n; ++i){
        sort(coin[i].begin(), coin[i].end());
        for(int y:coin[i]){
            auto it = lower_bound(dp.begin(), dp.end(), mp(y, i));
            //cout << y << ' ' << i << '\n';
            int id = it - dp.begin();
            //cout << id << '\n';
            if(id == dp.size()) {
                dp.pb(mp(y, i));
            }
            else{
                //cout << (*it).ff << ' ' << (*it).ss << '\n';
                dp[id] = mp(y, i);
                //cout << (*it).ff << ' ' << (*it).ss << '\n';
            }
            //cout << (*it).ff << ' ' << (*it).ss << '\n';
            prev[mp(y, i)] = dp[id - 1];
            //cout << dp[id - 1].ff << ' ' << dp[id - 1].ss << '\n';
            cnt[mp(y, i)] = cnt[dp[id - 1]] + 1;
            //cout << '\n';
        }
    }
    for(auto [P, c]:cnt){
        if(c > cnt[p]) p = P;
    }
    cout << cnt[p] << '\n';
    vector<pii> ans;
    ans.pb(mp(m, n));
    while(p != prev[p]){
        //cout << p.ff << ' ' << p.ss << '\n';
        ans.pb(p);
        p = prev[p];
    }
    ans.pb(p);
    reverse(ans.begin(), ans.end());
    int x = 1, y = 1;
    string op = "";
    for(auto [nx, ny]:ans){
        while(x < nx) op += "R", x++;
        while(y < ny) op += "D", y++;
    }
    cout << op << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
