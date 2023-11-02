/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MuyGrave.h
 * Author: alulab14
 *
 * Created on 2 de noviembre de 2023, 10:43 AM
 */

#ifndef MUYGRAVE_H
#define MUYGRAVE_H

#include "Infraccion.h"



class MuyGrave:public Infraccion {
public:
    MuyGrave();
    MuyGrave(const MuyGrave& orig);
    virtual ~MuyGrave();
    void SetMeses(int meses);
    int GetMeses() const;
    void SetPuntos(int puntos);
    int GetPuntos() const;
    void leeDatos(ifstream &);
    void imprimir(ofstream &);
    void aplicar();
    void acumula(int &puntosP,int &mesesS,double &total);

private:
    int puntos;
    int meses;
};

#endif /* MUYGRAVE_H */

