#include <bits/stdc++.h>
#include "vish.cpp"

using namespace std;



signed main() {
    string alphabet = "";
    map<char, int> position;
    for (char i = 'a'; i <= 'z'; ++i)
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
    
    
    for (size_t i = 0; i < alphabet.length(); ++i) {
        for (size_t j = 0; j < alphabet.length(); ++j)
            cerr << matrix[i][j];
        cerr << '\n';
    }
    cerr << "\n\n";
    for (size_t i = 0; i < alphabet.length(); ++i) {
        for (size_t j = 0; j < alphabet.length(); ++j)
            cerr << cipherMatr[i][j];
        cerr << '\n';
    }

    cerr << "\n\n##########################################################\
    #############################################################\n\n";


    string openText = "";
    string cipherText = "";
    string key = "";
    cerr << "Open text: ";
    cin >> openText;
    cerr << "Key: ";
    cin >> key;
    cipherText = cipher_vish(openText, key, matrix, position);
    cerr << "cipher: " << cipherText << '\n';
    openText = decipher_vish(cipherText, key, cipherMatr, position);
    cerr << "checkOpen: " << openText << '\n';



    return 0;
}
