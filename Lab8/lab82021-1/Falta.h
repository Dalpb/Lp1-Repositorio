/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Falta.h
 * Author: alulab14
 *
 * Created on 2 de noviembre de 2023, 10:38 AM
 */

#ifndef FALTA_H
#define FALTA_H

class Falta {
public:
    Falta();
    Falta(const Falta& orig);
    virtual ~Falta();
    void SetPlaca(const char* placa);
    void GetPlaca(char *plac) const;
    void SetFecha(int fecha);
    int GetFecha() const;
private:
    int fecha;
    char *placa;
};

#endif /* FALTA_H */

