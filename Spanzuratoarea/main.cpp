#include <iostream>
#include <windows.h>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <stdlib.h>

using namespace std;

int input, numarDeLinii = -1;
string const morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.",
    "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
    ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
string convertToEnglish(string morse, string const morseCode[]);
string omulet, cuvantAles;

string AlegereaUnuiCuvantAleatoriu(int intervalulDeCuvinte){
    string line;
    ifstream file2("cuvinte.txt");
    if(file2.is_open()){
        while(!file2.eof()){
            getline(file2, line);
            numarDeLinii++;
            if(numarDeLinii == intervalulDeCuvinte){
                srand(time(NULL));
                int randomInt = rand () % 20 + intervalulDeCuvinte;
                for(int i = numarDeLinii; i<=randomInt; i++){
                    getline(file2, line);
                }
                return line;
            }
        }
    }
}

void AfisareOmuletIntreg(){
    ifstream file1;
    file1.open("Omulet/omuletIntreg.txt");
    if(file1.is_open()){
        while(getline(file1, omulet)){
            cout<<omulet<<endl;
        }
    }
    file1.close();
}

void AfisareOmuletFara1Picior(){
    ifstream file1;
    file1.open("Omulet/omuletFara1Picior.txt");
    if(file1.is_open()){
        while(getline(file1, omulet)){
            cout<<omulet<<endl;
        }
    }
    file1.close();
}

void AfisareOmuletFaraPicioare(){
    ifstream file1;
    file1.open("Omulet/omuletFaraPicioare.txt");
    if(file1.is_open()){
        while(getline(file1, omulet)){
            cout<<omulet<<endl;
        }
    }
    file1.close();
}

void AfisareOmuletFara1Mana(){
    ifstream file1;
    file1.open("Omulet/omuletFara1Mana.txt");
    if(file1.is_open()){
        while(getline(file1, omulet)){
            cout<<omulet<<endl;
        }
    }
    file1.close();
}

void AfisareOmuletFaraMaini(){
    ifstream file1;
    file1.open("Omulet/omuletFaraMaini.txt");
    if(file1.is_open()){
        while(getline(file1, omulet)){
            cout<<omulet<<endl;
        }
    }
    file1.close();
}

void AfisareOmuletFaraTrunchi(){
    ifstream file1;
    file1.open("Omulet/omuletFaraTrunchi.txt");
    if(file1.is_open()){
        while(getline(file1, omulet)){
            cout<<omulet<<endl;
        }
    }
    file1.close();
}

void AfisareTitlu(){
    system("Color 0F");
    for(int i = 1; i<=21; i++){
        cout<<" ";
    }
    cout<<"Bine ati venit la jocul Spanzuratoarea"<<endl;

    for(int i = 1; i<=21; i++){
        cout<<" ";
    }
    for(int i = 1; i<=38; i++){
        Sleep(50);
        cout<<"*";
    }
    cout<<"\n\n";
}

void AfisareMeniu(){
    system("Color 0F");
    cout<<"Alegeti dificultatea jocului: "<<endl<<endl;
    cout<<"1.Usor"<<endl;
    Sleep(90);
    cout<<"2.Mediu"<<endl;
    Sleep(90);
    cout<<"3.Greu"<<endl;
    Sleep(90);
    cout<<"4.Dau o ciocolata daca castigi"<<endl<<endl;

    cout<<"Optiunea: ";
}

void AlegereDificultate(int &n){
    cin>>n;cout<<"\n\n";
}

void SelectareaDificultatii(int dificultate){
    switch(dificultate){
    case 1:
        cuvantAles = AlegereaUnuiCuvantAleatoriu(0);
        break;
    case 2:
        cuvantAles = AlegereaUnuiCuvantAleatoriu(20);
        break;
    case 3:
        cuvantAles = AlegereaUnuiCuvantAleatoriu(40);
        break;
    case 4:
        cuvantAles = AlegereaUnuiCuvantAleatoriu(60);
        break;
    default:
        exit(0);
    }
}

