/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Leve.h
 * Author: alulab14
 *
 * Created on 2 de noviembre de 2023, 10:41 AM
 */

#ifndef LEVE_H
#define LEVE_H

#include "Infraccion.h"



class Leve: public Infraccion{
public:
    Leve();
    Leve(const Leve& orig);
    virtual ~Leve();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void leeDatos(ifstream &);
    void imprimir(ofstream &);
    void aplicar();
    void acumula(int &puntosP,int &mesesS,double &total);

private:
    double descuento;
};

#endif /* LEVE_H */

