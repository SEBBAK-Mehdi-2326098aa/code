#include <iostream>
#include <vector>
#include <cstdlib>
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
    vector <string> equipes (16);

    for (size_t i=0; i!=16; i++){

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


vector<string> RoundSwiss () {


    struct joueur
    {
        size_t points;
        bool a_joué = false;
    };


    vector<string> joueurs= participants();
    vector<joueur> pointsjoueurs(joueurs.size());

    for ( size_t i = 0; i<joueurs.size(); i+=2 ){

        cout << joueurs[i] << " VERSUS " << joueurs[i+1] << endl << endl;
        int premierround = quiAgagner(joueurs[i], joueurs[i+1]);

        if (premierround == 1) {
            pointsjoueurs[i].points = 1;
            pointsjoueurs[i+1].points = 0;

            cout << joueurs[i] << " a gagné" << endl;
        }
        else {

            pointsjoueurs[i+1].points = 1;
            pointsjoueurs[i].points = 0;

            cout << joueurs[i+1] << " a gagné" << endl;
        }



    }



  size_t z= 1;
    for (size_t i =0 ; i< joueurs.size()-1; ){


        if ( pointsjoueurs[i].points!= pointsjoueurs[z].points) {
            z++;
        }
        if (pointsjoueurs[i].points == pointsjoueurs[z].points && pointsjoueurs[i].a_joué == false && pointsjoueurs[z].a_joué == false){

            cout << joueurs[i] << " VERSUS " << joueurs[z] << endl << endl;

            int secondround= quiAgagner(joueurs[i], joueurs[z]);

            if (secondround== 1){
                pointsjoueurs[i].points+=1;
                pointsjoueurs[i].a_joué = true;
                pointsjoueurs[z].a_joué = true;
            }
            else {
                pointsjoueurs[z].points+=1;
                pointsjoueurs[z].a_joué = true;
                pointsjoueurs[i].a_joué = true;
            }

            }
        i++;


        }
        // je remets toutes les booleans a false pour le round suivant

        for (size_t i=0 ; i<joueurs.size(); i++){

        pointsjoueurs[i].a_joué = false;
        }

        cout << "C'est l'heure du round 3 !" << endl;








// je declare x qui va parcourir avec les nombres de points de chaque équipes
size_t x=1;
bool ToutLeMondeAjoue = false;
size_t i=0;


//une boucle for me permet de parcourir tout les nombres de points avec i
        while(ToutLeMondeAjoue == false){




        // Ce while me permet d'incrémenter x tant qu'il ne trouve pas la meme valeur que i
        while (pointsjoueurs[i].points!= pointsjoueurs[x].points) {

            if (x ==16){
                break;
            }
            x++;

        }

// je vérifie que les équipes ont toutes les 2 pas joués et si elles ont le meme nombre de points alors on joue
        if (pointsjoueurs[i].points == pointsjoueurs[x].points && pointsjoueurs[i].a_joué == false && pointsjoueurs[x].a_joué == false){

            cout << joueurs[i] << " VERSUS " << joueurs[x] << endl << endl;

            int troisièmeround= quiAgagner(joueurs[i], joueurs[x]);
// l'équipe qui gagne voit son nombre de points augmenter, et dans tout les cas le bool a_joué prend la valeur true puisque meme si tu perds tu as quand meme joué
            if (troisièmeround== 1){
                pointsjoueurs[i].points+=1;
                pointsjoueurs[i].a_joué = true;
                pointsjoueurs[x].a_joué = true;
            }
            else {
                pointsjoueurs[x].points+=1;
                pointsjoueurs[x].a_joué = true;
                pointsjoueurs[i].a_joué = true;
            }

            }
//j'incrémente i de 1 pour qu'il parcours la valeurs suivante du tableau
            //je réinitialise x a i+1 afin de ne sauter aucune équipe
        i++;
        x=i+1;




            if (pointsjoueurs[14].a_joué==true){
                ToutLeMondeAjoue = true;
            }









        }


        cout << "C'est l'heure de la finale du TOURNOI" << endl << endl;

        size_t finaliste1=0;

        size_t finaliste2=1;

        // je remets toutes les booleans a false pour trouver les 2 finalistes

        for (size_t i=0 ; i<joueurs.size(); i++){

            pointsjoueurs[i].a_joué = false;
        }


        while ( pointsjoueurs[finaliste1].points != 3){
            finaliste1++;
        }
        pointsjoueurs[finaliste1].a_joué = true;

            while (pointsjoueurs[finaliste2].points != 3 && pointsjoueurs[i].a_joué == false){
            finaliste2++;
        }


        cout << joueurs[finaliste1] << " VERSUS " << joueurs[finaliste2];



        int finale = quiAgagner(joueurs[finaliste1], joueurs[finaliste2]);

        if (finale == 1){

        cout << joueurs[finaliste1] << " A GAGNER LE TOURNOI " << endl << endl;

        }
        else {

        cout << joueurs[finaliste2] << " A GAGNER LE TOURNOI " << endl << endl;
        }


        }















int main()
{
    RoundSwiss();
    return 0;
}
