#include <bits/stdc++.h>
using namespace std;
#define mp             make_pair
#define pb             push_back
#define fi             first
#define se             second
#define sz(x)          (int)((x).size())
#define fill(x, y)     memset(x, y, sizeof(y))
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (__typeof(x) i = x; i <= y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
const   int            inf = 0;
const   double         eps = 0;
const   int            ms  = 0;
const   int            md  = 0;
//     vector<vector<int> > vec( n , vector<int> (m));
const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;


int main() {
    ll t, x1, x2, y1, y2;
    string movs;
    cin >> t >> x1 >> y1 >> x2 >> y2;
    cin >> movs;
    char cX = '$', cY = '$';
    if(x1 - x2 > 0){
        cX = 'W';
    } else if(x1- x2 < 0){
        cX = 'E';
    }
    if(y1 - y2 > 0){
        cY = 'S';
    } else if(y1- y2 < 0){
        cY = 'N';
    }
    ll cnt1 = abs(x1 - x2), cnt2 = abs(y1- y2);
   // cout << cX << endl << cY << endl;

    //cout << cnt1 << endl << cnt2<< endl;

    ll ans = 0;
    for(int i = 0; i < movs.size(); i++){
        if(cnt1 > 0 || cnt2 > 0){
            ans++;
        }
        if(movs[i] == cX)
            cnt1--;

        if(movs[i] == cY)
            cnt2--;
    }
    if(cnt1 > 0 || cnt2 > 0){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
	return 0;
}
