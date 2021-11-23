#include <iostream>
#include<fstream>
using namespace std;


int codice=11,password=23,scelta;
int conto_corrente=0,pin=2323,pin_input,prel,carta_bonifico,importo,eta,d_n,e,d,cod,somma_input;
int anno_corrente=2021;

string nome,cognome,n,c;


void saldo(int conto_corrente){
    cout<<"il tuo saldo e di "<<conto_corrente<<" euro"<<endl;
}

int versamento(int conto_corrente){
    
    
    cout<<"Depositare somma versamento"<<endl;
    cin>>somma_input;
    
    return somma_input+conto_corrente;
}

int controllo(int pin,int pin_input,int conto_corrente){
    if(pin_input==pin){
        return true;
    }
    else{
        return false;
    }
}


int prelievo(int conto_corrente,int prel){
    
    
    if(conto_corrente>prel){
        return conto_corrente-prel;
    }
    else{
        cout<<endl;
        cout<<"errore nel tentativo di prelevare il denaro"<<endl;
        return conto_corrente;
    }

    
}



int bonifico(int pin,int conto_corrente,int importo){
    
    return conto_corrente-importo;


}


void stampa_proprietario(string n,string c,int e,int d,int conto_corrente){
    

    
    cout<<"-----------------ELEMENTI PROPRIETARIO CARTA----------------"<<endl;
    cout<<endl;
    cout<<"NOME: "<<n<<endl;
    cout<<"COGNOME: "<<c<<endl;
    cout<<"DATA NASCITA: "<<d<<endl;
    cout<<"ETA: "<<e<<endl;
    cout<<"SALDO DISPONIBILE: "<<conto_corrente<<endl;
    
    cout<<endl;
    
    
}


void sezione_password(int password,int pin,int pin_input,string n,int codice){
    
    do{
        cout<<"----------------LOGIN CARTA DI CREDITO-------------------------"<<endl;
        cout<<"inserire codice_carta"<<endl;
        cin>>codice;
        cout<<"inserisci password"<<endl;
        cin>>password;
    }
    while(codice!=11 || password!=2323);
    
    cout<<"inserisci il pin della carta"<<endl;
    cin>>pin_input;
    if(controllo(pin,pin_input,conto_corrente)==true){
        
        cout<<endl;
        
        cout<<"-----------------SEZIONE PASSWORD-------------------"<<endl;
        cout<<"NOME: "<<n<<endl;
        cout<<"NUMERO CARTA: "<<codice<<endl;
        cout<<"PASSWORD: "<<password<<endl;
        cout<<"PIN CARTA: "<<pin<<endl;
        
    }
    cout<<endl;

}





int impostazioni_della_carta(int conto_corrente,int pin,int pin_input){
    
    int sc;
    do{
    cout<<"--------------IMPOSTAZIONI DELLA CARTA----------------"<<endl;
    cout<<"1)Cambia Pin"<<endl;
    cout<<"2)Bonifico"<<endl;
    cout<<"5)Sezione Password"<<endl;
    cout<<"0)Esci dalla modalità impostazioni della carta"<<endl;
    cin>>sc;
    
    switch(sc){
        case 1:
            do{
        cout<<"----------------LOGIN CARTA DI CREDITO-------------------------"<<endl;
                cout<<"inserire codice_carta"<<endl;
                cin>>codice;
                cout<<"inserisci password"<<endl;
                cin>>password;
            }
            while(codice!=11 || password!=2323);
            cout<<"inserisci pin carta"<<endl;
            cin>>pin_input;
            if(controllo(pin,pin_input,conto_corrente)==true){
                cout<<"inserisci nuovo pin"<<endl;
                cin>>pin;
            }
            
            break;
        case 2:
            cout<<"inserisci l'iban della carta"<<endl;
            cin>>carta_bonifico;
            
            cout<<"inserisci il pin della carta"<<endl;
            cin>>pin_input;
            if(controllo(pin,pin_input,conto_corrente)==true){
                cout<<"inserisci importo da consegnare"<<endl;
                cin>>importo;
          
            bonifico(pin, conto_corrente,importo);
            }
            else{
                cout<<"errore nella riuscita dell'operazione;"<<endl;
            }
            break;
        case 0:
            cout<<"si desidera uscire dalla modalità impostazioni? 0:SI  1:NO"<<endl;
            cin>>sc;
           
            break;
        case 5:
            sezione_password(password,pin,pin_input,n,codice);
            break;
        default:
        cout<<"errore nella scelta"<<endl;
    }
        

    }
    while(sc!=0);
    return pin;
}



