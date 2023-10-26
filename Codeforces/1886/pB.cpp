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

int dist(pii a, pii b){
    int dx = a.ff - b.ff, dy = a.ss - b.ss;
    return (dx * dx) + (dy * dy);
}

void solve(){
    vector<pii> p(3);
    for(auto &[x, y]:p) cin >> x >> y;
    p.pb(pii(0, 0));
    int d1 = min(dist(p[1], p[3]), dist(p[2], p[3])), d2 = min(dist(p[0], p[1]), dist(p[0], p[2])), d3 = dist(p[1], p[2]);
    double ans;
    if(dist(p[0],p[1]) < dist(p[0], p[2]) && dist(p[1], p[3]) < dist(p[2], p[3])){
        ans = sqrt(max({d1, d2}));
    }else if(dist(p[0],p[1]) > dist(p[0], p[2]) && dist(p[1], p[3]) > dist(p[2], p[3])){
        ans = sqrt(max({d1, d2}));
    }else{
        ans = sqrt(max({d1, d2}));
        ans = max(ans, sqrt(d3) / 2);
        //cerr << "!\n";
    }
    //cerr << d1 << ' ' << d2 << ' ' << d3 << '\n';
    cout << fixed << setprecision(6) << ans << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
