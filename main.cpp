/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: robso
 *
 * Created on 4 de Abril de 2019, 20:17
 */

#include "Core.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    //Core core;                      //cria objeto do tipo core
    //core.iniciar("arquivo1.txt");
    
    cout<<" ----- ALGORITMO DE HUFFMAN ------- "<<endl;
    cout<<" Compactação de Arquivo de Texto "<<endl;
    
    Core core;                      //cria objeto do tipo core
    
   
    int opcao = 0;
    bool op = true;
    
    
    cout<<endl;
    while(op){
    
        cout<<"\n INFORME O ARQUIVO DESEJADO! "<<endl;
        cout<<" 1 - Arquivo-1 \n 2 - Arquivo-2 \n 3 - Arquivo-3 \n 0 - Sair "<<endl;
        cout<<" Digite a opção: ";
        cin >> opcao;

        switch(opcao){
            
            case 0:
                cout<<"\n Saindo... "<<endl;
                op = false;
                break;

            case 1:
                
                cout<<"\n Arquivo 1 Selecionado! \n"<<endl;
        
                core.iniciar("arquivo1.txt");
                //op = false;
                break;

            case 2:
                cout<<"\n Arquivo 2 Selecionado! \n"<<endl;
               
                core.iniciar("arquivo2.txt");
                //op = false;
                break;

            case 3:
                cout<<"\n Arquivo 3 Selecionado! \n"<<endl;
                
                core.iniciar("arquivo3.txt");
                //op = false;
                break;

            default:
                cout<<"\n Opção inválida! \n"<<endl;
        }
    }
    cout<<endl; 
    return 0;
}

