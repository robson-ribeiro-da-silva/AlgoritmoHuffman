/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NoArvore.h
 * Author: robso
 *
 * Created on 10 de Abril de 2019, 14:47
 */

#ifndef NOARVORE_H
#define NOARVORE_H


#include "NoFreq.h"


class NoArvore {   //No da arvore, contem uma chave que é o caracter, a sua frequencia, o ponteiro esquerdo e direito
public:
    
    NoArvore();
    NoArvore(int freq, char chave);
    NoArvore(int freq, char chave, NoArvore *esq, NoArvore *dir);
    NoArvore(const NoArvore& orig);
    virtual ~NoArvore();
    
    NoArvore* GetDireito() const;
    void SetDireito(NoArvore* direito);
    NoArvore* GetEsquerdo() const;
    void SetEsquerdo(NoArvore* esquerdo);
    char GetChave() const;
    void SetChave(char chave);
    int GetFrequencia() const;
    void SetFrequencia(int frequencia);
    
private:
    
    int frequencia;
    char chave;
    NoArvore *esquerdo;
    NoArvore *direito;
    

};

#endif /* NOARVORE_H */

