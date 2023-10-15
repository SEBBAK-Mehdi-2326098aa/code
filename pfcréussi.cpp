#include <iostream>
#include <termios.h>

using namespace std;
string demandeprediction(string name)
{
    cout << "Pierre,Papier ou Ciseaux," << name << endl;
    string prediction;
    cin >> prediction;
    if (prediction=="papier" || prediction == "ciseaux" || prediction == "pierre"){
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";//l'idée et de pouvoir cacher la saisie de l'utilisateur sur le terminale meme si ce n'est clairement pas le plus optimale, au moins ça marche;
    }
    unsigned valeur;
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
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            break;
        }
    }
    return prediction;
}


int main()

{string joueur1 , joueur2;
    joueur1=demandeprediction("Joueur 1");
    joueur2= demandeprediction ("Joueur 2");

    if (joueur1==joueur2){
        cout << "Match nul" << endl;}

    if (joueur1=="pierre"&& joueur2=="papier"){
        cout << "Victoire du Joueur 2, le papier bat la pierre" << endl;
    }

    if(joueur1=="pierre" && joueur2== "ciseaux" ){


        cout << "Joueur 1 à gagné, la pierre bat le ciseaux" << endl;
    }


    if(joueur1=="papier" && joueur2=="pierre"){
        cout <<"Joueur 1 à gagné, le papier bat la pierre" << endl;}


    if(joueur1=="papier" && joueur2=="ciseaux"){
        cout << "Joueur 2 à gagné, le ciseaux bat le papier" << endl;}


    if(joueur1=="ciseaux" && joueur2=="pierre"){
        cout << "Joueur 2 à gagné, la pierre bat le ciseaux" << endl;}


    if (joueur1=="ciseaux" && joueur2=="papier"){
        cout << "Joueur 1 à gagner le ciseaux coupe le papier" << endl;

    }




}



