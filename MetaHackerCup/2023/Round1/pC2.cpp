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
    vector<int> v(n + 1, 0), a(n + 1, 0), b(n + 1, 0);
    int ans = 0;
    string t = s;
    for(int i = 1; i <= n; ++i){
        if(t[i - 1] == '1'){
            v[i] = 1;
            for(int j = i; j <= n; j += i){
                t[j - 1] = change(t[j - 1]);
            }
            ans++;
        }
    }
    int q; cin >> q;
    int anss = 0;
    for(int i = 1; i <= q; ++i){
        int p; cin >> p;
        if(v[p] == 1){
            ans--;
        }else{
            ans++;
        }
        v[p] ^= 1;
        anss += ans;
        swap(b[p], a[p]); 
    }
    cout << "Case #" << tc << ": ";
    cout << anss << '\n';
}

signed main(){
    starburst
    freopen("C2_input.txt", "r", stdin);
    freopen("C2_output.txt", "w", stdout);
    int t = 1; cin >> t;
    for(int i = 1; i <= t; ++i) solve(i);
}
