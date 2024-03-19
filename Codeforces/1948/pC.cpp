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
    string s[2];
    cin >> s[0] >> s[1];
    queue<pair<pii, int>> bfs;
    vector<vector<int>> vis(2, vector<int> (n, 0));
    vis[0][0] = 2;
    bfs.push(mp(mp(0, 0), 2));
    while(bfs.size()){
        pii p = bfs.front().ff;
        int x = p.ff, y = p.ss;
        int type = bfs.front().ss;
        bfs.pop();
        if(type == 1){
            if(s[x][y] == '>' && vis[x][y + 1] != 2){
                vis[x][y + 1] = 2;
                bfs.push(mp(mp(x, y + 1), 2));
            }
            if(s[x][y] == '<' && vis[x][y - 1] != 2){
                vis[x][y - 1] = 2;
                bfs.push(mp(mp(x, y - 1), 2));
            }
        }else{
            if(vis[x ^ 1][y] == 0){
                vis[x ^ 1][y] = 1;
                bfs.push(mp(mp(x ^ 1, y), 1));
            }
            if(y != 0 && vis[x][y - 1] == 0){
                vis[x][y - 1] = 1;
                bfs.push(mp(mp(x, y - 1), 1));
            }
            if(y != n - 1 && vis[x][y + 1] == 0){
                vis[x][y + 1] = 1;
                bfs.push(mp(mp(x, y + 1), 1));
            }
        }
    }
    cout << (vis[1][n - 1] ? "Yes" : "No") << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
