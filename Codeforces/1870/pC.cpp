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

struct BIT{
    int n;
    vector<int> v;
    void init(int _n, int op){
        n = _n;
        if(op == 1) v.assign(n + 1, 1e9);
        else v.assign(n + 1, -1);
    }
    void modify(int p, int x, int op){
        if(op == 1) for(; p > 0; p -= (p & -p)) v[p] = min(v[p], x);
        else for(; p > 0; p -= (p & -p)) v[p] = max(v[p], x);
    }
    int query(int p, int op){
        int ret;
        if(op == 1){
            ret = 1e9;
            for(; p <= n; p += (p & -p)) ret = min(v[p], ret);
        }else{
            ret = -1;
            for(; p <= n; p += (p & -p)) ret = max(v[p], ret);
        }
        return ret;
    }
}bit;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    vector<int> l(k + 1, 0), r(k + 1, -1);
    bit.init(k + 1, 1);
    for(int i = 0; i < n; ++i){
        bit.modify(a[i], i, 1);
        int q = bit.query(a[i], 1);
        l[a[i]] = (q == 1e9 ? i : q);
    }
    bit.init(k + 1, 2);
    for(int i = n - 1; i >= 0; --i){
        bit.modify(a[i], i, 2);
        int q = bit.query(a[i], 2);
        r[a[i]] = (q == -1 ? i : q);
    }
    for(int i = 1; i <= k; ++i) cout << 2 * (r[i] - l[i] + 1) << ' ';
    cout << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
