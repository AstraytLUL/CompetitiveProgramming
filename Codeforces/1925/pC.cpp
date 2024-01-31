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
    int n, k, m; cin >> n >> k >> m;
    string s; cin >> s;
    int cur = 0, check = (1ll<<k) - 1, cnt = 0;
    string tmp = "";
    for(int i = 0; i < m; ++i){
        int t = s[i] - 'a';
        cur |= (1ll<<t);
        if(cur == check){
            cur = 0;
            cnt++;
            tmp += s[i];
        }
    }
    if(cnt >= n){
        cout << "yes\n";
    }else {
        cout << "no\n";
        int t;
        for(int i = 0; i < k; ++i){
            if((cur & (1ll<<i)) == 0) {
                t = i; break;
            }
        }
        for(int i = 0; i < n - cnt; ++i) tmp += (char)(t + 'a');
        cout << tmp << '\n';
    }
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
