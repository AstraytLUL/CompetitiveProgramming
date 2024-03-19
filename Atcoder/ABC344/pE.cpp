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
    map<int, int> L, R;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        if(i == 0) L[a[i]] = -1;
        else L[a[i]] = a[i - 1];
        if(i == n - 1) R[a[i]] = -1;
        else R[a[i]] = a[i + 1];
    }
    int q; cin >> q;
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int x, y; cin >> x >> y;
            int t = R[x];
            R[x] = y;
            L[y] = x;
            R[y] = t;
            if(t != -1) L[t] = y;
        }else{
            int x; cin >> x;
            int l = L[x], r = R[x];
            if(l != -1) R[l] = r;
            if(r != -1) L[r] = l;
            L.erase(x);
            R.erase(x);
        }
    }
    int ans = -1;
    for(auto [x, y]:L){
        if(y == -1) ans = x;
    }
    while(ans != -1){
        cout << ans << ' ';
        ans = R[ans];
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
