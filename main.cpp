//COMPITO DI NATALE 2021-2022 Ulivi Samuel 3F

#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <time.h>

using namespace std;

HANDLE colore = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

void crea_mondo(bool mondo [20][20], short &censimento, short &gen){ //Genera casualmente delle "vite" (ed esegue un censimento) per creare il
                                        //mondo, è impostato in modo che ci siano molte più
    short mem;                           //probabilità di celle spente che accese

    gen++; //prima generazione

    for(short i=0;i<20;i++){
        for(short j=0;j<20;j++){
            mem=rand()%5+1;
            if(mem==1){
                    mondo [i][j]=true;
                    censimento++; //aumento conteggio vite
            } else mondo [i][j]=false;
        }
    }
}

void mostra_mondo(bool mondo [20][20]){ //visualizza la griglia

    SetConsoleCursorPosition(output, {3, 4}); //Cornice alta
    SetConsoleTextAttribute(colore, 255);
    for(short i=0;i<60;i++) cout<<"*";
    SetConsoleTextAttribute(colore, 7);

    for(short i=0;i<22;i++){                            //cornice sinistra
        SetConsoleCursorPosition(output, {2, 4+i});
        SetConsoleTextAttribute(colore, 255);
        cout<<"*";
        SetConsoleTextAttribute(colore, 7);
    }

    for(short i=0;i<22;i++){                            //cornice destra
        SetConsoleCursorPosition(output, {63, 4+i});
        SetConsoleTextAttribute(colore, 255);
        cout<<"*";
        SetConsoleTextAttribute(colore, 7);
    }

    for(short i=0;i<20;i++){                            //visualizza tabella
        SetConsoleCursorPosition(output, {3, 5+i});
        for(short j=0;j<20;j++) {
                if(mondo[i][j]) SetConsoleTextAttribute(colore, 170);
                cout<<"[ ]";
                SetConsoleTextAttribute(colore, 7);
        }
    }

    SetConsoleCursorPosition(output, {3, 25}); //Cornice bassa
    SetConsoleTextAttribute(colore, 255);
    for(short i=0;i<60;i++) cout<<"*";
    SetConsoleTextAttribute(colore, 7);
}

void titolo(){ //visualizza il titolo
    SetConsoleCursorPosition(output, {40, 1});
    SetConsoleTextAttribute(colore, 240);
    cout<<"IL GIOCO DELLA VITA DI CONWAY";
    SetConsoleTextAttribute(colore, 7);
}

