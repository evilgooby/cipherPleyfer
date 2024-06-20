#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CipherPlayfer {
public:
    CipherPlayfer();
    ~CipherPlayfer(); //Деструктор (память не выделял удалять нечего)
    void encode();
    void decode();

private:
    string encryptedMessage;
    string decryptedMessage;
    char matrix[5][5];
    string word;
    string code;
    vector<int> index;
    vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i','j','k', 'l', 'm', 'n', 'o', 'p', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
};
