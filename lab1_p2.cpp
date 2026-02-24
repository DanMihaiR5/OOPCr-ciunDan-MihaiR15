#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main () {
    ifstream input("in_lab1_p2.txt");
  string s;
  getline(input,s);
  
  vector <char>rand;
  vector <int>lungime;
  vector <vector<char>>cuvinte;
  int k=0;
  int start=0;
  for (int i=0;i<s.length();i++) {
    if ((s[i]==' ')&&(s[i+1]!=' ')) {
        for (int j=start;j<start + k;j++) {
            rand.push_back(s[j]);
        }
        cuvinte.push_back(rand);
        lungime.push_back(k);
        k=0;
        rand.clear();
        start=i+1;
        continue;
    }
    if (s[i]==' '&&s[i+1]==' ') {
      continue;
    }
    if (s[i+1]=='\0') {
        k++;
        for (int j=start;j<start+k;j++) {
            rand.push_back(s[j]);
        }
        cuvinte.push_back(rand);
        lungime.push_back(k);
        rand.clear();
        break;
    }
    k++;
  }
  //
for (int i=0;i<lungime.size()-1;i++) {
    for (int j=0;j<lungime.size()-i-1;j++) {
    if (lungime[j]<=lungime[j+1]) {
    swap(lungime[j],lungime[j+1]);
    swap(cuvinte[j],cuvinte[j+1]);
    }
  }
    }
    //
for (int i=0;i<lungime.size()-1;i++) {
  if (lungime[i]==lungime[i+1]) {
    if (cuvinte[i]>cuvinte[i+1]) {
        swap(cuvinte[i],cuvinte[i+1]);
    }
  }
}
    //
    
  for (int i=0;i<cuvinte.size();i++){
    for (int j=0;j<cuvinte[i].size();j++) {
cout<<cuvinte[i][j];
    }
cout<<endl;
  }
 return 0;
}