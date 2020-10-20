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
    ll square[10];
    set<ll> s;
    for(int i = 1; i <= 9; i++){
        cin >> square[i];
        s.insert(square[i]);
    }
    for(int i = 1; i < 1000000; i++){

        square[1] = i;
        ll sums[9];
        sums[1] = square[1] + square[2] + square[3];
        square[5] = sums[1] - square[4] - square[6];
        square[9] = sums[1] - square[7] - square[8];
        if(square[5] <= 0 || square[9] <= 0 )
            continue;
        sums[2] = square[4] + square[5] + square[6];
        sums[3] = square[7] + square[8] + square[9];
        sums[4] = square[1] + square[4] + square[7];
        sums[5] = square[2] + square[5] + square[8];
        sums[6] = square[3] + square[6] + square[9];
        sums[7] = square[1] + square[5] + square[9];
        sums[8] = square[3] + square[5] + square[7];
        int pos[] = {1, 3, 5};

        for(int i = 2; i <= 8; i++){
            if(sums[i] != sums[1])
                continue;

        }
        break;

    }

    for(int i = 1; i <= 9; i++){
        if(i == 4 || i == 7)
            cout << endl;
        cout << square[i] << " ";
    }
	return 0;
}
