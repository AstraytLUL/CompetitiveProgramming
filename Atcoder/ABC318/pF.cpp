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
    int n, ans = 0; cin >> n;
    vector<int> X(n), L(n);
    vector<int> p;
    p.pb(-1000000000000000000), p.pb(1000000000000000001);
    for(int i = 0; i < n; ++i) cin >> X[i];
    for(int i = 0; i < n; ++i) cin >> L[i];
    set<int> sp;
    for(int i = 0; i < n; ++i){
        p.pb(X[i]);
        for(int j = i + 1; j < n; ++j){
            int tmp = X[i] + X[j];
            if(tmp % 2){
                p.pb(tmp / 2);
                p.pb(tmp / 2 + 1);
            }else{
                sp.insert(tmp / 2);
                p.pb(tmp / 2);
                p.pb(tmp / 2 + 1);
            }
        }
    }
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    for(int i = 0; i < (int)p.size() - 1; ++i){
        int l = p[i], r = p[i + 1] - 1;
        if(sp.find(l) != sp.end()) continue;
        int t = (l + r) / 2;
        vector<pii> dist;
        for(int j = 0; j < n; ++j){
            dist.pb(pii(abs(t - X[j]), j));
        }
        sort(dist.begin(), dist.end());
        for(int j = 0; j < n; ++j){
            if(X[dist[j].ss] <= l){
                r = min(r, X[dist[j].ss] + L[j]);
            }
            else if(X[dist[j].ss] >= r){
                l = max(l, X[dist[j].ss] - L[j]);
            }
        }
        ans += max(0ll, r - l + 1);
    }
    for(int t:sp){
        vector<pii> dist;
        int ok = 1;
        for(int j = 0; j < n; ++j){
            dist.pb(pii(abs(t - X[j]), j));
        }
        sort(dist.begin(), dist.end());
        for(int j = 0; j < n; ++j){
            if(X[dist[j].ss] < t && t - L[j] > X[dist[j].ss]) ok = 0;
            if(X[dist[j].ss] > t && t + L[j] < X[dist[j].ss]) ok = 0;
        }
        ans += ok;
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
