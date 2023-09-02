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
    string s; cin >> s;
    int n = s.size();
    if(s == "()"){
        cout << "NO\n";
        return;
    }
    string ans1 = "", ans2 = "";
    for(int i = 1; i <= n; ++i){
        ans1 += "()";
        ans2 += "(";
    }
    for(int i = 1; i <= n; ++i){
        ans2 += ")";
    }
    string ans = "";
    bool ok1 = 1, ok2 = 1;
    for(int i = 0; i + n - 1 < 2 * n; ++i){
        bool tmp1 = 1, tmp2 = 1;
        for(int j = i; j < i + n; ++j){
            if(ans1[j] != s[j - i]) tmp1 = 0;
            if(ans2[j] != s[j - i]) tmp2 = 0;
        }
        if(tmp1) ok1 = 0;
        if(tmp2) ok2 = 0;
    }
    cout << "Yes\n";
    if(ok1) cout << ans1 << '\n';
    else if(ok2) cout << ans2 << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
