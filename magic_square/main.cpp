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


int main() {
    ll MAX = 1000000;
    ll arr[9];
    for(int i = 0; i < 9; i++){
        cin >> arr[i];
    }
    ll sums[]= {arr[1] + arr[6], arr[3] + arr[7], arr[1] + arr[7] ,
    arr[3] + arr[5], arr[2] + arr[6], arr[2] + arr[5],
    arr[6] + arr[7]};

    for(int i = 1; i <= MAX; i++){
        ll x1 = i;
        ll y = (x1 + sums[0] == x1 + sums[1])? x1 + sums[0]: -1;

        ll aux1 = y - sums[2], aux2 = y - sums[3], aux3 = y - sums[4];
        ll x2 = (aux1 == aux2 && aux2 == aux3)?  aux1: -1;

        aux1 = y - sums[5], aux2 = y - sums[6];
        ll x3 = (aux1 == aux2)? aux1: -1;

        if(y == -1 || x2 == -1 || x3 == -1)
            continue;
        if(y == x1 + x2 + x3){
            arr[0] = x1;
            arr[4] = x2;
            arr[8] = x3;
            break;
        }


    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[3* i + j] << " ";
        }
        cout << endl;
    }
	return 0;
}
