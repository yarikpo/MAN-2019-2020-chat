#include <bits/stdc++.h>
// #include "vish.cpp"
#include "myA.cpp"

using namespace std;

signed main() {
    string alphabet = "";
    map<char, int> position;
    for (char i = 1; i <= 254; ++i)
        alphabet+= i;

    for (size_t i = 0; i < alphabet.length(); ++i)
        position[alphabet[i]] = i;

    form_table(alphabet, position);
    char **matrix = new char* [alphabet.length()];
    char **cipherMatr = new char* [alphabet.length()];
    for (size_t i = 0; i < alphabet.length(); ++i) {
        matrix[i] = new char[alphabet.length()];
        cipherMatr[i] = new char[alphabet.length()];
    }
    pair<char**, char**> p = read_table("./table.vis", alphabet);
    matrix = p.first;
    cipherMatr = p.second;
    

    string openText = "";
    string key = "";
    string cipherText = "";

    cout << "openText: ";
    cin >> openText;
    cout << "key: ";
    cin >> key;


    int sz = openText.length();
    cipherText = myAlgo_cipher(openText, key, matrix, position, 1);
    cout << "ciphertext: " << cipherText << '\n';
    string opt = myAlgo_decipher(cipherText, key, cipherMatr, position, 1);
    openText = "";
    for (size_t i = 0; i < sz; ++i)
        openText+= opt[i];

    cout << "openText: " << openText << '\n';
    


    return 0;
}
