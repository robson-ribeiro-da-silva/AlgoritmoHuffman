/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.cpp
 * Author: robso
 * 
 * Created on 10 de Abril de 2019, 14:42
 */

#include <iostream>
#include "Lista.h"

using namespace std;

Lista::Lista() {
    this->noCabeca = new NoLista();    
    //this->noCabeca->SetProximo(noCabeca);
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
}

int Lista::GetElementos() const {
    return elementos;
}

void Lista::SetElementos(int elementos) {
    this->elementos = elementos;
}

NoLista* Lista::GetNoCabeca() const {
    return noCabeca;
}

void Lista::SetNoCabeca(NoLista *noCabeca) {
    this->noCabeca = noCabeca;
}

void Lista::inserirNovo(NoLista *no) {  //função de inserir na lista encadeada de forma ordenada
   
    if(noCabeca->GetProximo() == nullptr){
        noCabeca->SetProximo(no);        
    }
    else if(no->GetNoArvore()->GetFrequencia() < noCabeca->GetProximo()->GetNoArvore()->GetFrequencia()){
        NoLista *aux;
        aux = noCabeca->GetProximo();
        //no->SetProximo(aux);
        noCabeca->SetProximo(no);
        no->SetProximo(aux);
                
    }else{
        NoLista *aux1 = noCabeca->GetProximo()->GetProximo();
        NoLista *aux2 = noCabeca->GetProximo();
        
        if(aux1 == nullptr){
            aux2->SetProximo(no);
        }else{        
            while(aux1 != nullptr && aux1->GetNoArvore()->GetFrequencia() <= no->GetNoArvore()->GetFrequencia()){
                aux2 = aux1;
                aux1 = aux2->GetProximo();
            }

            aux2->SetProximo(no);
            no->SetProximo(aux1);
        }
    }
    elementos++;
}

NoArvore* Lista::removeNoArvore() {  //remove elemento da lista e retorna um NoArvore
    
    NoLista *auxL = noCabeca->GetProximo();
    NoArvore *auxA = auxL->GetNoArvore();
    
    noCabeca->SetProximo(auxL->GetProximo());
    
    delete auxL;
    auxL = nullptr;
    
    elementos --;
    
    return auxA;
}


void Lista::imprimir() {  //imprimi a lista ordenada
    NoLista *aux = noCabeca->GetProximo();
    cout <<" Lista "<<endl;
    if(aux != nullptr){
        while(aux != nullptr){
            cout <<" Chave: "<< aux->GetNoArvore()->GetChave() << " "<< aux->GetNoArvore()->GetFrequencia() <<endl;
            aux = aux->GetProximo();
        }
    }else{
        cout << " Lista Vazia! "<<endl;
    }
}

