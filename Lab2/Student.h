#pragma once

class Student{
    char nume[100];
    float nota_mate;
    float nota_eng;
    float nota_istorie;
    float nota_medie;

public:
    void setnume(const char* n);
    void setmate(float nota);
    void seteng(float nota);
    void setistorie(float nota);
    void setmedie();

    const char* getnume() const;
    float getmate();
    float geteng();
    float getistorie();
    float getmedie();

    void my_strcpy(const char* source, char* destination){
        while (*source != 0){
            *destination = *source;
            destination++;
            source++;
        }
        *destination = 0;
    };
    int strcmp(const char* first, const char* second){
        while(*first!=0 && *second!=0){
                if(*first>*second)
                    return 1;
                if(*first<*second)
                    return -1;
            }
            if(*first==0 && *second == 0)
                return 0;
            if(*first ==0)
                return -1;
            return 1;
        }
};