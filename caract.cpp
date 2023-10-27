#include <iostream>
#include <cctype>
#include <cassert>
using namespace std;

bool debutmot(char caractere) {
    return (islower(caractere) || isupper(caractere));
}
bool caractAgarder(char caractere){
    return (islower(caractere) || isupper(caractere) || isdigit(caractere)) || caractere == '_';
}
unsigned comptermots(string chaine) {
    unsigned compteur = 0;
    bool DansLeMot = false;

    for (unsigned i = 0; i < chaine.size(); i++) {
        if (!DansLeMot && debutmot(chaine[i])) {
            compteur++;
            DansLeMot = true;
        } else if (DansLeMot && !debutmot(chaine[i])) {
            DansLeMot = false;
        }
    }

    return compteur;
}

int main() {
// Je fais les tests maintenants.
    assert(comptermots("Jadore Casali")==2);
        assert(comptermots("123 456 ")==0);
        assert(comptermots("_casali")==1);

    string lignelue;
    while (true) {
        cout << "Entrez une ligne: " << endl;
        getline(cin, lignelue);

        if (lignelue.size() == 0)
            break;

        cout << "Cette chaîne contient " << comptermots(lignelue) << " mots" << endl;
            break;
    }


}
