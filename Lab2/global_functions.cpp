#include <iostream>
#include "global_functions.h"
#include "Student.h"

using namespace std;

int cmp_nota_mate(Student s1, Student s2){
    if (s1.getmate()==s2.getmate())
        return 0;
    if (s1.getmate()>s2.getmate())
        return 1;
    return -1;
}
int cmp_nota_eng(Student s1, Student s2){
    if (s1.geteng()==s2.geteng())
        return 0;
    if (s1.geteng()>s2.geteng())
        return 1;
    return -1;
}
int cmp_nota_istorie(Student s1, Student s2){
    if (s1.getistorie()==s2.getistorie())
        return 0;
    if (s1.getistorie()>s2.getistorie())
        return 1;
    return -1;
}
int cmp_nota_medie(Student s1, Student s2){
    if (s1.getmedie()==s2.getmedie())
        return 0;
    if (s1.getmedie()>s2.getmedie())
        return 1;
    return -1;
}

int cmp_nume(const Student& s1, const Student& s2){
    int rezultat = strcmp(s1.getnume(),s2.getnume());
    if(rezultat == 0)
        return 0;
    if(rezultat > 0)
        return 1;
    return -1;
}
