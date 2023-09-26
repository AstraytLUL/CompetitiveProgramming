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

void solve(int tc){
    cout << "Case #" << tc << ": ";
    int s, d, k; cin >> s >> d >> k;
    int b = (s + d) * 2, p = s + d * 2;
    cout << (b >= k + 1 && p >= k ? "YES" : "NO") << '\n';
}

signed main(){
    starburst
    freopen("A1_input.txt", "r", stdin);
    freopen("A1_output.txt", "w", stdout);
    int t = 1; cin >> t;
    for(int i = 1; i <= t; i++) solve(i);
    fclose(stdin);
    fclose(stdout);
}
