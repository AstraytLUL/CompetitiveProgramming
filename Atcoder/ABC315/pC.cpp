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
    vector<int> F(n + 1), S(n + 1);
    vector<pii> mx(n + 1);
    pii mxp(0, 0);
    for(int i = 1; i <= n; ++i){
        cin >> F[i] >> S[i];
        if(S[i] > mx[F[i]].ff) swap(S[i], mx[F[i]].ff);
        if(S[i] > mx[F[i]].ss) swap(S[i], mx[F[i]].ss);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans = max(ans, mx[i].ff + mx[i].ss / 2);
        if(mx[i].ff > mxp.ff) swap(mx[i].ff, mxp.ff);
        if(mx[i].ff > mxp.ss) swap(mx[i].ff, mxp.ss);
    }
    cout << max(ans, mxp.ff + mxp.ss) << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
