#include <iostream>
#include <random>
#include <vector>
#include <unistd.h>
#include <time.h>
#include <string>
#include "passerLignes.cpp"
#include <stdlib.h>


using namespace std;

size_t devinemonnombre (string name){
    size_t choix;
    size_t devine;
    size_t compteur =0;


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
size_t resultat(){


    size_t pointsJ1, pointsJ2;
    size_t resultat = 0;

    pointsJ1 = devinemonnombre(" Joueur 1 ");
    pointsJ2 = devinemonnombre("Joueur 2 ");

    if (pointsJ1==pointsJ2){
        cout << "Match nul vous avez tout les 2 trouver au bout de " << pointsJ1 << " essais. "<< endl;


    }
    else if(pointsJ1 < pointsJ2){
        cout << "Le Joueur 1 à gagner il à trouver au bout de " << pointsJ1 << " essais contre " << pointsJ2 <<endl;
                resultat = 1;

    }

    else{
        cout << "Le Joueur 2 à gagné, il à trouver au bout de " << pointsJ2 <<" essais contre " << pointsJ1 << endl;
                resultat= 2;
    }
    return resultat;






}

int combat()
{
    float pvj1 (150);
    float pvj2 (150);
    int popo (60);
    int nbj1popo (3);
    int nbj2popo (3);
    int attackj1 (40);
    int attackj2 (40);
    float attack;
    float defensej1 (0);
    float defensej2 (7);
    char (j1);
    char (j2);
    string (nomjoueur1);
    string (nomjoueur2);
    cout << "entrez votre nom joueur 1" << endl;
    cin >> nomjoueur1;
    cout << "entrez votre nom joueur 2"<<endl;
    cin >> nomjoueur2;
    while(pvj1> 0 && pvj2>0)
    {

        cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' <<"Tour de "<<nomjoueur1<< '\n' << '\n';
        cout <<"stat de "<<nomjoueur1<< "  point de vie : " << pvj1 <<'\t'<<"attack "<<attackj1<< "  defense: " << 100*defensej1/(defensej1+100)<<"%" <<'\t'<< "  nombre de potion: "<<nbj1popo << endl;
        cout <<"stat de "<<nomjoueur2<< "  point de vie : " << pvj2 <<'\t'<<"attack "<<attackj2<< "  defense: " << 100*defensej2/(defensej2+100)<<"%" <<'\t'<< "  nombre de potion: "<<nbj2popo <<'\n'<< endl;
        cout <<"que voulez vous faire: " <<'\n'<< "attaquer: 1"<< '\n'<<"prendre une potion: 2"<<'\n'<<"se renforcer: 3"<<'\n'<<"aiguiser sa lame 4"<<endl;
        cin >> j1 ;
        switch ( j1 )
        {
        case '1':
            attack= attackj1*(1-(defensej2/(defensej2+100)));
            pvj2 = pvj2 - attack;
            break;
        case '2':
            if (nbj1popo<=0)
            {
                cout << "vous n'avez plus de potion vous perdez votre tour."<<'\n' ;
                break;
            }
            pvj1 = pvj1 + popo;
            nbj1popo = nbj1popo -1;
            cout << "vous avez maintenant " << pvj1 << "point de vie"<<'\n' << endl;
            break;
        case '3':
            cout<<"se renforcer"<<endl;
            defensej1 = defensej1 + 19;
            break;
        case '4':
            attackj1 = attackj1 +5;
            break;
        default:
            cout <<"erreur mauvais caractère entré"<<endl;
        }
        if (pvj2<=0)
        {
            cout <<nomjoueur1<<" a gagné"<<endl;
                return 1 ;
            break;}


        cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' <<"Tour de "<<nomjoueur2<< '\n' << '\n';
        cout <<"stat de "<<nomjoueur1<< "  point de vie : " << pvj1 <<'\t'<<"attack "<<attackj1<< "  defense: " << 100*defensej1/(defensej1+100)<<"%" <<'\t'<< "  nombre de potion: "<<nbj1popo << endl;
        cout <<"stat de "<<nomjoueur2<< "  point de vie : " << pvj2 <<'\t'<<"attack "<<attackj2<< "  defense: " << 100*defensej2/(defensej2+100)<<"%" <<'\t'<< "  nombre de potion: "<<nbj2popo <<'\n'<< endl;
        cout <<"que voulez vous faire: " <<'\n'<< "attaquer: 1"<< '\n'<<"prendre une potion: 2"<<'\n'<<"se renforcer: 3"<<'\n'<<"aiguiser sa lame 4"<<endl;
        cin >> j2 ;
        switch ( j2 )
        {
        case '1':
            attack= attackj2*(1-(defensej1/(defensej1+100)));            pvj1 = pvj1 - attack;
            break;
        case '2':
            if (nbj2popo<=0)
            {
                cout << "vous n'avez plus de potion vous perdez votre tour." << endl ;
                break;
            }
            pvj2 = pvj2 + popo;
            nbj2popo = nbj2popo -1;
            cout << "vous avez maintenant " << pvj1 << "point de vie"<< '\n'<<endl;
            break;
        case '3':
            defensej2 = defensej2 +19;
            break;
        case '4':
            attackj2 = attackj2 +5;
            break;
        default:
            cout <<"erreur mauvais caractère entré"<<endl;
        }
        if(pvj1 < 0)
        {
            cout<<nomjoueur2<<" a gagné"<<endl;
                return 2;
        }
    }



}


vector <int> score_equipes = {0,0};

vector <vector <string>> questions_geo = {{"Question 1 : Quelle est la capitale du Maroc ?" , "Rabat"},
                                        {"Question 2 : Dans quel pays se trouve Lille ?" , "France"},
                                        {"Question 3 : Sur quel continent se trouve l'Éthiopie ?" , "Afrique"},
                                        {"Question 4 : Quel département possède le numéro 83 ?", "Var"},
                                        {"Question 5 : Quelle est la région de France métropolitaine la plus à l'Ouest ?" , "Bretagne"},
                                        {"Question 6 : Dans quel état américain se trouve Miami ?",  "Floride"},
                                         {"Question 7 : Quelle est la capitale de la Norvège ?" , "Oslo" },
                                         {"Question 8 : Quel département possède le numéro 69 ?" , "Rhône"},
                                         {"Question 9 : Dans quel pays se trouve la Kabylie ?" , "Algérie"},
                                         {"Question 10 : Quel pays partage une frontière avec l'Alaska ?", "Canada"},
                                         {"Question 11 : Quelle est la capitale de l'Italie ?", "Rome"},
                                         {"Question 12 : Quel est le climat du sud de la Californie ?", "Méditerranéen"},
                                          {"Question 13 : Dans quel département se trouve Orcières ?", "Hautes-Alpes"},
                                           {"Question 14 : Quelle est la capitale du Chili ?", "Santiago"},
                                           {"Question 15 : Quelle est la capitale du Luxembourg ?", "Luxembourg"},
                                           {"Question 16 : Quel est le département de Vitrolles ?", "Bouches-du-Rhône"},
                                            {"Question 17 : Quelle est la capitale du Kirghizistan ?", "Bichkek"},
                                            {"Question 18 : Dans quel continent se trouve la Papouasie-Nouvelle-Guinée ?",  "Océanie"},
                                             {"Question 19 : Quelle est la capitale du Botswana ?", "Gaborone"},
                                             {"Question 20 : Quel est le pays où la France possède sa plus grande frontière terrestre ?", "Brésil"}};


int quiz(vector <vector<string> > questions_quiz)
{
    vector <int> liste_scores = {0, 0};
    cout << "Bienvenue dans un quiz joueur vs joueur" << endl;
    cout << "Le jeu se deroule en tour par tour" << endl;
    string reponse_quiz;
    for (int j = 0; j < int(liste_scores.size()); j++)
    {
        cout << "C'est à l'équipe " << j + 1 << " de jouer." << endl;
            for(int i = 0; i < int(questions_quiz.size()); i++)
        {
            cout << questions_quiz[i][0] << endl;
            cin >> reponse_quiz;
            if  (reponse_quiz == questions_quiz[i][1])
            {
                cout << ("Tu as eu vrai, bien joué !") << endl;
                        cout << ("+ 1 point") << endl;
                liste_scores[j] += 1;       }
            else
            {
                cout << "Faux";
                cin.ignore();
                cout << endl;
            }
        }
        passerLignes();
    }
    // Cette partie-là détermine le gagnant
    int equipe_gagnante = 1;
    if (liste_scores[1] > liste_scores[0])
    {
        equipe_gagnante = 2;
    }
    return equipe_gagnante;
}

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

// Liste avec les phrases qui peuvent être tirées pour le téléphone arabe
vector <string> tableau_de_phrases = {"Ne bougez pas ! Il y a une araignée gigantesque derrière vous !",
                                     "Tu as très mauvaise haleine en ce moment, ou c’est juste moi ?",
                                     "Je n’ai aucune idée de ce que je fais, mais je sais que je le fais très bien.",
                                     "Les lapins grondent, les géants grognent, les chiens aboient dans le noir, et les loups courent dans le bois.",
                                     "J’adorerais manger des sandwiches au fromage grillé et au thon.",
                                     "Le renard brun et rapide saute par-dessus le chien paresseux et dit bonjour au chat.",
                                     "Les oiseaux en colère ont mangé des bonbons.",
                                     "L’entrée est gardée par un dragon cracheur de feu, myope et qui a le vertige.",
                                     "Si j’étais un dinosaure, je serais un Ankylosaure : j’ai un extérieur dur et blindé, mais un cœur d’or feuillu et aimant !",
                                     "Tu sens vraiment bon aujourd’hui."};

                                     // Fonction qui affiche la phrase du joueur précédent, et renvoie celle que le joueur en cours écrit
                                     string teleArabeJoueurEnCours(string & phrase_en_cours)
                                     {
                                      cout << "Une phrase va apparaitre et tu devras la recopier. Tu as 10 secondes pour la mémoriser. Ne commence à l'écrire que quand on te dit de le faire." << endl;
                                          sleep(3);
cout << "La phrase est: " << phrase_en_cours << endl;
sleep(10);
passerLignes();
cout << "Réécris la phrase que tu as vu" << endl;
        getline(cin >> ws, phrase_en_cours);
passerLignes();
return phrase_en_cours;
}

// Fonction principale
int jeuTeleArabe(int nombre_equipes, int nombre_joueurs)
{
    // Initialise l'aléatoire
    srand(time(NULL));
    // Crée un tableau où l'on stockera les résultats des équipes (initialisés à 0 par défaut)
    vector <int> resultats_equipes;
    for (int i = 0; i < nombre_equipes; i++)
    {
        resultats_equipes.push_back(0);
    }
    // Boucle principale
    for (int j = 0; j < nombre_equipes; j++)
    {
        /*
        int nb_aleatoire;
        nb_aleatoire = rand() % tableau_de_phrases.size();
        */
        int nb_aleatoire = 8;
        string phrase_originale = tableau_de_phrases[nb_aleatoire];
        string phrase_finale = phrase_originale;
        cout << "C'est à l'équipe " << j + 1 << " de jouer." << endl;
            for (int k = 0; k < nombre_joueurs; k ++ )
        {
            phrase_finale = teleArabeJoueurEnCours(phrase_finale);
        }
        for (size_t l = 0; l < phrase_originale.size(); ++l) {
            if (phrase_originale[l] != phrase_finale[l]) {
                resultats_equipes[j] = resultats_equipes[j] + 1;
            }
        }
    }
    // Initialise un tableau de deux éléments, le premier étant l'indice 0 pour l'équipe 1 et le second le résultat de l'équipe 1
    vector <int> equipe_gagnante = {0,resultats_equipes[0]};
    // Renvoie l'indice du plus petit élément de la liste des résultats (donc le gagnant, car il a le plus petit score)
    for (int m = 0; m < int(resultats_equipes.size()); m++)
    {
        if (resultats_equipes[m] < equipe_gagnante[1])
        {
            equipe_gagnante = {m, resultats_equipes[m]};
        }
    }
    // Si tu veux vérifier quelle équipe à gagner ici tu peux faire un cout de ce que renvoie la fonction, ou bien dans int main
    return (equipe_gagnante[0]+1);
}


// Pour appeler la fonction, fais jeuTeleArabe(nombre d'équipes qui est un entier naturel, nombre de joueurs qui est un entier naturel)








int duel ( string equipe1 , string equipe2){

    int round1 , round2 , round3, round4, round5;

    int compteur1=0 , compteur2 =0;

    round1 = quiAgagner(equipe1,equipe2);
    round2 = quiz(questions_geo);
    round3 = combat();
    round4 = resultat();
    round5 = jeuTeleArabe(1,1);



    if (round1 == 1 ){

        compteur1++;


    }
    else{
        compteur2++;
    }

    if (round2 == 1 ){

        compteur1++;


    }
    else{
        compteur2++;
    }
    if (round3 == 1 ){

        compteur1++;


    }
    else{
        compteur2++;
    }
    if (round4 == 1 ){

        compteur1++;


    }
    else{
        compteur2++;
    }
    if (round5 == 1 ){

        compteur1++;


    }
    else{
        compteur2++;
    }

    if (compteur1>compteur2){

        return 1;
    }
    else {
        return 2;
    }

}


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




vector < string > participants () {



    vector < string> joueurs(16);
    cout << "Saisissez votre nom puis prénom et numéro d'équipe" << endl;
    for (unsigned i (0); i < 114; ++i){


        string nom (litUneString());
        string prenom  (litUneString());
        unsigned numEquipe (litUnEntier());
        //cout << nom << endl << prenom << endl << numEquipe << endl;



        if (numEquipe >= 1 && numEquipe <= 16) {
            joueurs[numEquipe-1] += nom + " " + prenom + ", ";
        }

    }



    return joueurs;
}



string tournoiPFC() {
    cout << "Le tournoi va débuter !" << endl;
            vector<string> joueurs = participants();

    vector<string> gagnanttour(joueurs.size());

    while (joueurs.size() > 1) {
        gagnanttour.resize(joueurs.size()/2);
        for (size_t i = 0; i < joueurs.size(); i += 2) {
            cout << joueurs[i] << " VERSUS " << joueurs[i + 1] << endl << endl;
            int premiertour = duel(joueurs[i], joueurs[i + 1]);

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
