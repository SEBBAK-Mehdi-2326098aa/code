#include <iostream>
#include <experimental/random>

using namespace std;

int main()
{
    int piece;
    cout << "Pile ou Face mon Fils, 1 pour pile et 2 pour face" << endl;
    int prediction;
    cin >> prediction;
    if (prediction==1){
        cout << "Tu as choisi pile" << endl;
    }
    else if(prediction==2){
        cout << "Tu as choisi face" << endl;
    }
    else

    while (prediction != 1 && prediction != 2){

        cout << "ce n'est pas bon c'est sois pile soit face" << endl;

        cin >> prediction;

        if (prediction==1 || prediction==2){
            break;}

    }


    piece= experimental::randint(1,2);
    if (piece==1){
        cout << "C'est pile" << endl;
    }
    else
        cout << "C'est face" << endl ;

    if (prediction == piece){
        cout << "Bien joué tu avais raison" << endl;
    }
    else
        cout << "Tu avais tord sale perdant" << endl;





    return 0;
}
