#include <bits/stdc++.h>

using namespace std;

signed main() {
    string openText;
    string cipherText;
    string key;
    getline(cin, openText);
    getline(cin, key);
    getline(cin, cipherText);

    int xr = (int)openText[0];
    for (int i = 1; i < openText.length(); ++i)
        xr^= (int)openText[i];
    for (int i = 0; i < key.length(); ++i)
        xr^= (int)key[i];
    for (int i = 0; i < cipherText.length(); ++i)
        xr^= (int)cipherText[i];

    string rs = "";
    int col0 = 0;
    while (xr != 0) {
        rs+= (char)(xr % 2 + 48);
        if (xr % 2 == 0)
            col0++;
        xr/= 2;
    }
    reverse(rs.begin(), rs.end());
    cout << rs << '\n';
    cout << (double)col0 / (double)rs.length() << '\n';



    return 0;
}
