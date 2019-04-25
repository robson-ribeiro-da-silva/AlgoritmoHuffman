/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NoLista.h
 * Author: robso
 *
 * Created on 10 de Abril de 2019, 14:43
 */

#ifndef NOLISTA_H
#define NOLISTA_H

#include "NoArvore.h"

class NoLista {   //No da lista encadeada
public:
    NoLista();
    NoLista(NoArvore *noArvore);
    NoLista(const NoLista& orig);
    virtual ~NoLista();

    NoArvore* GetNoArvore() const;
    void SetNoArvore(NoArvore* noArvore);
    NoLista* GetProximo() const;
    void SetProximo(NoLista* proximo);

    void imprimir();
    
private:
    
    NoArvore *noArvore;  //recebe um no do tipo arvore
    NoLista *proximo;

};

#endif /* NOLISTA_H */

