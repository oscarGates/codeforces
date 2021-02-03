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
    string s;
    ll nb, ns, nc;
    ll pb, ps, pc;
    ll r;
    cin >> s;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;
    ll Nb=0, Ns=0, Nc=0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'B')
            Nb++;
        if(s[i] == 'C')
            Nc++;
        if(s[i] == 'S')
            Ns++;
    }
    ll i = 0, j = 1e15, ans = 0;
    while(j- i > 1){
        ll x = i + (j - i)/2;
        ll price = max(0ll, Nb * x-nb) * pb+ max(0ll, Ns * x-ns)* ps+ max(0ll, Nc * x-nc)* pc;

        if(price <= r){
            i = x;
            ans = max(ans, x);
        } else {
            j = x-1;
        }
    }
    if((max(0ll, Nb * j-nb) * pb+ max(0ll, Ns * j-ns)* ps+ max(0ll, Nc * j-nc)* pc) <= r)
        cout << j << endl;
    else cout << i<< endl;
	return 0;
}
