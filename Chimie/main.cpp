#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Functii.h"

using namespace std;

int main(){
    int n;

    cout<<"Alegeti un alcan pe care programul sa il deseneze: "<<endl<<endl;

    afisare();
    cout<<"\nPentru a iesi din program introduceti alta valoare (ex: 0)"<<endl;

    while(true){
        cout<<endl;
        cout<<"\nVarianta: ";cin>>n;cout<<endl;
        system("cls");
        if(n<1 || n>10){
            break;
        }

        afisare1(n);
        cout<<endl;
        cout<<"=======================================================================================";
        cout<<endl;
        afisare();
        cout<<"\nPentru a iesi din program introduceti alta valoare (ex: 0)"<<endl;

    }


    return 0;
}
