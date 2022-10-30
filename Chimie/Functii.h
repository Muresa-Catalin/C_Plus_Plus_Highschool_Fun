#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string alcan;


ifstream file;

void afisare(){
    file.open("ss.txt");
    if(file.is_open()){
        while(!file.eof()){
            file>>alcan;
            cout<<alcan<<endl;
        }
    }
    file.close();
}
void afisare1(int n){
    ifstream file1;
    file1.open("Alcanii/Metan.txt");
    if(n == 1){
        if(file1.is_open()){
        while(getline(file1, alcan)){
            cout<<alcan<<endl;
        }
      }
    }
    if(n == 2){
        ifstream file2;
        file2.open("Alcanii/Etan.txt");
        if(file2.is_open()){
       while(getline(file2, alcan)){
            cout<<alcan<<endl;
        }
      }
    }
    if(n == 3){
        ifstream file3;
        file3.open("Alcanii/Propan.txt");
        if(file3.is_open()){
        while(getline(file3, alcan)){
            cout<<alcan<<endl;
        }
      }
    }
    if(n == 4){
        ifstream file4;
        file4.open("Alcanii/Butan.txt");
        if(file4.is_open()){
        while(getline(file4, alcan)){
            cout<<alcan<<endl;
        }
      }
    }
    if(n == 5){
        ifstream file5;
        file5.open("Alcanii/Pentan.txt");
        if(file5.is_open()){
        while(getline(file5, alcan)){
            cout<<alcan<<endl;
        }
      }
    }
    if(n == 6){
        ifstream file6;
        file6.open("Alcanii/Hexan.txt");
        if(file6.is_open()){
        while(getline(file6, alcan)){
            cout<<alcan<<endl;
        }
      }
    }
    if(n == 7){
        ifstream file7;
        file7.open("Alcanii/Heptan.txt");
        if(file7.is_open()){
        while(getline(file7, alcan)){
            cout<<alcan<<endl;
        }
      }
    }
    if(n == 8){
        ifstream file8;
        file8.open("Alcanii/Octan.txt");
       if(file8.is_open()){
        while(getline(file8, alcan)){
            cout<<alcan<<endl;
        }
      }
    }
    if(n == 9){
        ifstream file9;
        file9.open("Alcanii/Nonan.txt");
        if(file9.is_open()){
        while(getline(file9, alcan)){
            cout<<alcan<<endl;
        }
      }
    }
    if(n == 10){
        ifstream file10;
        file10.open("Alcanii/Decan.txt");
        if(file10.is_open()){
        while(getline(file10, alcan)){
            cout<<alcan<<endl;
        }
      }
    }

}

#endif // FUNCTII_H_INCLUDED
