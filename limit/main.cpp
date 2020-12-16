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
ll maxComunDivisor(ll num1, ll num2){
    ll a = max(num1, num2);
    ll b = min(num1, num2);
    ll ans;
    do{
        ans = b;
        b = a % b;
        a = ans;
    } while(b != 0);
    return ans;
}

int main() {
    ll n, m;
    cin >> n >> m;
    ll a, b;
    cin >> a;
    for(int i = 1; i < n + 1; i++){
        ll aux;
        cin >> aux;
    }
    cin >> b;
    for(int i = 1; i <  m+1; i++){
        ll aux;
        cin >> aux;
    }
    ll fSign = 1, sSign = 1;
    if(a < 0)
        fSign = -1;
    if(b < 0)
        sSign = -1;
    bool flag = fSign * sSign < 0;

    if(n > m){
        if(flag)
            cout << "-";
        cout << "Infinity";

    } else if(m > n){
        cout << "0/1" << endl;
    } else{
        if(flag)
            cout << "-";

        ll mcd =maxComunDivisor(a, b);
        cout << abs(a/ mcd) << "/" << abs(b/mcd)<< endl;
    }

	return 0;
}
