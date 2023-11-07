#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

string pierrefeuilleciseaux(string nomJoueur)
{
    cout << "Pierre,Papier ou Ciseaux," << nomJoueur << endl;
    string prediction;
    cin >> prediction;

    int valeur;

    if (prediction=="papier" || prediction == "ciseaux" || prediction == "pierre"){
        system("clear");
    }
    if (prediction == "pierre" || prediction=="Pierre"){
        cout <<"Choix done."<< endl << endl;
        valeur=1;
    }
    else if (prediction=="Papier" || prediction=="papier"){
        cout << "Choix done" << endl <<endl;
        valeur=2;
    }
    else
        if(prediction == "Ciseaux" || prediction=="ciseaux"){
            cout << "Choix done."<< endl << endl;
            valeur=3;
        }
    while (valeur != 1 && valeur !=2 && valeur !=3){
        cout << "il faut saisir soit pierre, papier ou ciseau." << endl;
        cin >> prediction;
        if (prediction=="papier" || prediction=="pierre" || prediction=="ciseaux" ){
            system("clear");
            break;
        }
    }

    return prediction;

}

int quiAgagner (string joueur1 , string joueur2) {


    int resultat;
    joueur1 =  pierrefeuilleciseaux(joueur1);
    joueur2 =  pierrefeuilleciseaux(joueur2);

    if (joueur1==joueur2){
        resultat=0;
        cout << "Match nul" << endl;
    }

    if (joueur1=="pierre"&& joueur2=="papier"){
        cout << "Victoire du Joueur 2, le papier bat la pierre" << endl;
        resultat=2;

    }

    if(joueur1=="pierre" && joueur2== "ciseaux" ){
        cout << "Joueur 1 à gagné, la pierre bat le ciseaux" << endl;
                resultat=1;
    }


    if(joueur1=="papier" && joueur2=="pierre"){
        cout <<"Joueur 1 à gagné, le papier bat la pierre" << endl;
                resultat= 1;}

    if(joueur1=="papier" && joueur2=="ciseaux"){
        cout << "Joueur 2 à gagné, le ciseaux bat le papier" << endl;
                resultat =2;}

    if(joueur1=="ciseaux" && joueur2=="pierre"){
        cout << "Joueur 2 à gagné, la pierre bat le ciseaux" << endl;
                resultat=2;}

    if (joueur1=="ciseaux" && joueur2=="papier"){
        cout << "Joueur 1 à gagner le ciseaux coupe le papier" << endl;
    }


    while (resultat == 0){
        cout << "Il faut jouer de nouveau." <<endl;

        joueur1=pierrefeuilleciseaux(joueur1);

        joueur2= pierrefeuilleciseaux(joueur2);

        if (joueur1==joueur2){
            resultat=0;
            cout << "Match nul" << endl;
        }

        if (joueur1=="pierre"&& joueur2=="papier"){
            cout << "Victoire du Joueur 2, le papier bat la pierre" << endl;
            resultat=2;

        }

        if(joueur1=="pierre" && joueur2== "ciseaux" ){
            cout << "Joueur 1 à gagné, la pierre bat le ciseaux" << endl;
                    resultat=1;
        }


        if(joueur1=="papier" && joueur2=="pierre"){
            cout <<"Joueur 1 à gagné, le papier bat la pierre" << endl;
                    resultat= 1;}

        if(joueur1=="papier" && joueur2=="ciseaux"){
            cout << "Joueur 2 à gagné, le ciseaux bat le papier" << endl;
                    resultat =2;}

        if(joueur1=="ciseaux" && joueur2=="pierre"){
            cout << "Joueur 2 à gagné, la pierre bat le ciseaux" << endl;
                    resultat=2;}

        if (joueur1=="ciseaux" && joueur2=="papier"){
            cout << "Joueur 1 à gagner le ciseaux coupe le papier" << endl;
        }

    }
    return resultat;
}


vector<string> participants ()
{
    string nom1 , prenom1, nom2, prenom2 , nom3 , prenom3 , nom4 , prenom4;
    int numequipe;
    vector <string> equipes (16);

    for (int i=0; i!=16; i++){

        cout << "Saisissez votre nom puis prénom " << endl;

                    getline (cin , nom1);
        getline (cin , prenom1);

        cout << "Au tour du joueur 2" << endl;
        getline (cin , nom2);
        getline(cin , prenom2);
        cout << "Au tour du joueur 3" << endl;
        getline(cin,nom3);
        getline(cin , prenom3);
        cout << "Au tour du joueur 4" << endl;
        getline (cin , nom4);
        getline (cin, prenom4);
        cout << "Informations de l'équipes " << i+1 << " enregistrés" << endl;



        equipes[i] = nom1 + " " + prenom1 + ", " + nom2 + " " + prenom2 + ", " + nom3 + " " + prenom3 + ", " + nom4 + " " + prenom4;



    }
    return equipes;
}

string tournoiPFC() {
    cout << "Le tournoi va débuter !" << endl;
            vector<string> joueurs = participants();

    vector<string> gagnanttour(joueurs.size());

    while (joueurs.size() > 1) {
        gagnanttour.resize(joueurs.size()/2);
        for (size_t i = 0; i < joueurs.size(); i += 2) {
            cout << joueurs[i] << " VERSUS " << joueurs[i + 1] << endl << endl;
            int premiertour = quiAgagner(joueurs[i], joueurs[i + 1]);

            if (premiertour == 1) {
                gagnanttour[i / 2] = joueurs[i];
                cout << "L'équipe " << joueurs[i] << " a gagné" << endl;
            } else {
                gagnanttour[i / 2] = joueurs[i + 1];
                cout << "L'équipe " << joueurs[i + 1] << " a gagné" << endl;
            }
        }

        for (size_t i = 0; i < gagnanttour.size(); i++) {
            cout << "Gagnant du tour en cours : " << gagnanttour[i] << endl;

        }
         joueurs.assign(gagnanttour.begin(), gagnanttour.end());


    }
    cout << "Nous avons des vainqueurs, l'équipe " << joueurs[0] << " a gagné le tournoi" << endl;
}




int main()

{

    tournoiPFC();
}
