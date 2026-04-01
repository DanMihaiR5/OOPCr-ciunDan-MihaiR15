#pragma once

class Number
{
   char* value;
   int base;
   public:
   Number(const char* value, int base);
   Number();
   ~Number();
   Number(int val);
   Number(const char* value);

   Number(const Number& copy);
   Number(Number&& move);
   char operator[](int index) const;
   char& operator[](int index);

   void SwitchBase(int newBase);
   int GetDigitsCount() const;
   
   int charToInt(char c) const;
   int intToChar(int a);
   int GetBase() const;
   int toBase10() const;
   void fromBase10(int a);

   friend Number operator+(const Number& a, const Number& b);
   friend Number operator-(const Number& a, const Number& b);

   bool operator==(const Number& a)const;
   bool operator>(const Number& a)const;
   bool operator<(const Number& a)const;
   bool operator>=(const Number& a)const;
   bool operator<=(const Number& a)const;
   bool operator!=(const Number& a)const;

   Number operator--(int);
   Number operator--();
   Number& operator+=(const Number& a);
   Number& operator=(const Number& a);

   int my_strlen(const char* value) const;

   void Print();


};
