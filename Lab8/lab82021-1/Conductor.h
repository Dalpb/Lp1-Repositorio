/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.h
 * Author: alulab14
 *
 * Created on 2 de noviembre de 2023, 10:33 AM
 */

#ifndef CONDUCTOR_H
#define CONDUCTOR_H

class Conductor {
public:
    Conductor();
    Conductor(const Conductor& orig);
    virtual ~Conductor();
    void SetNombre(const char* nombre);
    void GetNombre(char *nom) const;
    void SetLicencia(int licencia);
    int GetLicencia() const;
private:
    int licencia;
    char *nombre;
};

#endif /* CONDUCTOR_H */

