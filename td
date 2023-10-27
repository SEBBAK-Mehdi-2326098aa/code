#include <iostream>
#include <cctype>
using namespace std;

bool isspace (char c){
    return (c == ' '|| c=='\t' || c == '\n');
}
int CompterDoublonsV1(string chaine){
    if (chaine.size()<2) return 0;

    unsigned compt=0;
    int i = 0;
    while(i<chaine.size()){
        if (!isspace(chaine[i]) && chaine[i]==chaine[i-1]){
            compt++;
            i++;
        }
    }
    i++;
    return compt;
}





int main()
{
    string lignelue;
    while(true){
        cout << "Entrez une string" << endl;
        cin >> lignelue;
        if (lignelue.size()==0){
            break;
        }
            unsigned nmbredoublons;
            nmbredoublons = CompterDoublonsV1(lignelue);

            cout << lignelue << endl;

            cout << "Le nombre de doublons: " <<nmbredoublons << endl;

    }


}
