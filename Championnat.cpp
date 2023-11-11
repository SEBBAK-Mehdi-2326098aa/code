#include <iostream>
#include<vector>
#include<cstdlib>
#include <algorithm>

using namespace std;


string pierrefeuilleciseaux(string nomJoueur)
{
    cout << "Pierre,Papier ou Ciseaux," << nomJoueur << endl;
    string prediction;
    cin >> prediction;

    size_t valeur;

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

size_t quiAgagner (string joueur1 , string joueur2) {


    size_t resultat;
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
    size_t numequipe;
    vector <string> equipes (3);

    for (size_t i=0; i!=3; i++){

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













void Championnats (){


// je déclare mon tableau qui reçois les noms des joueurs et le vecteurs associés qui reçoit les points de chaque équipe
    vector<string> joueurs= participants();
    vector<size_t> pointsjoueurs(joueurs.size());


    for ( size_t i = 0; i<joueurs.size(); i++ ){
        size_t j = i+1;

        for ( ; j < joueurs.size() ; j++){

        cout << joueurs[i] << " VERSUS " << joueurs[j] << endl << endl;
        int premierround = quiAgagner(joueurs[i], joueurs[j]);

        if (premierround == 1) {
            pointsjoueurs[i]++;


            cout << joueurs[i] << " a gagné" << endl;
        }
        else {

            pointsjoueurs[j]++;


            cout << joueurs[i+1] << " a gagné" << endl;
        }
        }
    }

        for (size_t i = 0; i < pointsjoueurs.size(); i++) {
        for (size_t z = i + 1; z < pointsjoueurs.size(); z++) {
            if (z < joueurs.size() && pointsjoueurs[z] > pointsjoueurs[i]) {
                swap(pointsjoueurs[i], pointsjoueurs[z]);
                swap(joueurs[i], joueurs[z]);
            }
        }
        }





        cout << joueurs[0] << " sont les grands gagnants du championnats ";






}




int main()
{
    Championnats();
}
