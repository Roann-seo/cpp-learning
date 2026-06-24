#include<iostream>
using namespace std;
int strlen(char str[]) {
    int count = 0;
    while (*str != '\0') {
        count++;
        *str++;
    }
    return count;
}
void strreverse(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    cout << str << endl;
}
int main() {
    char str[] = "qwertyuiop";
    cout<<strlen(str)<<endl;
    strreverse(str);
    return 0;
}