void generazioni(bool mondo [20][20], short &contaGen, short &contaVite){ //creazione delle generazioni e conta di esse e delle vite

    short conta; //usata per contare vite adiacenti
    bool newGen[20][20]; //memoria nuova generazione

    contaGen++; //aumento il contatore delle generazioni

    for(short i=0;i<20;i++){ //analisi della matrice punto per punto
        for(short j=0;j<20;j++){
            conta=0;


            if(i==0 && j==0){ //se si tratta del punto 0,0


                for(short a=0;a<2;a++){ //analisi del blocco intorno all'elemento
                    if(mondo[1][a]) conta++; //parte bassa
                }


                if(mondo[0][1]) conta++;//analisi del blocco intorno all' elemento
                                        //a destra
            } else {


                if(i==0 && j==19){ //se si tratta del punto 0,9


                    for(short a=18;a<20;a++){ //analisi del blocco intorno all'elemento
                        if(mondo[1][a]) conta++; //parte bassa
                    }


                    if(mondo[0][18]) conta++;//analisi del blocco intorno all' elemento
                                            //a sinistra
                } else {


                    if(i==19 && j==0){ //se si tratta del punto 9,0


                        for(short a=0;a<2;a++){ //analisi del blocco intorno all'
                            if(mondo[18][a]) conta++; //elemento parte alta
                        }
                                                //analisi del blocco intorno all'elemento
                        if(mondo[19][1]) conta++;//a destra


                    } else {


                        if(i==19 && j==19){ //se si tratta del punto 9,9


                            for(short a=18;a<20;a++){ //analisi del blocco intorno all'
                                if(mondo[18][a]) conta++; //elemento parte alta
                            }
                                                //analisi del blocco intorno all'elemento
                            if(mondo[19][18]) conta++;//a sinistra


                        } else {


                            if(i==0){


                                for(short a=j-1;a<j+2;a++){ //analisi del blocco elemento
                                    if(mondo[i+1][a]) conta++; //parte bassa
                                }


                                for(short a=j-1;a<j+2;a=a+2){ //analisi del blocco intorno                            //all' elemento
                                    if(mondo[i][a]) conta++;//a sinistra e a destra
                                }


                            } else {


                                if(i==19){


                                    for(short a=j-1;a<j+2;a++){ //analisi del blocco                                //intorno all'
                                        if(mondo[i-1][a]) conta++; //elemento parte alta
                                    }


                                    for(short a=j-1;a<j+2;a=a+2){ //analisi del blocco                                //intorno all' elemento
                                        if(mondo[i][a]) conta++;//a sinistra e a destra
                                    }


                                } else {


                                    if(j==0){


                                        for(short a=j;a<j+2;a++){ //analisi del blocco
                                            if(mondo[i-1][a]) conta++; //elemento parte alta
                                            if(mondo[i+1][a]) conta++; //e bassa
                                        }


                                        //analisi del blocco intorno all' elemento
                                        if(mondo[i][j+1]) conta++;//a destra


                                    } else {


                                        if(j==19){


                                            for(short a=j-1;a<j+1;a++){ //analisi del blocco
                                                if(mondo[i-1][a]) conta++; //elemento parte
                                                if(mondo[i+1][a]) conta++; //alta e bassa
                                            }


                                            //analisi del blocco intorno all' elemento
                                            if(mondo[i][j-1]) conta++;//a sinistra


                                        } else {


                                            for(short a=j-1;a<j+2;a++){ //analisi del //blocco intorno all'
                                                if(mondo[i-1][a]) conta++; //elemento parte //alta
                                                if(mondo[i+1][a]) conta++; //e bassa
                                            }


                                            for(short a=j-1;a<j+2;a=a+2){ //analisi del //blocco intorno all' elemento
                                                if(mondo[i][a]) conta++;//a sinistra e
                                                //destra
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(mondo[i][j]){ //controllo se è vivo o no e cambio valori
                if(conta<2 || conta>3) newGen[i][j]=false;
                else {
                        newGen[i][j]=true;
                        contaVite++; //aumento conteggio vite
                }
            } else {
                if(conta==3){
                        newGen[i][j]=true;
                        contaVite++; //aumento conteggio vite
                } else newGen[i][j]=false;
            }
        }
    }


    for(short i=0;i<20;i++){ //trasferisco vaori nuova gen a mondo
        for(short j=0;j<20;j++) mondo[i][j]=newGen[i][j];
    }
}

void cornice_menu(){ //visualizza cornice menu

    SetConsoleCursorPosition(output, {70, 4}); //cornice menu parte alta
    for(short i=0;i<22;i++) cout<<"+ ";

    for(short i=5;i<25;i++){ //cornice menu sinistra
            SetConsoleCursorPosition(output, {70, i});
            cout<<"+";
    }

    SetConsoleCursorPosition(output, {70, 25}); //cornice menu parte bassa
    for(short i=0;i<22;i++) cout<<"+ ";

    for(short i=5;i<25;i++){ //cornice menu destra
            SetConsoleCursorPosition(output, {112, i});
            cout<<"+";
    }

    SetConsoleCursorPosition(output, {70, 7}); //cornice menu contatore parte bassa
    for(short i=0;i<22;i++) cout<<"+ ";
}

void visualizza_conteggi(short contGen, short contVite){ //visualizzo conteggi di vita e generazione

    SetConsoleCursorPosition(output, {72, 5});
    cout<<"Generazione numero: "<<contGen;

    SetConsoleCursorPosition(output, {72, 6});
    cout<<"Vite totali: "<<contVite;
}

void menu(){ //visualizza menu

    SetConsoleCursorPosition(output, {72, 8});
    cout<<"Regole: ";
    SetConsoleCursorPosition(output, {72, 9});
    cout<<"1. E' un gioco 'senza utente'.";
    SetConsoleCursorPosition(output, {72, 10});
    cout<<"2. Bisogna solamente osservare.";
    SetConsoleCursorPosition(output, {72, 12});
    cout<<"Per capire la logica che adotta il";
    SetConsoleCursorPosition(output, {72, 13});
    cout<<"gioco della vita di Conway leggere l'";
    SetConsoleCursorPosition(output, {72, 14});
    cout<<"articolo su:";
    SetConsoleCursorPosition(output, {72, 15});
    cout<<"https://tinyurl.com/ycy6erpj";
    SetConsoleCursorPosition(output, {72, 17});
    cout<<"Il gioco finisce quando muoiono tutti o";
    SetConsoleCursorPosition(output, {72, 18});
    cout<<"quando si crea una stabilita' o quando";
    SetConsoleCursorPosition(output, {72, 19});
    cout<<"si raggiunge la generazione 300.";
    SetConsoleCursorPosition(output, {72, 21});
    system("PAUSE");
    for(short i=72;i<109;i++){
        SetConsoleCursorPosition(output, {i, 21});
        cout<<" ";
    }
}

void memorizzaS_mondo(bool mondo [20][20], bool memMondo [20][20]){ //memorizza mondo

    for(short i=0;i<20;i++){ //trasferisco valori nuova gen a mondo
        for(short j=0;j<20;j++) memMondo[i][j]=mondo[i][j];
    }
}

bool stabilita_mondo(bool mondo [20][20], bool memMondo [20][20]){ //verifica stabilità e periodicità

    short conta=0;
    bool verifica;

    for(short i=0;i<20;i++){ //trasferisco vaori nuova gen a mondo
        for(short j=0;j<20;j++){
            if(memMondo[i][j]==mondo[i][j]) conta++;
            else break;
        }
    }

    if(conta==400){
        verifica=false;
        return verifica;
    }
}

int main() {

    bool mondo [20][20]={false};
    bool memMondoS[20][20]; //memorizzazione del mondo in caso di situazione stabile
    bool continua=true;
    short nGen=0;
    short nVite=0;

    srand(time(0));

    titolo(); //mostro menu iniziale con mondo vuoto
    mostra_mondo(mondo);
    cornice_menu();
    visualizza_conteggi(nGen, nVite);
    menu();

    crea_mondo(mondo, nVite, nGen); //creo il mondo e lo visualizzo aggiornando i conteggi
    mostra_mondo(mondo);
    visualizza_conteggi(nGen, nVite);
    sleep(0.5);

    while(continua){ //creo generazioni e mi fermo se ho tutti gli elementi morti o una situaszione stabile o periodica
        nVite=0;
        memorizzaS_mondo(mondo, memMondoS);
        generazioni(mondo, nGen, nVite);
        mostra_mondo(mondo);
        visualizza_conteggi(nGen, nVite);
        sleep(0.5);

        continua=stabilita_mondo(mondo, memMondoS);
        if(nVite==0) continua=false;
        if(nGen==300) continua=false;
    }

    SetConsoleCursorPosition(output, {72, 21});
    system("PAUSE");
    system("CLS");

    return 0;
}
