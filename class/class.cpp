#include "class.h"

CipherPlayfer::CipherPlayfer() {
    cout<<"Введите слово с помощью которого будем шифровать/расшифровывать сообщение"<<endl;
    cout<<"Слово должно быть не более 8 символов"<<endl;
    cout<<"Слова вводить на английском прописными буквами!";
    cout<<"Все повторяющиеся буквы будут удалены"<<endl;
    cout<<"После ввода нажмите Enter"<<endl;
    for (int i = 0; i < 5; ++i) { // Запрос на ввод слова
        bool t = false;
        cin >> word;
        for (int j = 0; j < word.length(); ++j) {
            if (!(word[j] >= 97 && word[j] <= 122)){
                cout << word[j] << " не верный символ" << endl;
                cout << "Попробуйте ещё раз" << endl;
                t = false;
                break;
            }
            t = true;
        }
        if (t) {
            break;
        }
    }
    for (int i = 0; i < word.length(); ++i) { // удаление повторяющихся букв
        if (word[i] == word[i+1]) {
            string::iterator it = word.begin() + i;
            word.erase(it);
            i--;
        }
    }
    for (int i = 0; i < word.length(); ++i) { // удаление букв из алфавита
        for (int j = 0; j < alphabet.size(); ++j) {
            if (word[i] == alphabet[j]) {
                alphabet.erase(alphabet.begin() + j);
                j--;
            }
        }
    }
    int temp = 0;
    int tempAlphabet = 0;
    for (int i = 0; i < 5; ++i) { // Заполнение матрицы
        for (int j = 0; j < 5; ++j) {
            if (temp < word.length()){
                matrix[i][j] = word[temp];
                temp++;
            }
            else{
                matrix[i][j] = alphabet[tempAlphabet];
                tempAlphabet++;
            }
        }
    }
    for (int i = 0; i < 5; ++i) {//Вывод матрицы
        for (int j = 0; j < 5; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Введите слово которое хотите закодировать или раскодировать"<<endl;
    bool t = false;
    for (int i = 0; i < 5; ++i) {//Запрос на ввод кодового слова
        cin >> code;
        for (int j = 0; j < code.length(); ++j) {
            if (!(code[j] >= 97 && code[j] <= 122)){
                cout << code[j] << " не верный символ" << endl;
                cout << "Попробуйте ещё раз" << endl;
                t = false;
                break;
            }
            else
            {
                t = true;
            }
        }
        if (t){
            break;
        }
    }
    if (code.length() % 2 != 0){//Проверка на четность
        code += 'w';
    }

    for (int i = 0; i < code.length(); ++i) {//Поиск букв в матрице и запись их в массив индексов
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                if (code[i] == matrix[j][k]) {
                    index.push_back(j);
                    index.push_back(k);
                }
            }
        }
    }
    for(int i = 0; i < code.length(); i+=2){//Вывод биграмма в консоль
        cout << code[i] <<code[i + 1];
        cout << " ";
    }
    cout << endl;
}
CipherPlayfer::~CipherPlayfer() {}
void CipherPlayfer::encode(){ //Шифрование
    int a = 0, b = 0;
    for(int i = 0; i <= index.size()-3; i+=4){
        if (index[i] == index[i+2]){
            encryptedMessage += matrix[index[i]][(index[i+1]+1) % 5];
            encryptedMessage += matrix[index[i+2]][(index[i+3]+1) % 5];
        }else if (index[i+1] == index[i+3]){
            encryptedMessage += matrix[(index[i]+1) % 5][index[i+1]];
            encryptedMessage += matrix[(index[i+2]+1) % 5][index[i+3]];
        }else{
            encryptedMessage += matrix[index[i]][index[i+3]];
            encryptedMessage += matrix[index[i+2]][index[i+1]];
        }
    }
    cout << endl;
    cout << encryptedMessage << endl;
}
void CipherPlayfer::decode(){//Дешифрование
    int a = 0, b = 0;
    for(int i = 0; i <= index.size()-3; i+=4){
        if (index[i] == index[i+2]){
            decryptedMessage += matrix[index[i]][(index[i+1]+4) % 5];
            decryptedMessage += matrix[index[i+2]][(index[i+3]+4) % 5];
        }else if (index[i+1] == index[i+3]){
            decryptedMessage += matrix[(index[i]+4) % 5][index[i+1]];
            decryptedMessage += matrix[(index[i+2]+4) % 5][index[i+3]];
        }else{
            decryptedMessage += matrix[index[i]][index[i+3]];
            decryptedMessage += matrix[index[i+2]][index[i+1]];
        }
    }
    cout << endl;
    cout <<  decryptedMessage << endl;
}
