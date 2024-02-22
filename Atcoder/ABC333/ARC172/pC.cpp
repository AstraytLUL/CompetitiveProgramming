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
    int n; cin >> n;
    string s, t; cin >> s;
    vector<int> A(n, 0), B(n, 0);
    for(int i = 0; i < n; ++i){
        if(i != 0) A[i] = A[i - 1], B[i] = B[i - 1];
        if(s[i] == 'A') A[i]++;
        else B[i]++;
    }
    int ans = 1;
    for(int j = 0; j < n - 1; ++j){
        int cur = A[j] - B[j];
        bool ok = 1;
        if(s[j] != s[j + 1] && s[j + 1] == 'A') A[j]++, B[j]--;
        else if(s[j] != s[j + 1] && s[j + 1] == 'B') B[j]++, A[j]--;
        else ok = 0;
        swap(s[j], s[j + 1]);
        if(cur * (A[j] - B[j]) <= 0 && ok) ans++;
    }
    cerr << '\n';
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
