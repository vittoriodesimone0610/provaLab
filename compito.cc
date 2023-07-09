#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;

#include "liste.h"

void leggi_riga(istream &is, char* line){
    while(is.peek() == '\n')
        is.get();
    
    is.get(line, 51);
    is.get();
}

//PUNTO 1
void agenda(lista &a, tipo_inf inf){
    if(search(a, inf) != NULL){
        cout<<"Non è possibile aggiungere l'appuntamento: ne esiste già per questa data e ora"<<endl;
        return;
    }
    else{
        elem* e = new_elem(inf);
        a = insert_elem(a, e);
    }
}

void stampa(lista agenda){

    while(agenda != NULL){
        print(head(agenda));
        cout<<endl;
        agenda = tail(agenda);
    }
}

//PUNTO 2a
void quanti(lista a, tipo_inf app){
    int p = 0;
    int d = 0;

    while(a != NULL){
        if(strcmp(app.data, head(a).data) == 0){
            if(strcmp(head(a).ora_i, app.ora_f) > 0){//l'appuntamento app cercato viene dopo
                d++;
            }
            else if(strcmp(head(a).ora_i, app.ora_f) < 0){
                p++;
            }
        }
        a = tail(a);
    }

    cout<<"Appuntamenti che precedono: "<<p<<endl;
    cout<<"Appuntamento che seguono: "<<d<<endl;
}

int main(){
    lista a = NULL;
    ifstream file("agenda.txt");
    tipo_inf appuntamento;
    /*file>>appuntamento.data;
    file>>appuntamento.ora_i;
    file>>appuntamento.ora_f;*/
    string firstRow, secondRow; 

    while(!file.eof()){
        
        getline(file, firstRow);
        
        istringstream iss(firstRow);
        iss>>appuntamento.data>>appuntamento.ora_i>>appuntamento.ora_f;

        //cout<<appuntamento.data<<endl;
        //file>>appuntamento.ora_i;
        
        //cout<<appuntamento.ora_i<<endl;
        //file>>appuntamento.ora_f;
        
        //cout<<appuntamento.ora_f<<endl;

        getline(file, secondRow);
        strcpy(appuntamento.descr, secondRow.c_str());

        /*cout<<"AAPPUNTAMENTO: ";
        cout<<appuntamento.descr<<endl;*/

        agenda(a, appuntamento);
    }
    file.close();

    cout<<"----PUNTO 1: STAMPA DELL'AGENDA: "<<endl;
    stampa(a);

    cout<<"----PUNTO 2"<<endl;
    tipo_inf app;
    cout<<"Inserisci la data dell'appuntamento da cercare"<<endl;
    cin>>app.data;
    cout<<"Inserisci l'ora inizio dell'appuntamento da cercare"<<endl;
    cin>>app.ora_i;
    cout<<"Inserisci l'ora di fine dell'appuntamento da cercare"<<endl;
    cin>>app.ora_f;
    cout<<"Inserisci la descrizione dell'appuntamento da cercare"<<endl;
    cin>>app.descr;
    quanti(a, app);

    return 0;
}