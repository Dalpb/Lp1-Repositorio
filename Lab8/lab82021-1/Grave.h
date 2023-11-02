/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grave.h
 * Author: alulab14
 *
 * Created on 2 de noviembre de 2023, 10:42 AM
 */

#ifndef GRAVE_H
#define GRAVE_H


#include "Infraccion.h"


class Grave: public Infraccion {
public:
    Grave();
    Grave(const Grave& orig);
    virtual ~Grave();
    void SetPuntos(int puntos);
    int GetPuntos() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void leeDatos(ifstream &);
    void imprimir(ofstream &);
    void aplicar();
    void acumula(int &puntosP,int &mesesS,double &total);

private:
    double descuento;
    int puntos;
};

#endif /* GRAVE_H */

