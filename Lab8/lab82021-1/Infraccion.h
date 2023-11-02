/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infraccion.h
 * Author: alulab14
 *
 * Created on 2 de noviembre de 2023, 10:36 AM
 */

#ifndef INFRACCION_H
#define INFRACCION_H

#include <fstream>

class Infraccion {
public:
    Infraccion();
    Infraccion(const Infraccion& orig);
    virtual ~Infraccion();
    void SetMulta(double multa);
    double GetMulta() const;
    void SetGravedad(const char* gravedad);
    void GetGravedad(char *grav) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void leeDatos(ifstream &);
    virtual void imprimir(ofstream &);
    virtual void aplicar() = 0;
    virtual void acumula(int &puntosP,int &mesesS,double &total);
private:
    int codigo;
    char *gravedad;
    double multa;
};

#endif /* INFRACCION_H */

