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
    int m; cin >> m;
    string s[3]; cin >> s[0] >> s[1] >> s[2];
    sort(s, s + 3);
    int ans = 1e18;
    do{
        for(int i = 0; i <= m; ++i){
            int t = i;
            char c1 = s[0][t % m], c2, c3;
            for(int j = i + 1; j - i <= m; ++j){
                t = j;
                c2 = s[1][t % m];
                for(int k = j + 1; k - j <= m; ++k){
                    t = k;
                    c3 = s[2][t % m];
                    if(c1 == c2 && c2 == c3) ans = min(ans, t);
                }
            }
        }
        cerr << s[0] << ' ' << s[1] << ' ' << s[2] << '\n';
    }while(next_permutation(s, s + 3));
    cout << (ans == 1e18 ? -1 : ans) << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
