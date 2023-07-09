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

    cout<<"PUNTO 1: STAMPA DELL'AGENDA: "<<endl;
    stampa(a);

    return 0;
}