#include <iostream>
#include <vector>

using namespace std;


string litUneString (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return uneChaine;
}

int litUnEntier (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return stoi(uneChaine);
}

struct joueur {
    string nom;
    string prenom;
    unsigned numEquipe;
};




vector < string > joueurs () {

    cout << "Hello World!" << endl;

    vector < string> joueurs(16);
    for (unsigned i (0); i < 114; ++i){
        string nom (litUneString());
        string prenom  (litUneString());
        unsigned numEquipe (litUnEntier());
        //cout << nom << endl << prenom << endl << numEquipe << endl;




        if (numEquipe<16){
            joueurs[numEquipe-1] += nom + " " + prenom + ", ";

        }
    }


    for (int i = 0 ; i < joueurs.size() ; i++){

        cout << joueurs[i] << endl;

}
}

int main()
{

    joueurs();
}






