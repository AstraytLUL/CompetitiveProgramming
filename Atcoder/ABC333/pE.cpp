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

vector<int> pos[maxn];

void solve(){
    int n; cin >> n;
    vector<int> T(n + 1, 0), X(n + 1, 0), act(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        cin >> T[i] >> X[i];
    }
    for(int i = 1; i <= n; ++i){
        if(T[i] == 1){
            pos[X[i]].pb(i);
        }else{
            act[i] = -1;
            if(pos[X[i]].empty()){
                cout << "-1\n";
                return;
            }
            int k = pos[X[i]].back();
            pos[X[i]].pop_back();
            act[k] = 1;
        }
    }
    int ans = 0;
    for(int i = 1, cnt = 0; i <= n; ++i){
        cnt += act[i];
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    for(int i = 1; i <= n; ++i){
        if(act[i] >= 0) cout << act[i] << ' ';
    }
    cout << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