string MorseToRo(string morse, string const morseCode[]){
    string output = "";
    string currentLetter = "";
    istringstream ss(morse);

    size_t const characters = 26;

    while(ss >> currentLetter)
    {
        size_t index = 0;
        while(currentLetter != morseCode[index] && index < characters)
        {
            ++index; //increment here so we don't have to decrement after the loop like if we put in the condition
        }

        output += 'A' + index;
    }

    return output;
}

void SelectareOmuleti(int n){
  switch(n){
  case 6:
    AfisareOmuletIntreg();
    break;
  case 5:
    AfisareOmuletFara1Picior();
    break;
  case 4:
    AfisareOmuletFaraPicioare();
    break;
  case 3:
    AfisareOmuletFara1Mana();
    break;
  case 2:
    AfisareOmuletFaraMaini();
    break;
  case 1:
    AfisareOmuletFaraTrunchi();
    break;
  }
}

void GhicireCuvant(string cuvantDeGhicit){
    cuvantDeGhicit = cuvantAles;
    int k = 6, ok, a=-1;;
    char s[100], varianta, sirAfisat[20], cuvinteGresiteFolosite[100];
    strcpy(s, cuvantDeGhicit.c_str());
    for(int i = 0; i<strlen(s); i++){
        s[i] = tolower(s[i]);
        //cout<<s[i];
    }
    //cout<<s<<endl;
    for(int j = 0; j<strlen(s); j++){
        sirAfisat[j] = '^';
    }
    sirAfisat[strlen(s)] = 0;
    sirAfisat[0] = s[0];
    sirAfisat[strlen(s)-1] = s[strlen(s)-1];
    for(int i = 1; i<strlen(s)-1; i++){
        if(s[i] == sirAfisat[0] || s[i] == sirAfisat[strlen(s)-1]){
            sirAfisat[i] = s[i];
        }
    }
    cout<<sirAfisat<<endl;

    while(strcmp(s, sirAfisat) != 0 && k > 0){
        ok = 0;
        cin>>varianta;cout<<endl;
          for(int i = 1; i<strlen(s)-1; i++){
            if(varianta == s[i]){
              sirAfisat[i] = s[i];
              //cout<<sirAfisat<<endl;
              ok = 1;
            }
          }
          //cout<<ok<<endl;
          if(ok == 0){
            k--;
            a++;
            cuvinteGresiteFolosite[a] = varianta;
            if(a >= 0){
              cuvinteGresiteFolosite[a+1] = 0;
            }
          }
          system("CLS");
          SelectareOmuleti(k);
        cout<<sirAfisat<<"                 "<<"Cuvinte gresite introduse anterior: ";
        for(int l = 0; l<strlen(cuvinteGresiteFolosite); l++){
            cout<<cuvinteGresiteFolosite[l]<<", ";
        }
        cout<<endl;
    }
    if(k == 0){
      system("Color 4D");
      cout<<endl<<endl<<"AI PIERDUT"<<endl<<"Cuvantul era: "<<s<<endl<<endl;
      cout<<"Pentru a juca din nou introduceti valoarea 1, pentru a iesi valoarea 0"<<endl<<endl;
    }else{
      system("Color 2A");
      cout<<"\n\nFELICITARI!!!"<<endl<<endl<<"Pentru a juca din nou introduceti valoarea 1, pentru a iesi valoarea 0"<<endl<<endl;
    }
}

int main(){
    int n;
    AfisareTitlu();
    do{
      AfisareMeniu();
      AlegereDificultate(input);
      SelectareaDificultatii(input);
      cuvantAles = MorseToRo(cuvantAles, morseCode);
      GhicireCuvant(cuvantAles);
      cout<<"Valoarea: ";cin>>n;
      system("CLS");
    }while(n == 1);

    return 0;
}
