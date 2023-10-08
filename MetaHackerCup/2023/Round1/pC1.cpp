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

inline char change(char a){
    if(a == '0') return '1';
    else return '0';
}

inline void solve(int tc){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> v(n + 1, 0);
    int q; cin >> q;
    for(int i = 1; i <= q; ++i){
        int p; cin >> p;
        v[p] ^= 1;
    }
    for(int i = 1; i <= n; ++i){
        if(v[i] == 1){
            for(int j = i; j <= n; j += i){
                s[j - 1] = change(s[j - 1]);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(s[i - 1] == '1'){
            for(int j = i; j <= n; j += i){
                s[j - 1] = change(s[j - 1]);
            }
            ans++;
        }
    }
    cout << "Case #" << tc << ": ";
    cout << ans << '\n';
}

signed main(){
    starburst
    freopen("C1_input.txt", "r", stdin);
    freopen("C1_output.txt", "w", stdout);
    int t = 1; cin >> t;
    for(int i = 1; i <= t; ++i) solve(i);
}
