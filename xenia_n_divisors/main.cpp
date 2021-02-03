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
    ll n;
    cin >> n;
    vector<ll> freqArray(8);
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        freqArray[x]++;
    }
    ll ans = 0;
    ll first = 0, second = 0, third = 0;

    if(freqArray[1] > 0 && freqArray[3] > 0 && freqArray[6] > 0){
        ll minVal = min(min(freqArray[1], freqArray[3]), freqArray[6]);
        ans += minVal * 3;
        first = minVal;
        freqArray[1] -= minVal; freqArray[3] -= minVal ; freqArray[6] -= minVal;
    }

    if(freqArray[1] > 0 && freqArray[2] > 0 && freqArray[6] > 0){
        ll minVal = min(min(freqArray[1], freqArray[2]), freqArray[6]);
        ans += minVal * 3;
        second = minVal;
        freqArray[1] -= minVal; freqArray[2] -= minVal ; freqArray[6] -= minVal;
    }

    if(freqArray[1] > 0 && freqArray[2] > 0 && freqArray[4] > 0){
        ll minVal = min(min(freqArray[1], freqArray[2]), freqArray[4]);
        ans += minVal * 3;
        third = minVal;
        freqArray[1] -= minVal; freqArray[2] -= minVal ; freqArray[4] -= minVal;
    }
    if(ans == n){
        for(int i = 0; i < third; i++){
            cout << 1 << " " << 2 << " " << 4 << endl;
        }
        for(int i = 0; i < second; i++){
            cout << 1 << " " << 2 << " " << 6 << endl;
        }
        for(int i = 0; i < first; i++){
            cout << 1 << " " << 3 << " " << 6 << endl;
        }
    } else  {
        cout << -1 << endl;
    }

	return 0;
}
