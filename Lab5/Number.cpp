#include "Number.h"
#include <iostream>

Number::Number(const char* val, int base){
    this -> base = base;
    int l = my_strlen(val);
    value = new char[l+1];
    for(int i=0; i<l; i++)
        value[i] = val[i];
    value[l] = '\0';
}
Number::~Number(){
    delete[] value;
}

Number::Number(const Number& copy){
    base = copy.base;
    int len = my_strlen(value);
    value = new char[len+1];
    for(int i=0; i<len; i++)
        value[i]=copy.value[i];
    value[len] ='\0';
}

Number::Number(Number&& move){
    value= move.value;
    base= move.base;

    move.value = nullptr;
    move.base = 0;
}

int Number::my_strlen(const char* value) const{
      int i=0;
      while(value[i] != '\0')
         i++;
      return i;
}

int Number::GetBase() const{
    return base;
}

int Number::charToInt(char c) const{
    if(c >= '0' && c <= '9')
        return c - '0';
    return c - 'A' + 10;
}

int Number::intToChar(int a){
    if (a<10)
        return a + '0';
    else
        return a-10 + 'A';
}

int Number::toBase10() const{
   int numar = 0;
   for(int i=0; i< my_strlen(value); i++){
        numar = numar * base + charToInt(value[i]);
   }
   return numar;
}

void Number::fromBase10(int numar){
    if(numar == 0){
        delete [] value;
        value = new char[2];
        value[0] = '0';
        value[1] = '\0';
        return;
    }
    char temp[100];
    int i = 0;
    while(numar > 0){
        int rest = numar % base;
        temp[i] = intToChar(rest);
        numar = numar/base;
        i++;
    }
    int l=i;
    delete[] value;
    value = new char[l+1];
    for(int j=0; j<l; j++){
        value[j] = temp[l-j-1];
    }
    value[i] = '\0';
}

void Number::Print(){
    for (int i=0; i< my_strlen(value); i++){
        std::cout <<value[i];
    }
}

Number operator+(const Number& a, const Number& b){
    int val_a = a.toBase10();
    int val_b = b.toBase10();
    int sum = val_a + val_b;
    int baza = (a.GetBase() > b.GetBase()) ? a.GetBase() : b.GetBase();
    Number c("", baza);
    c.fromBase10(sum);
    return c;
}

Number operator-(const Number& a, const Number& b){
    int val_a = a.toBase10();
    int val_b = b.toBase10();
    int sum = val_a - val_b;
    int baza = (a.GetBase() > b.GetBase()) ? a.GetBase() : b.GetBase();
    Number c("", baza);
    c.fromBase10(sum);
    return c;
}

bool Number::operator==(const Number& a)const{
    return this->toBase10() == a.toBase10();
}
bool Number::operator>(const Number& a)const{
    return this->toBase10() > a.toBase10();
}
bool Number::operator<(const Number& a)const{
    return this->toBase10() < a.toBase10();
}
bool Number::operator>=(const Number& a)const{
    return this->toBase10() >= a.toBase10();
}
bool Number::operator<=(const Number& a)const{
    return this->toBase10() <= a.toBase10();
}
bool Number::operator!=(const Number& a)const{
    return this->toBase10() != a.toBase10();
}

void Number::SwitchBase(int newBase){
    int val = toBase10();
    base = newBase;
    fromBase10(val);
}

int Number::GetDigitsCount()const{
    return my_strlen(value);
}

char Number::operator[](int index) const{
    return value[index];
}
char& Number::operator[](int index){
    return value[index];
}

Number Number::operator--(int){ //postfix
    int len = GetDigitsCount();
    Number c = *this;
    value[len-1] = '\0';
    return c;
}

Number Number::operator--(){ //prefix
    int len = GetDigitsCount();
    Number c =*this;
    for(int i =0; i<len; i++)
        value[i] = value[i+1];
    value[len-1] = '\0';
    return c;
}

Number& Number::operator=(const Number& a){
    if(this == &a) return *this;
    base = a.base;
    int len = a.GetDigitsCount();

    delete[] value;
    value = new char[len+1];
    for(int i=0; i<len; i++){
        value[i] = a.value[i];
    }
    value[len]='\0';
    return *this;
}
Number& Number::operator+=(const Number& a){
    
    int val_a = a.toBase10();
    int val_this = this->toBase10();
    int sum = val_a + val_this;
    int baza = (this->GetBase() > a.GetBase()) ? this->GetBase() : a.GetBase();
    fromBase10(sum);
    return *this;
}

Number::Number(const char* val) {
    base = 10;              
    int l = my_strlen(val);
    value = new char[l+1];
    for(int i=0; i<l; i++)
        value[i] = val[i];
    value[l] = '\0';
}
Number::Number(int val) {
    base = 10;                 
    fromBase10(val);             
}