/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NoBinario.cpp
 * Author: robso
 * 
 * Created on 17 de Abril de 2019, 09:27
 */
#include <string>
#include <iostream>

#include "NoBinario.h"

using namespace std;

NoBinario::NoBinario() {
}

NoBinario::NoBinario(char chave, string binario) {
    this->chave = chave;
    this->binario = binario;
}

NoBinario::NoBinario(const NoBinario& orig) {
}

NoBinario::~NoBinario() {
}

string NoBinario::GetBinario() const {
    return binario;
}

void NoBinario::SetBinario(string binario) {
    this->binario = binario;
}

char NoBinario::GetChave() const {
    return chave;
}

void NoBinario::SetChave(char chave) {
    this->chave = chave;
}

