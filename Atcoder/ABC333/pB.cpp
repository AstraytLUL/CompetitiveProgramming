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
    string s1,s2; cin >> s1 >> s2;
    int l1 = abs(s1[0] - s1[1]), l2 = abs(s2[0] - s2[1]); 
    if(l1 == 3) l1 = 2;
    else if(l1 == 4) l1 = 1;
    if(l2 == 3) l2 = 2;
    else if(l2 == 4) l2 = 1;
    cout << (l1 == l2 ? "Yes\n" : "No\n");
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
