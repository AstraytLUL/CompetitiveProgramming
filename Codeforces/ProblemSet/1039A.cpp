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
    int n, t; cin >> n >> t;
    vector<int> a(n), x(n), b(n);
    for(auto &v:a) cin >> v;
    for(auto &v:x) cin >> v;
    a.pb(a[n - 1] + n + 1);
    bool ok = 1;
    for(int i = 0; i < n; ++i) ok &= (x[i] >= i + 1), b[i] = a[x[i]] + t - 1;
    for(int i = n - 2; i >= 0; --i) b[i] = (b[i] >= b[i + 1] ? b[i + 1] - 1 : b[i]);
    for(int i = 0; i < n - 1; ++i){
        if(x[i + 1] == x[i]){
            ok &= (b[i] >= a[i + 1] + t);
        }else{
            ok &= (b[i] < a[i + 1] + t);
        }
        ok &= (b[i] >= a[i] + t);
    }
    if(ok){
        cout << "Yes\n";
        for(auto v:b) cout << v << ' ';
        cout << '\n';
    }else{
        cout << "No\n";
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
