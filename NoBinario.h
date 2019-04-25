/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NoBinario.h
 * Author: robso
 *
 * Created on 17 de Abril de 2019, 09:27
 */

#ifndef NOBINARIO_H
#define NOBINARIO_H

#include <string>

using namespace std;

class NoBinario {   //No que recebera a chave e o binario, ou seja, o caracter e o binario correspondente
public:
    NoBinario();
    NoBinario(char chave, string binario);
    NoBinario(const NoBinario& orig);
    virtual ~NoBinario();
    
    string GetBinario() const;
    void SetBinario(string binario);
    char GetChave() const;
    void SetChave(char chave);

    
private:
    
    char chave;
    string binario;  //string que recebe a sequencia de binarios

};

#endif /* NOBINARIO_H */

