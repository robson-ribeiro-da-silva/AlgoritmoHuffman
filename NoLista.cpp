/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NoLista.cpp
 * Author: robso
 * 
 * Created on 10 de Abril de 2019, 14:43
 */
#include <iostream>
#include "NoLista.h"

using namespace std;

NoLista::NoLista() {
    this->proximo = nullptr;
}

NoLista::NoLista(NoArvore* noArvore){
    this->noArvore = noArvore;
    this->proximo = nullptr;
}

NoLista::NoLista(const NoLista& orig) {
}

NoLista::~NoLista() {
}

void NoLista::SetNoArvore(NoArvore* noArvore) {
    this->noArvore = noArvore;
}

NoLista* NoLista::GetProximo() const {
    return proximo;
}

void NoLista::SetProximo(NoLista* proximo) {
    this->proximo = proximo;
}

NoArvore* NoLista::GetNoArvore() const {
    return noArvore;
}

void NoLista::imprimir() {
    cout <<"No: "<< GetNoArvore()->GetChave() <<" "<< GetNoArvore()->GetFrequencia() <<endl<<endl;
}



