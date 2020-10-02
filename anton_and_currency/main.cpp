#include <iostream>

using namespace std;
const long long INF = 1e9 + 7;


int main()
{
    string s;
    cin >> s;

    long long length = s.size() - 1;
    for(int i = 0; i < length; i++){
        int aux = s[i] - '0';
        if(aux % 2 == 0 && aux < s[length]-'0'){
            char c = s[length];
            s[length] = s[i];
            s[i] = c;
            cout << s << endl;
            return 0;
        }
    }
    for(int i = length - 1; i >= 0; i--){
        int aux = s[i] - '0';
        if(aux % 2 == 0 ){
            char c = s[length];
            s[length] = s[i];
            s[i] = c;
            cout << s << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
