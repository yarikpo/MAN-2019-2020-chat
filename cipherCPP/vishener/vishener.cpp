#include <bits/stdc++.h>
#include "vish.cpp"

using namespace std;



signed main() {
    freopen("vinput.txt", "r", stdin);
    freopen("voutput.txt", "w", stdout);

    string alphabet = "";
    map<char, int> position;
    for (char i = 'a'; i <= 'z'; ++i)
        alphabet+= i;
    for (char i = 'A'; i <= 'Z'; ++i)
        alphabet+= i;
    alphabet+= " !@#$%^&*()_-+=1234567890,.";
    

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
    

    ///
    /*for (int i = 0; i < alphabet.size(); i++) {
        for (int j = 0; j < alphabet.size(); j++)
            cerr << matrix[i][j];
        cerr << '\n';
    }
    cerr << "\n\n";*/
    ///



    
    string openText = "";
    string cipherText = "";
    string key = "";
    cerr << "Open text: ";
    getline(cin, openText);
    cerr << "Key: ";
    getline(cin, key);

    srand(time(NULL));

    cipherText = cipher_vish(openText, key, matrix, position);
    
    cout << fixed << setprecision(9) << "\n\n#######################################\n" << "time: " << clock() / 1000.0 << "\n\n#################################\n";
    
    cout << "cipher: " << cipherText << '\n';
    cipherText = decipher_vish(cipherText, key, cipherMatr, position);
    cerr << "checkOpen: " << cipherText << '\n';



    return 0;
}
