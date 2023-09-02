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
    vector<int> X(n + 1), L(n + 1);
    vector<double> p;
    p.pb(-1e18), p.pb(1e18);
    for(int i = 1; i <= n; ++i) cin >> X[i];
    for(int i = 1; i <= n; ++i) cin >> L[i];
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            p.pb((X[i] + X[j]) / 2);
        }
    }
    
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    for(int i = 0; i < p.size() - 1; ++i){
        int l = ceil(p[i]), r = floor(p[i + 1]);
        if(l == p[i]) l++;
        if(r == p[i + 1]) r--;
        if(l > r) continue;
        vector<pii> dist;
        for(int i = 1; i <= n; ++i){
            dist.pb(pii(abs(l - X[i]), i));
        }
        sort(dist.begin(), dist.end());
        for(int i = 0; i < n; ++i){
            if(X[dist[i].ss] <= l){
                r = min(r, X[dist[i].ss] + L[i + 1]);
            }
            else if(X[dist[i].ss] >= r){
                l = max(l, X[dist[i].ss] - L[i + 1]);
            }
        }
        ans += max(0ll, r - l + 1);
    }
    for(int i = 0; i < p.size(); i++){
        int t = floor(p[i]), ok = 1;
        if(t != p[i]) continue;
        vector<pii> dist;
        for(int i = 1; i <= n; ++i){
            dist.pb(pii(abs(t - X[i]), i));
        }
        sort(dist.begin(), dist.end());
        for(int i = 0; i < n; ++i){
            if(X[dist[i].ss] < t){
                if(X[dist[i].ss] < t - L[i + 1]) ok = 0;
            }
            else if(X[dist[i].ss] > t){
                if(X[dist[i].ss] > t + L[i + 1]) ok = 0;
            }
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
