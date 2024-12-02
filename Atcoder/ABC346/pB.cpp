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
    int w, b; cin >> w >> b;
    string s = "wbwbwwbwbwbw";
    string piano = "";
    for(int i = 0; i < 100; ++i){
        piano = piano + s;
    }
    bool ok = 0;
    for(int l = 0; l < piano.size(); ++l){
        int wc = 0, bc = 0;
        for(int r = l; r < piano.size(); ++r){
            if(piano[r] == 'w') wc++;
            else bc++;
            if(wc == w && bc == b) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No";
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
