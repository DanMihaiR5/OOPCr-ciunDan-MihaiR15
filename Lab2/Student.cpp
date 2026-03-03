#include <iostream>
#include "Student.h"

using namespace std;

void Student::setnume(const char* n){
    my_strcpy(n,nume);
}

void Student::setmate(float nota){
    nota_mate = nota;
}
void Student::seteng(float nota){
    nota_eng = nota;
}
void Student::setistorie(float nota){
    nota_istorie = nota;
}
void Student::setmedie(){
    nota_medie = (nota_mate + nota_eng + nota_istorie) / 3;
}

const char* Student::getnume() const{
    return nume;
}

float Student::getmate(){
    if(nota_mate >=1.0f && nota_mate<=10.0f)
        return nota_mate;
    return -1;
}
float Student::geteng(){
    if(nota_eng >=1.0f && nota_eng<=10.0f)
        return nota_eng;
    return -1;
}
float Student::getistorie(){
    if(nota_istorie >=1.0f && nota_istorie<=10.0f)
        return nota_istorie;
    return -1;
}
float Student::getmedie(){
        return nota_medie;
}



