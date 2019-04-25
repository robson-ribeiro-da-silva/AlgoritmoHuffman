/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NoFreq.cpp
 * Author: robso
 * 
 * Created on 6 de Abril de 2019, 10:58
 */

#include "NoFreq.h"

NoFreq::NoFreq() {
}

NoFreq::NoFreq(char chave, int posicao, int frequencia){
    this->chave = chave;
    this->posicao = posicao;
    this->frequencia = frequencia;
}

NoFreq::NoFreq(const NoFreq& orig) {
}

NoFreq::~NoFreq() {
    this->chave = 0;
    this->posicao = 0;
    this->frequencia = 0;
}

char NoFreq::GetChave() const {
    return chave;
}

void NoFreq::SetChave(char chave) {
    this->chave = chave;
}

int NoFreq::GetFrequencia() const {
    return frequencia;
}

void NoFreq::SetFrequencia(int frequencia) {
    this->frequencia = frequencia;
}

int NoFreq::GetPosicao() const {
    return posicao;
}

void NoFreq::SetPosicao(int posicao) {
    this->posicao = posicao;
}

