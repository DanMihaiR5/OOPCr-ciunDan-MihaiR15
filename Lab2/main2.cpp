#include <iostream>
#include "Student.h"
#include "global_functions.h"

using namespace std;

int main(){
    Student s1, s2;

    s1.setnume("ion");
    s1.setmate(6.5f);
    s1.seteng(9.0f);
    s1.setistorie(5.0f);
    s1.setmedie();

    s2.setnume("palarie");
    s2.setmate(9.0f);
    s2.seteng(5.0f);
    s2.setistorie(5.9f);
    s2.setmedie();

    cout << "Media studentului " << s1.getnume() << " este " << s1.getmedie() << endl;
    cout << "Media studentului " << s2.getnume() << " este " << s2.getmedie() << endl;

    cout << "Compara nume: " << cmp_nume(s1, s2)<< endl;
    cout << "Compara nota mate: " << cmp_nota_mate(s1, s2)<< endl;
    cout << "Compara nota eng: " << cmp_nota_eng(s1, s2)<< endl;
    cout << "Compara nota istorie: " << cmp_nota_istorie(s1, s2)<< endl;
    cout << "Compara nota medie: " << cmp_nota_medie(s1, s2)<< endl;
    

    return 0;
}