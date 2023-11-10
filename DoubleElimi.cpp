#include <iostream>
#include <cstdlib>
#include <vector>

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

string tournoiPFC() {
    cout << "Le tournoi va débuter !" << endl;
            vector<string> joueurs = participants();

    vector<string> winnerside(joueurs.size());
    vector<string> looserside ;
    vector<string> perdanttour;


    while (joueurs.size() > 1) {
        winnerside.resize(joueurs.size()/2);




        for (size_t i = 0; i < joueurs.size(); i += 2) {
            cout << joueurs[i] << " VERSUS " << joueurs[i + 1] << endl << endl;
            size_t firstround = quiAgagner(joueurs[i], joueurs[i + 1]);


            if (firstround == 1) {
                winnerside[i/2] = joueurs[i];
                looserside.push_back(joueurs[i+1]);

                cout << "L'équipe " << joueurs[i] << " a gagné" << endl;
            } else {
                winnerside[i/2] = joueurs[i + 1];
                looserside.push_back( joueurs[i]);
                cout << "L'équipe " << joueurs[i + 1] << " a gagné" << endl;
            }

        }

        for (size_t i = 0; i < winnerside.size(); i++) {
            cout << "Gagnant du tour en cours : " << winnerside[i] << endl;
            cout << "Perdant du tour en cours : " << looserside[i] << endl;
            perdanttour.push_back(looserside[i]);


            looserside.clear();
        }



        joueurs=winnerside;

    }
    cout << "Nous avons des vainqueurs, " << joueurs[0] << "est gagnant du winners side, en attente de la grande finale"<< endl << endl;

    for (size_t i = 0 ; i< perdanttour.size() ; i++)
        cout << perdanttour[i] << endl;





    size_t j = 8;


for ( size_t i = 0 ; i<8; i+=2){

    cout << perdanttour[i] << " VERSUS " << perdanttour[i+1] << endl << endl;
    size_t looserround = quiAgagner(perdanttour[i], perdanttour[i+1]);



    if (looserround == 1) {
        perdanttour.insert(perdanttour.begin() + j, perdanttour[i]);
    }
    else {
        perdanttour.insert(perdanttour.begin() +j, perdanttour[i+1]);

    }
    cout << "l'équipe " << perdanttour[j] << "a gagné" << endl << endl;

                    j=j+2;

}


        size_t y = 16;
        for ( size_t i = 0 ; i < 8; i+=2){

        cout << perdanttour[i+8] << " VERSUS " << perdanttour[i+9] << endl;
    size_t looserround2= quiAgagner(perdanttour[i+8], perdanttour[i+9]);

            if (looserround2==1){
        perdanttour.insert(perdanttour.begin() +y, perdanttour[i+8]);

        }
            else{
        perdanttour.insert(perdanttour.begin() +y, perdanttour[i+9]);
        }

        y++;
        }

        cout << "l'équipe " << perdanttour[y] << " a gagné" << endl << endl;


        size_t x = 20;
        for ( size_t i = 2 ; i<6 ; i+=2 ){

        cout << perdanttour[i+14] << "VERSUS " << perdanttour[i+15] << endl;

        int looserround3 = quiAgagner(perdanttour[i+14], perdanttour[i+15]);

        if ( looserround3 == 1){

        perdanttour.insert(perdanttour.begin() + x , perdanttour[i+14]);
        }
        else {

        perdanttour.insert(perdanttour.begin() + x , perdanttour[i+15]);
        }

        x+=2;
        }
        size_t z = 24;
        for ( size_t i = 0; i<4 ; i+=2){

        cout << perdanttour[i+20] << " VERSUS " << perdanttour[i+21] << endl;

        int looserround4 = quiAgagner(perdanttour[i+20], perdanttour[i+21]);

        if (looserround4 == 1){

        perdanttour.insert(perdanttour.begin() + z , perdanttour[i+20]);
        }
        else {
        perdanttour.insert(perdanttour.begin() + z , perdanttour[i+21]);

        }
        }
        cout << " C'est l'heure de la looserfinal" << endl;

        cout << perdanttour[24] << "VERSUS " << perdanttour[25] << endl;

        int looserfinal = quiAgagner(perdanttour[24], perdanttour[25]);

        if (looserfinal == 1){
        perdanttour.insert(perdanttour.begin() + 26, perdanttour[24]);
        }
        else {

         perdanttour.insert(perdanttour.begin() + 26, perdanttour[25]);
        }
        cout << perdanttour[26] << " a gagné" << endl << endl;







        z++;









        for (size_t i = 0 ; i< perdanttour.size() ; i++)
        cout << perdanttour[i] << endl;






    cout << "C'est l'heure de la GRANDE FINALE" << endl << endl;

        cout << winnerside[0] << " VERSUS " << perdanttour[26] << endl << endl;

    size_t grandefinale = quiAgagner(winnerside[0], perdanttour[26]);

    if (grandefinale==1){

        cout << "LE TOURNOI EST REMPORTE PAR " << winnerside[0] << endl;

    }
    else{ cout << "L'équipe revenant du looser a gagné, le gagnant de cette dernière manche sera le grand gagnant du tournoi" << endl;



    }
    if (grandefinale==2){
    size_t dernieremanche= quiAgagner(winnerside[0] , perdanttour[26]);

    if (dernieremanche == 1){
        cout << "LE TOURNOI EST REMPORTE PAR " << winnerside[0] << endl;
    }
    else {
        cout << "LE TOURNOI EST REMPORTE PAR" << perdanttour[26] << "APRES UNE MAGNIFIQUE REMONTADA" << endl << endl;
    }

    }
}





int main()

{

    tournoiPFC();
}
