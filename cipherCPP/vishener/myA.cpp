#include <bits/stdc++.h>
#include "vish.cpp"

using namespace std;

string myAlgo_cipher(string openText, string key, char** matrix, map<char, int> position, int rounds) {
    vector<string> blocks;
    string block = "";
    while(openText.length() % key.length() != 0)
        openText+= " ";

    for (size_t i = 0; i < openText.length(); ++i) {
        block+= openText[i];
        if (block.length() == key.length()) {
            blocks.push_back(block);
            block = "";
        }
    }

    blocks[0] = cipher_vish(blocks[0], key, matrix, position);
    for (size_t i = 1; i < blocks.size(); ++i) { // first round
        blocks[i] = cipher_vish(blocks[i], blocks[i - 1], matrix, position);
    }

    for (size_t j = 1; j < rounds; ++j) {
        blocks[0] = cipher_vish(blocks[0], blocks[blocks.size() - 1], matrix, position);
        for (size_t i = 1; i < blocks.size(); ++i) {
            blocks[i] = cipher_vish(blocks[i], blocks[i - 1], matrix, position);
        }
    }
    string cipherText = "";
    for (size_t i = 0; i < blocks.size(); ++i)
        for (size_t j = 0; j < blocks[i].length(); ++j)
            cipherText+= blocks[i][j];

    return cipherText;
}

string myAlgo_decipher(string cipherText, string key, char** cipherMatr, map<char, int> position, int rounds) {
    vector<string> blocks;
    string block = "";

    for (size_t i = 0; i < cipherText.length(); ++i) {
        block+= cipherText[i];
        if (block.length() == key.length()) {
            blocks.push_back(block);
            block = "";
        }
    }

    for (size_t j = rounds - 1; j > 0; --j) {
        for (size_t i = blocks.size() - 1; i > 0; --i)
            blocks[i] = decipher_vish(blocks[i], blocks[i - 1], cipherMatr, position);
        blocks[0] = decipher_vish(blocks[0], blocks[blocks.size() - 1], cipherMatr, position);
    }
    for (size_t i = blocks.size() - 1; i > 0; --i)
        blocks[i] = decipher_vish(blocks[i], blocks[i - 1], cipherMatr, position);
    blocks[0] = decipher_vish(blocks[0], key, cipherMatr, position);

    string openText = "";
    for (size_t i = 0; i < blocks.size(); ++i)
        for (size_t j = 0; j < blocks[i].length(); ++j)
            openText+= blocks[i][j];

    return openText;
}
