/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NoArvore.cpp
 * Author: robso
 * 
 * Created on 10 de Abril de 2019, 14:47
 */

#include "NoArvore.h"

NoArvore::NoArvore(){
    this->frequencia = 0;
    this->chave = 0;
    this->esquerdo = nullptr;
    this->direito = nullptr;
}

NoArvore::NoArvore(int freq, char chave) {
    this->frequencia = freq;
    this->chave = chave;
    this->esquerdo = nullptr;
    this->direito = nullptr;
}

NoArvore::NoArvore(int freq, char chave, NoArvore* esq, NoArvore* dir){
    this->frequencia = freq;
    this->chave = chave;
    this->esquerdo = esq;
    this->direito = dir;
    
}

NoArvore::NoArvore(const NoArvore& orig) {
}

NoArvore::~NoArvore() {
}

NoArvore* NoArvore::GetDireito() const {
    return direito;
}

void NoArvore::SetDireito(NoArvore* direito) {
    this->direito = direito;
}

NoArvore* NoArvore::GetEsquerdo() const {
    return esquerdo;
}

void NoArvore::SetEsquerdo(NoArvore* esquerdo) {
    this->esquerdo = esquerdo;
}

char NoArvore::GetChave() const {
    return chave;
}

void NoArvore::SetChave(char chave) {
    this->chave = chave;
}

int NoArvore::GetFrequencia() const {
    return frequencia;
}

void NoArvore::SetFrequencia(int frequencia) {
    this->frequencia = frequencia;
}

