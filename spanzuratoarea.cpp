#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

void afisareCuvant(char cuvant[])
{
    for(int i=0;i<strlen(cuvant);i++)
        cout<<cuvant[i]<<" ";
    cout<<endl;
}

bool testareLitera(char cuvant[],char cuvantCurent[],char lit)
{
    bool literaBuna = true;
    for(int i=0;i<strlen(cuvant);i++)
        if(cuvant[i] == lit)
        {
            cuvantCurent[i] = lit;
            literaBuna = false;
        }
    return literaBuna;
}

int main(void)
{
    ifstream f;
    char cuv[50];
    char *cuvantCurent;
    int nr_cuvinte = 0;
    f.open("cuvinte.txt");
    if(f == NULL)
    {
        cout<<"Fisierul cu cuvinte nu a putut fi deschis"<<endl;
    }
    f.getline(cuv,50);
    nr_cuvinte = atoi(cuv);
    srand(time(NULL));
    int nr_linie = rand() % nr_cuvinte + 1;
    for(int i=0;i<nr_linie;i++)
    {
        f.getline(cuv,50);
    }

    int lungime_cuvant = strlen(cuv);
    cuvantCurent = (char*)malloc(lungime_cuvant*sizeof(char));
    for(int i=0;i<lungime_cuvant;i++)
        cuvantCurent[i] = '_';

    bool gameOn = true;
    char lit;
    int greseli = 0;
    char *litere = NULL;
    int incercari = 0;

    while(gameOn)
    {
        system("cls");
        afisareCuvant(cuvantCurent);
        cout<<"Litere folosite:";
        for(int i=0;i<incercari;i++)
            cout<<litere[i]<<",";
        cout<<endl;
        cout<<"Greseli: "<<greseli<<endl;
        cout<<"Introduceti o litera:"; cin>>lit;
        incercari ++ ;
        litere = (char*) realloc(litere,incercari*sizeof(char));
        litere[incercari -1] = lit;
        if(testareLitera(cuv,cuvantCurent,lit))
        {
            greseli++;
            if(greseli >= 5)
            {
                system("cls");
                afisareCuvant(cuvantCurent);
                cout<<"Litere folosite:";
                for(int i=0;i<incercari;i++)
                    cout<<litere[i]<<",";
                cout<<endl;
                cout<<"Greseli: "<<greseli<<endl;
                SetConsoleTextAttribute(hConsole, 12);
                cout<<"Ati depasit numarul de greseli permise!"<<endl;
                SetConsoleTextAttribute(hConsole, 7);
                cout<<"Cuvantul corect era "<<cuv<<endl;
                gameOn = false;
            }
        }
        else if(strcmp(cuv,cuvantCurent) == 0)
        {
            system("cls");
            afisareCuvant(cuvantCurent);
            cout<<"Litere folosite:";
            for(int i=0;i<incercari;i++)
                cout<<litere[i]<<",";
            cout<<endl;
            cout<<"Greseli: "<<greseli<<endl;
            SetConsoleTextAttribute(hConsole, 10);
            cout<<"Felicitari! Ati castigat"<<endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout<<"Cuvantul corect era "<<cuv<<endl;
            gameOn = false;
        }
    }
    Sleep(10000);
    return 0;
}
