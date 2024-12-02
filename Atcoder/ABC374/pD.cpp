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
#define double long double

double dist(pii a, pii b){
    int dx = abs(a.ff - b.ff), dy = abs(a.ss - b.ss);
    double d = dx * dx + dy * dy;
    d = sqrt(d);
    return d;
}

void solve(){
    int n, s, t; cin >> n >> s >> t;
    pii A[n], B[n]; 
    vector<int> v;
    double ans = 1e18;
    for(int i = 0; i < n; ++i){
        cin >> A[i].ff >> A[i].ss;
        cin >> B[i].ff >> B[i].ss;
        v.pb(i);
    }
    // 1 - A -> B
    do{
        for(int S = 0; S < (1<<n); S++){
            double time = 0;
            if(S & (1<<v[0])) time += dist(pii(0, 0), A[v[0]]) / s;
            else time += dist(pii(0, 0), B[v[0]]) / s;
            time += dist(A[v[0]], B[v[0]]) / t;
            for(int idx = 1; idx < n; ++idx){
                int i = v[idx], j = v[idx - 1];
                pii from = ((S & (1<<j)) ? B[j] : A[j]);
                pii to = ((S & (1<<i)) ? A[i] : B[i]);
                time += dist(from, to) / s;
                time += dist(A[i], B[i]) / t;
            }
            ans = min(ans, time);
        } 
    }while(next_permutation(v.begin(), v.end()));
    cout << fixed << setprecision(9) << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
