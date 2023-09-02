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
#include <unordered_map>
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
//#define int ll
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define maxn 200005
#define mod 1000000007

int G[2005][2005];

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> R(n + 1, vector<int>(27, 0)), C(m + 1, vector<int>(27, 0));
    vector<int> cntR(n + 1, 0), cntC(m + 1, 0);
    vector<int> rmvedR(n + 1, 0), rmvedC(m + 1, 0);
    queue<pair<char, int>> rmv;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            char c; cin >> c;
            G[i][j] = (int)(c - 'a');
            R[i][G[i][j]]++;
            if(R[i][G[i][j]] == 1) cntR[i]++;
            C[j][G[i][j]]++;
            if(C[j][G[i][j]] == 1) cntC[j]++;
        }
    }
    for(int i = 1; i <= n; ++i){
        if(cntR[i] == 1) rmv.push(mp('R', i));
    }
    for(int i = 1; i <= m; ++i){
        if(cntC[i] == 1) rmv.push(mp('C', i));
    }
    while(rmv.size()){
        char c = rmv.front().ff;
        int id = rmv.front().ss;
        rmv.pop();
        if(c == 'R'){
            rmvedR[id] = 1;
            for(int j = 1; j <= m; ++j){
                if(G[id][j] == 26) continue;
                C[j][G[id][j]]--;
                C[j][26]++;
                if(C[j][G[id][j]] == 0) cntC[j]--;
                G[id][j] = 26;
                if(cntC[j] == 1 && C[j][26] < n - 1 && rmvedC[j] == 0) rmv.push(mp('C', j));
            }
        }else{
            rmvedC[id] = 1;
            for(int j = 1; j <= n; ++j){
                if(G[j][id] == 26) continue;
                R[j][G[j][id]]--;
                R[j][26]++;
                if(R[j][G[j][id]] == 0) cntR[j]--;
                G[j][id] = 26;
                if(cntR[j] == 1 && R[j][26] < m - 1 && rmvedR[j] == 0) rmv.push(mp('R', j));
            }
        }
    }
    set<int> ans;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(G[i][j] == 26) {
                //cout << "-1 ";
                continue;
            }
            ans.insert(G[i][j]);
            //cout << G[i][j] << ' ';
        }
        //cout << '\n';
    }
    cout << ans.size() << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
