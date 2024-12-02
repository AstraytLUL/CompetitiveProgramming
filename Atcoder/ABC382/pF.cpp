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

struct SegTree{
    int H;
    vector<int> val;
    vector<int> tag;
    void init(int n, int h){
        val.assign(4*n, h);
        tag.assign(4*n, -1);
        H = h;
    }
    void push(int i){
        int ls = i * 2, rs = ls + 1;
        int t = tag[i];
        if(t == -1) return;
        val[ls] = t;
        val[rs] = t;
        tag[ls] = t;
        tag[rs] = t;
        tag[i] = -1;
        val[i] = min(val[ls], val[rs]);
    }
    void modify(int i, int l, int r, int ql, int qr, int x){
        if(l == r){
            val[i] = x;
            return;
        }
        push(i);
        if(ql <= l && r <= qr){
            tag[i] = x;
            val[i] = x;
            return;
        }
        int mid = (l + r) / 2, ls = i*2, rs = ls + 1;
        if(ql <= mid) modify(ls, l, mid, ql, qr, x);
        if(qr > mid) modify(rs, mid + 1, r, ql, qr, x);
        val[i] = min(val[ls], val[rs]);
    }
    int query(int i, int l, int r, int ql, int qr){
        if(ql <= l && r <= qr) return val[i];
        push(i);
        int mid = (l + r) / 2, ls = i*2, rs = ls + 1;
        int ret = H;
        if(ql <= mid) ret = min(ret, query(ls, l, mid, ql, qr));
        if(qr > mid) ret = min(ret, query(rs, mid + 1, r, ql, qr));
        return ret;
    }
}seg;

struct Query{
    int r, c, l, i, ans = 0;
};

void solve(){
    int h, w, n; cin >> h >> w >> n;
    seg.init(w, h);
    vector<Query> Q(n);
    for(int i = 0; i < n; ++i){
        auto &[r, c, l, id, ans] = Q[i];
        id = i;
        cin >> r >> c >> l;
    }
    sort(Q.begin(), Q.end(), [&](Query a, Query b){
        return a.r > b.r;
    });
    for(int i = 0; i < n; ++i){
        auto &[r, c, l, id, ans] = Q[i];
        ans = seg.query(1, 1, w, c, c + l - 1);
        seg.modify(1, 1, w, c, c + l - 1, ans - 1);
    }
    
    sort(Q.begin(), Q.end(), [&](Query a, Query b){
        return a.i < b.i;
    });
    for(int i = 0; i < n; ++i){
        auto &[r, c, l, id, ans] = Q[i];
        cout << ans << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
