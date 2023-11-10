#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <thread>
#include <cassert>

using namespace std;
typedef vector <vector<double>> CMatrix;

CMatrix Mat;

bool estbientrie(const vector<unsigned>tableau ){
    bool trier=false;
size_t i=0;
while(tableau[i]<= tableau[i+1] && i < tableau.size()-1){
    i=i+1;
}
if(i == tableau.size()-1){
    trier=true;
}


if(trier == true ){
    cout << "c'est bon"<< endl << endl;
}else{
    cout << "ce n'est pas bien trié "<< endl << endl;
}

return  trier;

}




void selectSort (vector <unsigned> & tableau){




        size_t n,mini,j,temp;
        size_t taille = tableau.size();
        for (n=0 ; n< taille ; n++){
            mini = n ;
            for (j = n+1 ; j< taille ; j++){
                if (tableau[j] < tableau[n]){
                    mini = j ;
                }
            }
            temp = tableau[n];
            tableau[n] = tableau[mini] ;
            tableau[mini ] = temp ;
        }


            for ( size_t z= 0 ; z < tableau.size() ; z++){

            cout << "|" << tableau[z] << "|" ;

        }
    }





void insertSort (vector <unsigned> & tableau)
{

            size_t ancien;

            size_t i = 0;
            for (  ; i < tableau.size()-1;i++)
                if (tableau[i+1] < tableau[i]){

                    ancien = tableau[i];
                    tableau[i] = tableau[i+1];
                    tableau[i+1] = ancien;
                }








            for ( size_t z= 0 ; z < tableau.size() ; z++){

                cout << "|" << tableau[z] << "|" ;

            }


        }


void bubbleSort (vector <unsigned> & tab)
{


                int inter;
                while(estbientrie(tab) == false){
                    for(size_t i=0; i< tab.size();++i){
                    if(tab[i] > tab[i+1]){
                        inter=tab[i];
                        tab[i]=tab[i+1];
                        tab[i+1]=inter;
                    }
                    }
                }
            }




void countingSort (vector <unsigned> & vUint)
{


            {
                vector<unsigned> tab2;
                unsigned min=0,max=vUint[0];
                for(size_t i=1;i<vUint.size();++i)
                {
                    if(max<vUint[i])
                    {
                    max = vUint[i];
                    }
                }
                tab2.resize(max+1);
                for(unsigned j=0;j<max+1;++j)
                {
                    for(size_t n=0;n<vUint.size();++n)
                    {
                    if(j == vUint[n])
                    {
                        tab2[j] += 1;

                    }
                    }
                }
                for(size_t t=0;t<tab2.size();++t)
                {
                    while(tab2[t] != 0)
                    {
                    vUint[min] = t;
                    min += 1;
                    tab2[t] -= 1;
                    }
                }
            }


}

void languageSort (vector<unsigned> & VUint)
{
    sort (VUint.begin(), VUint.end());
}

void initMat (unsigned NbColumns)
{
    Mat.resize(5, vector <double> (NbColumns));
}

//http://stackoverflow.com/questions/2962785/c-using-clock-to-measure-time-in-multi-threaded-programs
void protoGenericSort(void (*mySort) (vector <unsigned> & vUint), const vector <unsigned> & vUint, unsigned NbFois, unsigned PosMat, unsigned VectNum)
{
    for (unsigned i (0); i < NbFois; ++i)
    {
        vector <unsigned> copyVUint (vUint);
        struct timespec start, finish;
        double elapsed;
        clock_gettime(CLOCK_MONOTONIC, &start);
        mySort (copyVUint);
        clock_gettime(CLOCK_MONOTONIC, &finish);
        elapsed = (finish.tv_sec - start.tv_sec);
        elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
        Mat [PosMat][i + NbFois * VectNum] = elapsed;
    }
}

void traiterResultats (const unsigned & nbElemAEnlever)
{
    for (vector <double> & UneLigne : Mat)
    {
        //tri
        sort (UneLigne.begin(), UneLigne.end());
        //suppresion des éléments non significatifs
        UneLigne = vector <double> (UneLigne.begin() + nbElemAEnlever / 2, UneLigne.end() - nbElemAEnlever / 2 );
        //plus petit temps
        double min (UneLigne[0]);
        //plus grand temps
        double max (UneLigne[UneLigne.size()-1]);
        //temps median
        double med (UneLigne[UneLigne.size()/2]);

        //On assigne les valeurs memorisees aux 3 premières cases
        UneLigne[0] = min;
        UneLigne[1] = med;
        UneLigne [2] = max;
    }
    //Affichage
    cout << setw (20) << "Tri" << setw (10) << "Min" << setw (10) << "Med" << setw (10) << "Max" << endl;
    vector<string> VMetode {"Selection", "Insertion", "Bulles", "comptage", "Langage"};
    for (unsigned i (0); i < VMetode.size(); ++i)
        cout << setw (20) << VMetode[i] << setw (10) << setprecision(6) << Mat[i][0] << setw (10) << setprecision(6) << Mat[i][1] << setw (10) << setprecision(6) << Mat[i][2] << endl;

}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cerr << "boulette !\n utilisation : " << argv [0] << " (1) NbElem par vecteur (2) Nb de vecteurs differents (3) Nb itérations par vecteur" << endl;
            return 1;
    }

    unsigned NbElem (stoul(argv[1]));
    unsigned NbVecteurs (stoul(argv[2]));
    unsigned NbFois (stoul(argv[3]));

    srand (time(NULL));
    vector <unsigned> VUInt (NbElem);
    initMat (NbFois * NbVecteurs);


    for (unsigned i (0); i < NbVecteurs; ++i)
    {
        for (auto & Val : VUInt)
            Val = rand () % (VUInt.size() * 10);

        thread th1 (protoGenericSort, selectSort, VUInt, NbFois, 0, i);
        thread th2 (protoGenericSort, insertSort, VUInt, NbFois, 1, i);
        thread th3 (protoGenericSort, bubbleSort, VUInt, NbFois, 2, i);
        thread th4 (protoGenericSort, countingSort, VUInt, NbFois, 3, i);
        thread th5 (protoGenericSort, languageSort, VUInt, NbFois, 4, i);
        th1.join();
        th2.join();
        th3.join();
        th4.join();
        th5.join();
        cout << i << "fini" << endl;
    }

    cout << "Taille des vecteurs : " << NbElem << "\nNb de vecteurs : " << NbVecteurs << "\nNb iterations par vecteur : " << NbFois << endl;
    //On traite les résultats en supprimant 10% des éléments
    traiterResultats (NbFois * NbVecteurs / 10);
    return 0;
}
