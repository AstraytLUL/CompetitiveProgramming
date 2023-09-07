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
    vector<int> v(n), idn(n), tag(n);
    for(int &x:v) cin >> x;
    vector<pii> p(n);
    for(int i = 0; i < n; ++i){
        p[i] = mp(v[i], i);
    }
    sort(p.begin(), p.end());
    vector<set<int>> ans;
    for(int i = 0; i < n; ++i){
        if(tag[i]) continue;
        queue<int> bfs;
        bfs.push(i);
        set<int> st;
        while(bfs.size()){
            int cur = bfs.front();
            bfs.pop();
            if(tag[cur]) continue;
            tag[cur] = 1;
            st.insert(cur);
            bfs.push(idn[p[cur].ss]);
            bfs.push(idn[cur]);
            bfs.push(p[cur].ss);
        }
        ans.pb(st);
    }
    cout << ans.size() << '\n';
    for(auto st:ans){
        cout << st.size();
        for(auto x:st) cout << ' ' << x + 1;
        cout << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
