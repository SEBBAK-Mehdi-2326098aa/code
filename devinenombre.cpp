#include <iostream>
#include <stdlib.h>
using namespace std;

unsigned devinemonnombre (string name){
    unsigned choix;
    unsigned devine;
    unsigned compteur =0;
    cout << "C'est à " << name << "de jouer" << endl;
    cout << "Choisis une valeur entre 1 et 100" << endl;
    cin >> choix;
    while (choix>100 || choix<0){
        cout << "Il faut saisir une valeur entre 1 et 100 please !" << endl;
        cin >> choix;
        if (choix<1 && choix <101){;
            break;
        }
    }
    system("clear");
    cout << "Joueur 2 essaye de deviner le nombre de J1" << endl;
    cin >> devine;
    compteur=compteur+1;
    while (devine != choix){
        if (devine < choix){
            cout << "C'est plus grand" << endl;
            compteur=compteur + 1;
            cin>> devine;
        }
        else if (devine > choix){
            cout << "C'est plus petit." << endl;
            compteur=compteur + 1;
            cin >> devine;
        }

    }


    cout << "Bien joué tu as trouvé!!" << endl;
            cout << "Tu as trouvé au bout de " << compteur <<" essais. " <<endl;
        return compteur;

}

















int main()
{
    unsigned pointsJ1, pointsJ2;

    pointsJ1 = devinemonnombre(" Joueur 1 ");
    pointsJ2 = devinemonnombre("Joueur 2 ");

    if (pointsJ1==pointsJ2){
        cout << "Match nul vous avez tout les 2 trouver au bout de " << pointsJ1 << " essais. "<< endl;
    }
    else if(pointsJ1 < pointsJ2){
        cout << "Le Joueur 1 à gagner il à trouver au bout de " << pointsJ1 << " essais contre " << pointsJ2 <<endl;
    }

    else
        cout << "Le Joueur 2 à gagné, il à trouver au bout de " << pointsJ2 <<" essais contre " << pointsJ1 << endl;
            return 0;
}
