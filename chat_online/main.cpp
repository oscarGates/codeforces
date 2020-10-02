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

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;

bool itOverlap(ll a, ll b, ll c, ll d){
    return !(b < c || d < a);
}

int main() {
    ll p, q, l, r;
    cin >> p >> q >> l >> r;
    vector<vector<ll> > vectZ( p , vector<ll> (2));
    vector<vector<ll> > vectX( q , vector<ll> (2));

    for(int i = 0; i < p; i++){
        cin >> vectZ[i][0] >> vectZ[i][1];
    }

    for(int i = 0; i < q; i++){
        cin >> vectX[i][0] >> vectX[i][1];
    }
    ll maxValue = -INF;
    for(int i = l; i <= r; i++){
        ll counter = 0;
        for(int j = 0; j < p; j++){
            for(int k = 0; k < q; k++){
                ll x1 = i + vectX[k][0], x2 = i + vectX[k][1];
                if(itOverlap(vectZ[j][0], vectZ[j][1], x1, x2)){
                    counter++;
                }
            }
        }
        maxValue = max(maxValue, counter);
    }

    cout << maxValue << endl;
	return 0;
}
