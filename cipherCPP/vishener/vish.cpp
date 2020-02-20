#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

const bool DEBUG = false;

void form_table(string alphabet, map<char, int> position) {
    char matrix[alphabet.length()][alphabet.length()];
    char cipherMatr[alphabet.length()][alphabet.length()];

    for (size_t i = 0; i < alphabet.length(); ++i) {
        matrix[0][i] = alphabet[i];
        cipherMatr[position[alphabet[i]]][i] = alphabet[0];
    }
    for (size_t i = 1; i < alphabet.length(); ++i) {
        for (size_t j = 0; j < alphabet.length(); ++j) {
            matrix[i][j] = matrix[i - 1][(j + 1) % alphabet.length()];
            cipherMatr[position[matrix[i - 1][(j + 1) % alphabet.length()]]][j] = alphabet[i];
        }
    }
    if (DEBUG) {
        for (int i = 0; i < alphabet.length(); ++i) {
            for (size_t j = 0; j < alphabet.length(); ++j)
                cerr << matrix[i][j];
            cerr << '\n';
        }
    }

    ofstream fileOut("./table.vis") ;
    for (size_t i = 0; i < alphabet.length(); ++i) {
        for (size_t j = 0; j < alphabet.length(); ++j) {
            if (DEBUG)
                cerr << matrix[i][j];
            fileOut << matrix[i][j];
        }
        if (DEBUG)
            cerr << '\n';
        fileOut << '\n';
    }
    if (DEBUG)
        cerr << "\n\n";

    fileOut << '\n';
    for (size_t i = 0; i < alphabet.length(); ++i) {
        for (size_t j = 0; j < alphabet.length(); ++j) {
            if (DEBUG)
                cerr << cipherMatr[i][j];
            fileOut << cipherMatr[i][j];
        }
        if (DEBUG)
            cerr << '\n';
        fileOut << '\n';
    }
    fileOut.close();
}


pair<char**, char**> read_table(string path, string alphabet) {
    ifstream fileIn(path);

    char **matrix = new char* [alphabet.length()];
    char **cipherMatr = new char* [alphabet.length()];
    for (size_t i = 0; i < alphabet.length(); ++i) {
        matrix[i] = new char[alphabet.length()];
        cipherMatr[i] = new char[alphabet.length()];
    }
    for (size_t i = 0; i < alphabet.length(); ++i)
        for (size_t j = 0; j < alphabet.length(); ++j)
            fileIn >> matrix[i][j];

    for (size_t i = 0; i < alphabet.length(); ++i)
        for (size_t j = 0; j < alphabet.length(); ++j)
            fileIn >> cipherMatr[i][j];

    fileIn.close();
    return {matrix, cipherMatr};
}


string cipher_vish(string openText, string key, char** matrix, map<char, int> position) {
    string cipherText = "";
    for (size_t i = 0; i < openText.length(); ++i) {
        cipherText+= matrix[position[openText[i]]][position[key[i]]];
    }
    return cipherText;
}

string decipher_vish(string cipherText, string key, char** cipherMatr, map<char, int> position) { // 2m - position of i(char) in _ciphertext
    string openText = "";
    for (size_t i = 0; i < cipherText.length(); ++i) {
        openText+= cipherMatr[position[cipherText[i]]][position[key[i]]];
    }
    return openText;
}
