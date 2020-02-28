#include <bits/stdc++.h>
// #include "vish.cpp"
#include "myA.cpp"

using namespace std;

signed main() {
    setlocale(LC_ALL, "Russian");

    string alphabet = "";
    map<char, int> position;
    for (char i = 'a'; i <= 'z'; ++i)
        alphabet+= i;
    for (char i = 'A'; i <= 'Z'; ++i)
        alphabet+= i;
    alphabet+= " !@#$%^&*()_+=-.,";
    for (char i = '0'; i <= '9'; ++i)
        alphabet+= i;
    /*for (char i = 'а'; i <= 'я'; ++i)
        alphabet+= i;
    for (char i = 'А'; i <= 'Я'; ++i)
        alphabet+= i;*/


    /*for (char i = 1; i <= 150; ++i)
        alphabet+= i;*/


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
    getline(cin, openText);
    
    cout << "key: ";
    getline(cin, key);

    int rds = 0;
    cout << "rounds: ";
    cin >> rds;

    int sz = openText.length();
    cipherText = myAlgo_cipher(openText, key, matrix, position, rds);
    
    cout << "ciphertext: " << cipherText << '\n';
    string opt = myAlgo_decipher(cipherText, key, cipherMatr, position, rds);
    openText = "";
    for (size_t i = 0; i < sz; ++i)
        openText+= opt[i];

    cout << "openText: " << openText << '\n';




    return 0;
}
