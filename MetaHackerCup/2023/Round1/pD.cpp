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

struct SegmentTree{
    int n;
    vector<int> data;
    vector<int> tag;
    vector<pii> val1, val2;
    void init(int _n){
        n = _n;
        data.assign(n + 1, 0);
        tag.assign(n << 2, 0);
        val1.assign(n << 2, pii(0, 0));
        val2.assign(n << 2, pii(0, 0));
    }
    void build(int l, int r, int i){
        if(l == r){
            val1[i] = val2[i] = pii(data[l], l);
            return;
        }
        int mid = (l + r) / 2, ls = 2 * i, rs = ls + 1;
        build(l, mid, ls);
        build(mid + 1, r, rs);
        val1[i] = max(val1[ls], val1[rs]);
        val2[i] = min(val2[ls], val2[rs]);
    }
    void update(int i){
        swap(val1[i], val2[i]);
        val1[i].ff = mod - val1[i].ff;
        val2[i].ff = mod - val2[i].ff;
    }
    void push(int i){
        int ls = 2 * i, rs = 2 * i + 1;
        tag[i] = 0;
        tag[ls] ^= 1;
        tag[rs] ^= 1;
        update(ls); 
        update(rs);
    }
    void modify(int l, int r, int i ,int ql, int qr){
        if(ql <= l && r <= qr){
            tag[i] ^= 1;
            update(i);
            return;
        }
        int mid = (l + r) / 2, ls = 2 * i, rs = ls + 1;
        if(tag[i]) push(i);
        if(ql <= mid) modify(l, mid, ls, ql, qr);
        if(mid < qr) modify(mid + 1, r, rs, ql, qr);
        val1[i] = max(val1[ls], val1[rs]);
        val2[i] = min(val2[ls], val2[rs]);
    }
    int query(){
        return val1[1].ss;
    }
}sgt;

inline void solve(int tc){
    int ans = 0;
    int n; cin >> n; 
    sgt.init(n);
    for(int i = 1; i <= n; ++i) cin >> sgt.data[i];
    sgt.build(1, n, 1);
    int q; cin >> q;
    for(int i = 1; i <= q; ++i){
        int l, r; cin >> l >> r;
        sgt.modify(1, n, 1, l, r);
        ans += sgt.query();
    }
    cout << "Case #" << tc << ": ";
    cout << ans << '\n';
}

signed main(){
    starburst
    freopen("D_input.txt", "r", stdin);
    freopen("D_output.txt", "w", stdout);
    int t = 1; cin >> t;
    for(int i = 1; i <= t; ++i) solve(i);
}
