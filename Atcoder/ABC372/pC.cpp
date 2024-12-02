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
    int n, q; cin >> n >> q;
    string s; cin >> s;
    int cnt = 0;
    for(int i = 0; i < n - 2; ++i){
        if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C'){
            cnt++;
        }
    }
    for(; q; q--){
        int p; cin >> p;
        p--;
        char x; cin >> x;
        if(x == s[p]){
            cout << cnt << '\n';
            continue;
        }
        if(p < n - 2 && s[p] == 'A'){
            if(s[p + 1] == 'B' && s[p + 2] == 'C') cnt--;
        }
        if(p != 0 && p < n - 1 && s[p] == 'B'){
            if(s[p - 1] == 'A' && s[p + 1] == 'C') cnt--;
        }
        if(p > 1 && s[p] == 'C'){
            if(s[p - 2] == 'A' && s[p - 1] == 'B') cnt--;
        }
        if(x == 'A' && p < n - 2){
            if(s[p + 1] == 'B' && s[p + 2] == 'C') cnt++;
        }
        if(x == 'B' && p < n - 1 && p != 0){
            if(s[p - 1] == 'A' && s[p + 1] == 'C') cnt++;
        }
        if(p > 1 && x == 'C'){
            if(s[p - 2] == 'A' && s[p - 1] == 'B') cnt++;
        }
        s[p] = x;
        cout << cnt << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
