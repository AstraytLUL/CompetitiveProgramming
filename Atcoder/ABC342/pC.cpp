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
    string s; cin >> s;
    set<int> st[26];
    for(int i = 0; i < n; ++i){
        st[s[i] - 'a'].insert(i);
    }
    int q; cin >> q;
    for(; q; --q){
        char a, b; cin >> a >> b;
        int u = a - 'a', v = b - 'a';
        // a -> b
        if(u == v) continue;
        if(st[u].size() > st[v].size()){
            swap(st[u], st[v]);
        }
        for(auto x:st[u]){
            st[v].insert(x);
        }
        st[u].clear();
    }
    vector<char> ans(n);
    for(int i = 0; i < 26; ++i){
        for(auto x:st[i]){
            ans[x] = (char)('a' + i);
        }
    }
    for(auto &c:ans) cout << c;
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
