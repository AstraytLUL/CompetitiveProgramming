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

int ans[maxn];
vector<int> Q[maxn];
vector<pii> mod[maxn];

struct node{
    int pre, suf, sum, mx;
    node(){
        pre = suf = sum = mx = 0;
    }
}sgt[maxn * 4];

node merge_node(node a, node b){
    node ret;
    ret.pre = max({a.pre, a.sum + b.pre, a.sum});
    ret.suf = max({b.suf, b.sum + a.suf, b.sum});
    ret.sum = a.sum + b.sum;
    ret.mx = max({a.mx, b.mx, ret.pre, ret.suf, ret.sum, a.suf + b.pre});
    return ret;
}

void modify(int l, int r, int i, int p, int x){
    if(l == r){
        sgt[i].pre = x;
        sgt[i].sum = x;
        sgt[i].suf = x;
        sgt[i].mx = x;
        return;
    }
    int mid = (l + r) / 2;
    if(p <= mid) modify(l, mid, 2 * i, p, x);
    else modify(mid + 1, r, 2 * i + 1, p, x);
    sgt[i] = merge_node(sgt[2*i], sgt[2*i+1]);
}

node query(int l, int r, int i, int ql, int qr){
    if(ql <= l && r <= qr){
        return sgt[i];
    }
    int mid = (l + r) / 2;
    if(ql > mid) return query(mid + 1, r, 2 * i + 1, ql, qr);
    else if(qr <= mid) return query(l, mid, 2 * i, ql, qr);
    else if(ql <= mid && mid < qr){
        node ls = query(l, mid, 2 * i, ql, mid), rs = query(mid + 1, r, 2 * i + 1, mid + 1, qr);
        return merge_node(ls, rs);
    }
}

void solve(){
    int n, m, q; cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int l, r, x; cin >> l >> r >> x;
        mod[l].pb(pii(i, x));
        mod[r + 1].pb(pii(i, 0));
    }
    cin >> q;
    vector<int> S(q + 5, 0), T(q + 5, 0);
    for(int i = 1; i <= q; ++i){
        int k; cin >> k;
        Q[k].pb(i);
        cin >> S[i] >> T[i];
    }
    for(int i = 1; i <= n; ++i){
        for(auto [p, x]:mod[i]) modify(1, m, 1, p, x);
        for(auto id:Q[i]) ans[id] = query(1, m, 1, S[id], T[id]).mx;
    }
    for(int i = 1; i <= q; ++i) cout << ans[i] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
