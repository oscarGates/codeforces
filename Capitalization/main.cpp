#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s.length() > 0 && s[0] > 90)
        s[0] = s[0] - 32;
    cout << s << endl;
    return 0;
}
