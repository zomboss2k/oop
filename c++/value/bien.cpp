#include "iostream"
using namespace std;
int a = 10; // Biến toàn cục

void lamDai (){
    static int a = 6; // Biến tĩnh => tồn tại khi chương trình kết thúc
    a++;
    cout << a << endl;
}

int main (){
    // int a = 4;
    cout << a ++ << endl;
    lamDai();
    lamDai();
    cout << ::a << endl;
    return 0;
}