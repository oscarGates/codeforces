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
bool validate(ll s, ll l, ll r){
    if(l > r){
        ll aux = r;
        r = l;
        l = aux;
    }
    return s < l || s > r;
}

int main() {
    ll n, m, s,f;
    cin >> n>> m >> s >> f;
     ll turn = 1;
    ll mov = 1;
    ll index = 0;
    char movChar = 'R';
    if(s > f){
       mov = -1;
       movChar = 'L';
    }

    for(int i = 0; i < m; i++){
      ll ti, li, ri;
      cin >> ti >> li >> ri;

        while(s!= f && turn < ti){
            cout << movChar;
            s += mov;
            turn++;
        }
        if(s == f)
            break;
        else if(turn == ti){
            if(validate(s, li, ri) && validate(s + mov , li, ri)) {
                cout << movChar;
                s += mov;
                turn++;
            }   else {
                cout << 'X';
                turn++;

            }

        }

    }
    while(s != f){
        cout << movChar;
        s += mov;
    }


    cout << endl;
	return 0;
}
