/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Core.cpp
 * Author: robso
 * 
 * Created on 18 de Abril de 2019, 09:43
 */

//#include <cstdlib>
//#include <cstring>
#include <string.h>

#include "Arquivo.h"
#include "NoFreq.h"
#include "NoArvore.h"
#include "NoLista.h"
#include "Lista.h"
#include "Arvore.h"

#include "Core.h"

using namespace std;

Core::Core() {
}

Core::Core(const Core& orig) {
}

Core::~Core() {
}

void Core::iniciar(string arquivo) {  //funçao inicial, recebe o arquivo
    
    Arquivo a; 
    
    int tAscii = 256;   //tamanho da tabela ascii
    
    Lista *lista = new Lista();  //ponteiro lista
    
    NoFreq no;       //no do tipo NoFreq
    
    NoFreq nofreq[tAscii];  //vetor  do tipo NoFreq
    
    string saida = a.carregarArquivo(arquivo);  //string recebe a string concatenada resultado da leitura do arquivo
    cout << "\n ARQUIVO LIDO: \n" << saida <<"\n"<<endl;  //imprimi o conteudo do arquivo
    
    int t = saida.length()-1;
    char *s = new char[t];   //vetor de char
    memcpy(s, saida.c_str(), saida.length()-1);    //converte a string em vetor de char
   
    for(int j=0; j<=tAscii; j++){  //apenas pra limpar o vetor do NoFreq
        nofreq[j].SetChave(0);
        nofreq[j].SetPosicao(0);
        nofreq[j].SetFrequencia(0);
    }
    
    int j = 0;
    for(int i=0; i<t; i++){       //percorre o vetor de char que tem o conteudo
        j =(int) s[i];            //pega o valor decimal do caracter 
       if(nofreq[j].GetChave() == s[i]){ 
            nofreq[j].SetFrequencia(nofreq[j].GetFrequencia() + 1); //se ja estiver no vetor incrementa a frequencia
        }else{
            nofreq[j].SetChave(s[i]);  //insere o caracter no vetor NoFreq
            nofreq[j].SetPosicao(j);
            nofreq[j].SetFrequencia(1);
        }
    }
    
    cout << "\n LISTA DE FREQUÊNCIA: " <<endl;  //imprimi o vetor de NoFreq
    for(int i=0; i<=tAscii; i++){
        if(nofreq[i].GetChave() != 0 ){
            cout <<" Chave: " << nofreq[i].GetChave() <<" Frequência: " 
                    << nofreq[i].GetFrequencia() << " Posição: "
                    <<nofreq[i].GetPosicao()<<endl; 
            
            NoArvore *nArvore = new NoArvore(nofreq[i].GetFrequencia(), nofreq[i].GetChave()); //cria o NoArvore
           
            NoLista *nLista = new NoLista(nArvore);  //cria o NoLista
           
            lista->inserirNovo(nLista);  //insere o nó na lista
        }
    }
    
    cout <<"\n LISTA ORDENADA: "<<endl;
    lista->imprimir();      //imprimi a lista ordenada
    
    cout << "\n ARVORE: "<<endl;
    Arvore *arv = new Arvore(lista);   //cria objeto do tipo arvore recebendo a lista
    arv->arvoreHuffman();               //gera a arvore
    arv->preOrdem(arv->GetRaiz());      //imprimi em pré-ordem
    arv->gerarTabela(arv->GetRaiz(), ""); //funçao de gerar a tabela
    
    cout <<"\n TABELA: "<<endl;
    arv->imprimirTabela();             //imprimi a tabela de binario
    
    cout <<"\n COMPACTACAO: "<<endl;
    arv->compactador(s, t);             //compacta apartir do vetor de char e seu tamanho
    arv->liberarMemoria(arv->GetRaiz());  //libera a memoria
   // arv->imprimirListaBinario();
}


