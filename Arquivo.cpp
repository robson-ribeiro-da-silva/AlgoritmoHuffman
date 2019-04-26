/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arquivo.cpp
 * Author: robso
 * 
 * Created on 4 de Abril de 2019, 20:17
 */
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>


#include "Arquivo.h"

using namespace std;

Arquivo::Arquivo() {
}

Arquivo::Arquivo(const Arquivo& orig) {
}

Arquivo::~Arquivo() {
}

string Arquivo::carregarArquivo(string arquivo) {   //abre o arquivo e extrai o conteudo, retornando-o em uma string concatenada
    
    ifstream leitura;
    leitura.open(arquivo);
    stringstream saida;
    
    if(leitura.is_open() && leitura.good()){
        
        if(leitura.is_open()){
            while(!leitura.eof()){
                string l;
                leitura >> l;
                saida << l+" ";
            }
        }

        string s = saida.str();
        
        leitura.close();
    }
    return saida.str();
}



