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

set<int> ans;

struct TRIE{
    vector<vector<int>> node;
    vector<int> val;
    string change(string s){
        for(int i = 0; i < (int) s.size(); ++i){
            s[i] = s[i] - 'a';
        }
        return s;
    }
    void init(){
        node.assign(1, vector<int>(5, -1));
        val.assign(1, 0);
    }
    void add_node(int cur, int nxt){
        node[cur][nxt] = node.size();
        node.pb(vector<int>(5, -1));
        val.pb(0);
    }
    void add_string(string s){
        s = change(s);
        int cur = 0;
        for(int i = 0; i < (int) s.size(); ++i){
            int c = s[i];
            if(node[cur][c] == -1) add_node(cur, c);
            cur = node[cur][c];
        }
        val[cur] += 1;
    }
    void search(string s, int id, int pos){
        if(pos == -1) return;
        if(id == (int) s.length()) {
            ans.insert(pos);
            return;
        }
        if((s[id] + 'a') == '?'){
            search(s, id + 1, pos);
            for(int i = 0; i < 5; ++i){
                search(s, id + 1, node[pos][i]);
            }
        }else{
            search(s, id + 1, node[pos][s[id]]);
        }
    }
}trie;

void solve(){
    int n, m; cin >> n >> m;
    trie.init();
    for(int i = 1; i <= n; ++i){
        string s; cin >> s;
        trie.add_string(s);
    }
    for(int i = 1; i <= m; ++i){
        string s; cin >> s;
        ans.clear();
        s = trie.change(s);
        trie.search(s, 0, 0);
        int cnt = 0;
        for(int j:ans) cnt += trie.val[j];
        cout << cnt << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
