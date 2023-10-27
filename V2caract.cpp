#include <iostream>
#include <cctype>
#include <cassert>
using namespace std;

bool debutmot(char caractere) {
    return (islower(caractere) || isupper(caractere));
}

bool caractAgarder(char caractere) {
    return (islower(caractere) || isupper(caractere) || caractere == '_');
}

unsigned comptermots(string chaine) {
    unsigned compteur = 0;
    bool DansLeMot = false;

    for (int i = chaine.size() - 1; i >= 0; i--) {
        if (caractAgarder(chaine[i])) {
            DansLeMot = true;
        } else if (DansLeMot && !caractAgarder(chaine[i])) {
            compteur++;
            DansLeMot = false;
        }
    }

    if (DansLeMot) {
        compteur++;
    }

    return compteur;
}

int main() {
    // Je fais les tests maintenant.
    assert(comptermots("love Casali") == 2);
    assert(comptermots("123 456 ") == 0);
    assert(comptermots("_casali") == 1);

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
