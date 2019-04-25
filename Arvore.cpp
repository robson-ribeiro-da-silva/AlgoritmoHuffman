/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arvore.cpp
 * Author: robso
 * 
 * Created on 10 de Abril de 2019, 15:55
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <fstream>

#include "Arvore.h"
#include "Lista.h"
#include "NoBinario.h"
#include "Arquivo.h"

using namespace std;

int tNoBin = 257;  //tamanho da tabela ascii
NoBinario *nobinario = new NoBinario[257];     //No do tipo NoBinario declarado como variavel global, recebera o caracter e seu binario

Arvore::Arvore() {
    this->lista = nullptr;
    this->raiz = nullptr;
}

Arvore::Arvore(Lista* lista) {    //construtor recebe a lista
    this->lista = lista;
    this->raiz = nullptr;
}

Arvore::Arvore(const Arvore& orig) {
}

Arvore::~Arvore() {
}

Lista* Arvore::GetLista() const {
    return lista;
}

void Arvore::SetLista(Lista* lista) {
    this->lista = lista;
}

NoArvore* Arvore::GetRaiz() const {
    return raiz;
}

void Arvore::SetRaiz(NoArvore* raiz) {
    this->raiz = raiz;
}

int Arvore::GetI() const {
    return i;
}

void Arvore::SetI(int i) {
    this->i = i;
}

void Arvore::arvoreHuffman() {   //constói a arvore apartir da lista ordenada
    
    NoArvore *noRaiz;
    
    while(lista->GetElementos() > 1){  //esquanto o numero de elementos da lista for maior que um, vai removendo e inserindo de volta
         
        NoArvore *noEsq = lista->removeNoArvore();   //no arvore que recebe o no arvore da lista
        NoArvore *noDir = lista->removeNoArvore();
      
        NoArvore *noSoma = new NoArvore(noEsq->GetFrequencia() + noDir->GetFrequencia(), '#', noEsq, noDir); //cria um novo no apartir dos nós removidos
        NoLista *noLista = new NoLista(noSoma);  //cria no do tipo lista apartir do novo no arvore
        
        lista->inserirNovo(noLista);     //insere o novo no na lista
    }
    noRaiz = lista->removeNoArvore();   //remove o ultimo no da lista 
    SetRaiz(noRaiz);                    //e seta na raiz da arvore
}

bool Arvore::isfolha(NoArvore* no) {  //verifica se o no é folha
    if(no->GetEsquerdo() == nullptr && no->GetDireito() == nullptr){
        return true;
    }
    return false;
}

void Arvore::preOrdem(NoArvore* no) {  //percurso em pre-ordem recursivamente
    
    if(no != nullptr)
    {
        cout << no->GetChave() << " ";  
        preOrdem(no->GetEsquerdo());        
        preOrdem(no->GetDireito());
    }
}

//SEGUNDA OPÇÃO
void Arvore::gerarTabela2(NoArvore* no, string s) {   //funçao recursiva para gerar o caminho de binario ate a folha. em pre-ordem
    
    if(no != nullptr){         
        if(isfolha(no)){         //se o no for folha, seta a chave e o binario no vetor do tipo NoBinario
            nobinario[GetI()].SetChave(no->GetChave());
            nobinario[GetI()].SetBinario(s);
            SetI(GetI()+1);           //incremeta a variavel de controle que percorre o vetor
        }
        gerarTabela(no->GetEsquerdo(),  s+'0');       //chamada recursivamente ate a folha. se for para esquerda concatena 0
        gerarTabela(no->GetDireito(),  s+'1');        //para a direita concatena 1 na string
    }
}


void Arvore::gerarTabela(NoArvore* no, string s) {   //funçao recursiva para gerar o caminho de binario ate a folha. em pre-ordem
    
    if(no != nullptr){         
        if(isfolha(no)){         //se o no for folha, seta a chave e o binario no vetor do tipo NoBinario
            char chave = no->GetChave();
            int j =(int) chave;             //j recebe o valor decimal da chave correspondente a tabela ascii
            nobinario[j].SetChave(chave);   //seta a chave na posiçao do valor decimal
            nobinario[j].SetBinario(s);     //junto com o caminho binario
                       
        }
        gerarTabela(no->GetEsquerdo(),  s+'0');       //chamada recursivamente ate a folha. se for para esquerda concatena 0
        gerarTabela(no->GetDireito(),  s+'1');        //para a direita concatena 1 na string
    }
}

