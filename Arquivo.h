/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arquivo.h
 * Author: robso
 *
 * Created on 4 de Abril de 2019, 20:17
 */
#include <cstdlib>
#include <stdio.h>
#include <iostream>

using namespace std;

#ifndef ARQUIVO_H
#define ARQUIVO_H

class Arquivo {   //classe arquivo
public:
    
    Arquivo();
    Arquivo(const Arquivo& orig);
    virtual ~Arquivo();
    string carregarArquivo(string arquivo);  //recebe o arquivo para leitura e estração do conteudo
    
private:
    

};

#endif /* ARQUIVO_H */

