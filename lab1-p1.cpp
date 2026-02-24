#include <iostream>
#include <fstream>
using namespace std;


int conditie(char s[]){
    long long a=0;
    for (int i=0; s[i]!='\0'; i++){
    a= a*10 + s[i] - '0';
    }
    return a;
}

int main(){
    ifstream input("in_lab1_p1.txt");
    char s[100];
    int k;
    while(input>>s){
        int x=conditie(s);
        k+=x;
    }
    cout << k;
}