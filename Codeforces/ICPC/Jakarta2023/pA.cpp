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
    string s; 
    string a, b, c; cin >> a >> b >> c;
    s = a + b + c;
    string ans = "CCC";
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            for(int k = 0; k < 9; ++k){
                string tmp = "";
                tmp += s[i];
                tmp += s[j];
                tmp += s[k];
                if(i == j || i == k || j == k) continue;
                pii p1(i / 3, i % 3), p2(j / 3, j % 3), p3(k / 3, k % 3);
                if(abs(p1.ff - p2.ff) > 1 || abs(p1.ss - p2.ss) > 1) continue;
                if(abs(p3.ff - p2.ff) > 1 || abs(p3.ss - p2.ss) > 1) continue;
                ans = min(ans, tmp);
            }
        }
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
