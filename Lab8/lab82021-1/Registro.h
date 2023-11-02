/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Registro.h
 * Author: alulab14
 *
 * Created on 2 de noviembre de 2023, 10:44 AM
 */

#ifndef REGISTRO_H
#define REGISTRO_H

#include "Infraccion.h"
#include "Conductor.h"
#include "Falta.h"


class Registro: public Conductor,public Falta {
public:
    Registro();
    Registro(const Registro& orig);
    virtual ~Registro();
    void asignaLeve();
    void asignaGrave();
    void asignaMGrave();
    void lee(int falta);
    void imprime(ofstream &);
    void aplica();
    void acumulaDatos(int &puntosP,int &mesesS,double &total);
private:
    Infraccion *pfalta;
};

#endif /* REGISTRO_H */

