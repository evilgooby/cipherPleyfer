#include "class/class.h"

using namespace std;

int main() {
    CipherPlayfer s;
    int x = 0;
    cout <<"Введите 1 если хотите закодировать сообщение или 0 если хотите раскодировать"<<endl;
    cin >> x;
    if (x == 1){
        s.encode();
    }else{
         s.decode();
    }
    return 0;
}