//SEGUNDA OPÇÃO
void Arvore::imprimirTabela2() {  //imrpime a tabela e escreve no arquivo
    
    ofstream escrita;
    escrita.open("tabela.txt", ios::out);
    
    if(escrita.is_open() && escrita.good()){
        escrita << "Binario : Caracter" <<endl;

        int i;
        for(i = 0; i<tNoBin; i++){  //percorre o vetor NoBinario até onde tem elementos
            if(nobinario[i].GetChave() == 0){ //se chegar na posisão vazia para
                break;
            }
            cout<<" |"<<nobinario[i].GetChave() <<"\t "<<nobinario[i].GetBinario()<<"|"<<endl;  //vai imprimindo o vetor a cada incremento
            escrita << " |"+nobinario[i].GetBinario()+" :\t\t "+nobinario[i].GetChave()+"|" <<endl;  //vai escrevendo o vetor no arquivo a cada incremento
        }
        escrita.close();
    }
}



void Arvore::imprimirTabela() {  //imrpime a tabela e escreve no arquivo
    
    ofstream escrita;
    escrita.open("tabela.txt", ios::out);
    
    if(escrita.is_open() && escrita.good()){
        escrita << "Binario : Caracter" <<endl;

        int i;
        for(i = 0; i<tNoBin; i++){  //percorre todo o vetor NoBinario até onde tem elementos
            if(nobinario[i].GetChave() != 0){      //caso alguma chave igual a 0, nao faz     
            
                cout<<" |"<<nobinario[i].GetChave() <<"\t "<<nobinario[i].GetBinario()<<"|"<<endl;  //vai imprimindo o vetor a cada incremento
                escrita << " |"+nobinario[i].GetBinario()+" :\t\t "+nobinario[i].GetChave()+"|" <<endl;  //vai escrevendo o vetor no arquivo a cada incremento
        
            }
        }
        escrita.close();
    }
}

//SEGUNDA OPÇÃO
void Arvore::compactador2(char lista[], int t) {  //recebe o vetor de char e seu tamanho, o que resultou apartir do texto lido do arquivo
    
    ofstream escrita;
    escrita.open("compressao.txt", ios::out);
    
    if(escrita.is_open() && escrita.good()){

        int j=0;
        for(int i=3; i<t; i++){                         //percorre cada posicao do vetor
            while(lista[i] != nobinario[j].GetChave()){ //e compara o caracter com o vetor de NoBinario, ou seja, a tabela
                j++;

                if(nobinario[j].GetChave() == 0){   //condição que percorre o noBinario ate onde tem elementos
                    break;
                }
            }
            cout<<nobinario[j].GetBinario()<<" ";  //imprimi o binario correspondente a cada caracter da lista.
            escrita << nobinario[j].GetBinario()+" "; //e escreve no arquivo, gerando a codificação do texto lido

            j=0;
        }
        escrita.close();  
    }
}


void Arvore::compactador(char lista[], int t) {  //recebe o vetor de char e seu tamanho, o que resultou apartir do texto lido do arquivo
    int x = 0;
    ofstream escrita;
    escrita.open("compressao.txt", ios::out);
    
    if(escrita.is_open() && escrita.good()){
       
        
        for(int i=0; i<t; i++){ 
            x = (int) lista[i]; 
            if(x > 0){  //caso pegue lixo na lista
           //     cout<<lista[i]<<" "<< x <<" ";
                cout<< nobinario[x].GetBinario()<<" ";  //imprimi o binario correspondente a cada caracter da lista.
                escrita << nobinario[x].GetBinario()+" "; //e escreve no arquivo, gerando a codificação do texto lido
            }
        }
        escrita.close();  
    }
}

void Arvore::liberarMemoria(NoArvore* no) {  //funçao com chamadas recursivas para limpar a memoria que a arvore utilizou
    
    if(no != nullptr){
        NoArvore *esq = no->GetEsquerdo();
        NoArvore *dir = no->GetDireito();
        delete no;
        liberarMemoria(esq);
        liberarMemoria(dir);        
    }else{
        return;
    }
}

void Arvore::imprimirListaBinario() {  //imprimi o conteudo do vetor de NoBinario, ou seja a tabela.
    for(int i=0; i<=tNoBin; i++){
        if(nobinario[i].GetChave() != 0){
            cout << nobinario[i].GetChave()<<" "<<nobinario[i].GetBinario()<<" ";
        }
    }
}









