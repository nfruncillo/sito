#include <iostream>
using namespace std;


void caricamento(float vettore[],int dimensione){
    for (int i=0;i<dimensione;i++) {
        cout<<"inserisci"<<endl;
        cin>>vettore[i];
    }
}

void visualizza(float vettore[],int dimensione){
    
    cout<<"-----------VETTORE-------------"<<endl;
    
    for(int i=0;i<dimensione;i++){
        cout<<endl;
        cout<<endl;
        cout<<vettore[i]<<endl;
    }
}

float media(float vettore[],int dimensione){
    float somma=0;
    for(int i=0;i<dimensione;i++){
        somma=somma+vettore[i];
    }
    return somma/dimensione;
}

void ordinamento(float vettore[],int dimensione){
    float app;
    for(int i=0;i<dimensione-1;i++){
        for(int j=i+1;j<dimensione;j++){
            if(vettore[j]<vettore[i]){
            app=vettore[j];
            vettore[j]=vettore[i];
            vettore[i]=app;
            }
            
        }
    }
  
}


void ordinamento_dec(float vettore[],int dimensione){
    float app;
    for(int i=0;i<dimensione-1;i++){
        for(int j=i+1;j<dimensione;j++){
            if(vettore[j]>vettore[i]){
            app=vettore[j];
            vettore[j]=vettore[i];
            vettore[i]=app;
            }
            
        }
    }
  
}


void visualizza_media(float vettore[],int dimensione,float med){
    cout<<"la media e: "<<med<<endl;
}


float somma_elementi(float vettore[],int dimensione){
    int somma=0;
    for(int i=0;i<dimensione;i++){
        somma=somma+vettore[i];
    }
    return somma;
}

int  main(){
    int dimensione,scelta=0,s=0;
    
    cout<<"inserisci dimensione"<<endl;
    cin>>dimensione;
    
    float vettore[dimensione],med;
    
    do{
    
    cout<<"-----------MENU--------------"<<endl;
    cout<<"1)Carica vettore"<<endl;
    cout<<"2)Media"<<endl;
    cout<<"3)Somma Elementi"<<endl;
    cout<<"4)ordina CRESCENTE"<<endl;
    cout<<"5)ordina DECRESCENTE"<<endl;
    cout<<"6)visualizza"<<endl;
    cout<<"0)termina"<<endl;
            
    cout<<"operazione"<<endl;
    cin>>scelta;
    
    switch(scelta){
            
        case 1:
            caricamento(vettore,dimensione);
            break;
        case 2:
            med=media(vettore,dimensione);
            
            visualizza_media(vettore,dimensione,med);
            break;
        case 3:
            s=somma_elementi(vettore,dimensione);
            cout<<"la somma degli elementi del vettore e: "<<s<<endl;
            break;
        case 4:
            ordinamento(vettore,dimensione);
            break;
            
        case 5:
            ordinamento_dec(vettore,dimensione);
            break;
        
        case 6:
            visualizza(vettore,dimensione);
            break;
        case 0:
            return 0;
        default:
            cout<<"errore"<<endl;
    

    }
    }
    while (scelta!=0);
    
}

