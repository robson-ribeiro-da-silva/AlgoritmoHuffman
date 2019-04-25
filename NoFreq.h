/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NoFreq.h
 * Author: robso
 *
 * Created on 6 de Abril de 2019, 10:58
 */

#ifndef NOFREQ_H
#define NOFREQ_H

class NoFreq {     //No responsavel por por receber a chave, a frequencia e a posicao de cada caracter
public:
    NoFreq(char chave, int posicao, int frequencia);
    NoFreq();
    NoFreq(const NoFreq& orig);
    virtual ~NoFreq();
    char GetChave() const;
    void SetChave(char chave);
    int GetFrequencia() const;
    void SetFrequencia(int frequencia);
    int GetPosicao() const;
    void SetPosicao(int posicao);

private:
    
    char chave;
    int posicao;        //posicao que o caracter é inserido no vetor do tipo NoFreq, ou seja, a posicao correspode ao valor do caracter na tabela Ascii
    int frequencia;     //conta a frequencia do caracter, quantas vezes se repete
};

#endif /* NOFREQ_H */

