#include <bits/stdc++.h>
// #include "vish.cpp"
#include "myA.cpp"

using namespace std;

signed main() {
    // setlocale(LC_ALL, "");

    bool isCipher = false;
    cout << "Type 0 to cipher information/1 to decipher: ";
    cin >> isCipher;
    string path = "";
    cout << "enter path of the file: ";
    cin >> path;
    cout << "enter path where to write information: ";
    string outPath = "";
    cin >> outPath;

    // freopen(path.c_str(), "r", stdin);
    // freopen("output.txt", "w", stdout);
    ifstream gin(path.c_str());
    ofstream gout(outPath.c_str());

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
    
    
    
    // cout << "openText: ";
    getline(gin, openText);
    
    // cout << "key: ";
    getline(gin, key);

    int rds = 0;
    // cout << "rounds: ";
    gin >> rds;

    int sz = openText.length();
    if (!isCipher) {
        cipherText = myAlgo_cipher(openText, key, matrix, position, rds);
        gout << cipherText << '\n';
        cerr << cipherText << '\n';
    } else {
        cipherText = openText;
        string opt = myAlgo_decipher(cipherText, key, cipherMatr, position, rds);
        openText = "";
        for (size_t i = 0; i < sz; ++i)
            openText+= opt[i];

        gout << opt << '\n';
        cerr << opt << '\n';
    }

    system("pause");

    return 0;
}
