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

vector<int> ans;

void findans(int P, int cur, vector<int> tans, int pre){
    if(P == 1){
        for(int i = 1; i <= cur; ++i){
            tans.pb(1);
        }
        if(ans.empty()) ans = tans;
        else if(ans.size() > tans.size()) ans = tans;
        return;
    }
    for(int i = pre; i <= cur; ++i){
        if(P % i == 0){
            vector<int> tmp = tans;
            tmp.pb(i);
            findans(P / i, cur - i, tmp, i);
        }
    }
}

void solve(int tc){
    int P; cin >> P;
    cout << "Case #" << tc << ": ";
    ans.clear();
    findans(P, 41, vector<int>(), 2);
    if(ans.size() == 0) {
        cout << "-1\n";
        return;
    }
    cout << ans.size();
    for(auto x:ans) cout << ' ' << x;
    cout << '\n';
}

signed main(){
    starburst
    freopen("B1_input.txt", "r", stdin);
    freopen("B1_output.txt", "w", stdout);
    int t = 1; cin >> t;
    for(int i = 1; i <= t; ++i) solve(i);
}