int calcola_eta(int anno_corrente,int d_n){
    return anno_corrente-d_n;
}


void scambio(string nome,string cognome,int eta,int d_n){

    
    n=nome;
    c=cognome;
    e=calcola_eta(anno_corrente,d_n);
    d=d_n;
    
}



void caricamento(string nome,string cognome,int eta,int d_n){
    
    cout<<"Nome"<<endl;
    cin>>nome;
    cout<<"Cognome"<<endl;
    cin>>cognome;
    //cout<<"ETA"<<endl;
    //cin>>eta;
    cout<<"Data Nascita"<<endl;
    cin>>d_n;
    
    
    scambio(nome,cognome,eta,d_n);
    
    //stampa_proprietario(n,c,cogn,e,d);
    
}



int main(){
    
    
    do{
        
        cout<<endl;
        cout<<endl;
        
        cout<<"----------------LOGIN CARTA DI CREDITO-------------------------"<<endl;
        cout<<"inserire codice_carta"<<endl;
        cin>>codice;
        cout<<"inserisci password"<<endl;
        cin>>password;
    }
    while(codice!=11 || password!=2323);
    
    cout<<"CARICAMENTO DATI UTENTE: "<<endl;
    
    caricamento(nome,cognome,eta,d_n);
    
    cout<<endl;
    
    
    
    do{
        
       
        
        cout<<endl;
    
    cout<<"-----------MENU--------------"<<endl;
    cout<<"1)Saldo"<<endl;
        cout<<endl;
    cout<<"2)Versamento"<<endl;
        cout<<endl;
    cout<<"3)Prelievo"<<endl;
        cout<<endl;
    cout<<"4)impostazioni della carta"<<endl;
        cout<<endl;
    cout<<"0)ESCI"<<endl;
        cout<<endl;
        
      
        stampa_proprietario(n,c,e,d,conto_corrente);
        
        
        cout<<endl;
        
    cout<<"scelta"<<endl;
    cin>>scelta;
        cout<<endl;
        
    switch(scelta){
        case 1:
            saldo(conto_corrente);
            break;
        case 2:
            cout<<"inserisci codice pin della carta"<<endl;
            cin>>pin_input;
            
            if(controllo(pin,pin_input,conto_corrente)==true){
                conto_corrente=versamento(conto_corrente);
                cout<<"Somma Depositata";
            }
            else{
                cout<<"errore nel versamento della somma"<<endl;
            }
            break;
        case 3:
            cout<<"inserire importo da prelevare"<<endl;
            cin>>prel;
            cout<<"inserisci codice pin della carta"<<endl;
            cin>>pin_input;
            
            if(controllo(pin,pin_input,conto_corrente)==true){
                conto_corrente=prelievo(conto_corrente,prel);
            }
            else{
                cout<<"errore pin errato"<<endl;
            }
            
            break;
        case 4:
            pin=impostazioni_della_carta(conto_corrente, pin, pin_input);
            conto_corrente=bonifico(pin,conto_corrente,importo);
            break;
        case 0:
            scelta=0;
            break;
        default:
            cout<<"errore"<<endl;
    }
        
    }
    
    
   
    

    
    while(scelta!=0);
    
    cout<<"Grazie ed Arrivederci!"<<endl;
    
    cout<<endl;
        
    
  
    
}






