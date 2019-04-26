/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arvore.h
 * Author: robso
 *
 * Created on 10 de Abril de 2019, 15:55
 */

#ifndef ARVORE_H
#define ARVORE_H

#include <cstddef>
#include <string>
#include <iostream>

#include "NoArvore.h"
#include "Lista.h"


using namespace std;

class Arvore {    //classe arvore
public:
    Arvore();
    Arvore(Lista *lista);       //recebe um objeto do tipo lista no construtor
    Arvore(const Arvore& orig);
    virtual ~Arvore();
    
    Lista* GetLista() const;
    void SetLista(Lista* lista);
    NoArvore* GetRaiz() const;
    void SetRaiz(NoArvore* raiz);    
    int GetI() const;
    void SetI(int i);

    
    bool isfolha(NoArvore *no);  //verifica se o no atual é folha = se os ponteiros esquerdo e direito são nulo
   
    void arvoreHuffman();       //metodo principal da classe
    void gerarTabela(NoArvore *no, string s);  //gera a tabela, ou seja conta o caminho até cada folha
    void imprimirTabela();      //imprimi a tabela com o caracter e o binario correspondente, escreve no arquivo
    void compactador(char lista[], int t);   //gera a sequencia de binarios correspondente ao texto
    void liberarMemoria(NoArvore *no);      //libera a memoria ocupada pela arvore
    
    //SEGUNDA OPÇÃO
    void gerarTabela2(NoArvore *no, string s);  //gera a tabela, ou seja conta o caminho até cada folha
    void imprimirTabela2();      //imprimi a tabela com o caracter e o binario correspondente, escreve no arquivo
    void compactador2(char lista[], int t);   //gera a sequencia de binarios correspondente ao texto
    
    void percentualCompactacao(int tamanho);  //funçao que calcula o percentual 
    
    void preOrdem(NoArvore *no);  //percurso pre-ordem apartir da raiz
    void imprimirListaBinario();   //imprimi o vetor do tipo NoBinario
    
private:
    
    Lista *lista;    //recebe um objeto do tipo lista
    NoArvore *raiz;  //no raiz

    int i = 0;   //variavel de controle pra percorrer o vetor do tipo NoBinario - declarado global

};

#endif /* ARVORE_H */

