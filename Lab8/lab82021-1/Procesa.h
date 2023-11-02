/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.h
 * Author: alulab14
 *
 * Created on 2 de noviembre de 2023, 10:48 AM
 */

#ifndef PROCESA_H
#define PROCESA_H

#include "Registro.h"
class Procesa {
public:
    Procesa();
    Procesa(const Procesa& orig);
    virtual ~Procesa();
    void leer();
    void imprimir();
    void aplicar();
    void consolidar();
    void leeConductor(int licen);
private:

    Registro lregistro[1000];
    int cantidad;
};

#endif /* PROCESA_H */

