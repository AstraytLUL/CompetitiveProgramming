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
#define maxn 100005
#define mod 1000000007
#define ls (2*i)
#define rs (2*i+1)

struct SegmentTree{
    int val[4*maxn];
    void init(int sz){
        fill(val, val+4*sz+10, 1e18);
    }
    void modify(int i, int l, int r, int p, int x){
        if(l == r){
            val[i] = x;
            return;
        }
        int mid = (l + r) / 2;
        if(p <= mid) modify(ls, l, mid, p, x);
        else modify(rs, mid + 1, r, p, x);
        val[i] = min(val[ls], val[rs]);
    }
    int query(int i, int l, int r, int ql, int qr){
        if(ql <= l && r <= qr){
            return val[i];
        }
        int mid = (l + r) / 2, ret = 1e18;
        if(ql <= mid) ret = min(ret, query(ls, l, mid, ql, qr)) ;
        if(mid < qr) ret = min(ret, query(rs, mid + 1, r, ql, qr));
        return ret;
    }
}sgt;

bool check(int n, vector<int> a, int p){
    sgt.init(n);
    vector<int> dp0(n + 1, 1e18), dp1(n + 1, 1e18);
    dp0[0] = dp1[0] = 0;
    for(int i = 1, j = 1, j2 = 1, sum = 0, sum2 = 0; i <= n; ++i){
        sum += a[i];
        while(sum > p) sum -= a[j], j++;
        while(sum2 > p) sum2 -= a[j2], j2++;
        if(j == 1){
            dp0[i] = 0;
        }else{
            dp0[i] = sgt.query(1, 1, n, j - 1, i - 1);
        }
        if(j2 == 1){
            dp1[i] = a[i];
        }else{
            dp1[i] = a[i] + sgt.query(1, 1, n, j2 - 1, i - 1);
        }
        sgt.modify(1, 1, n, i, dp1[i]);
        sum2 += a[i];
    }
    return (min(dp0[n], dp1[n]) <= p);
}

void solve(){
    int n; cin >> n;
    int l = 0, r = 0;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; ++i) cin >> a[i], r += a[i], l = max(l, a[i]);
    while(l != r){
        int mid = (l + r) / 2;
        bool ok = check(n, a, mid);
        if(ok){
            r = mid;
        }else l = mid + 1;
    }
    cout << l << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
