/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Core.h
 * Author: robso
 *
 * Created on 18 de Abril de 2019, 09:43
 */
#include <string>

#ifndef CORE_H
#define CORE_H

using namespace std;

class Core {    //classe principal para execução
public:
    Core();
    Core(const Core& orig);
    virtual ~Core();
    void iniciar(string arquivo);   //metodo de iniciar a execução
    
private:

};

#endif /* CORE_H */

