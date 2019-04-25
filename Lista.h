/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.h
 * Author: robso
 *
 * Created on 10 de Abril de 2019, 14:42
 */

#ifndef LISTA_H
#define LISTA_H

#include "NoLista.h"


class Lista {   //Lista encadeada com nó cabeça
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    
    int GetElementos() const;
    void SetElementos(int elementos);
    NoLista* GetNoCabeca() const;
    void SetNoCabeca(NoLista* noCabeca);
    
    void inserirNovo(NoLista *no);   //metodo pra inserir um nó na lista
    NoArvore *removeNoArvore();      //metodo pra remover um no da lista e retorna um nó do tipo No da arvore
    void imprimir();                 //imprimi a lista ordenada pela frequencia de cada caracter   

    
private:
    
    NoLista *noCabeca;
    int elementos;
};

#endif /* LISTA_H */

