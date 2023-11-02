/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infraccion.cpp
 * Author: alulab14
 * 
 * Created on 2 de noviembre de 2023, 10:36 AM
 */
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Infraccion.h"

Infraccion::Infraccion() {
    codigo = 0;
    gravedad = nullptr;
}

Infraccion::Infraccion(const Infraccion& orig) {
}

Infraccion::~Infraccion() {
    if(gravedad!= nullptr)delete gravedad;
}

void Infraccion::SetMulta(double multa) {
    this->multa = multa;
}

double Infraccion::GetMulta() const {
    return multa;
}

void Infraccion::GetGravedad(char* grav) const {
    if(gravedad == nullptr)grav[0] = 0;
    else strcpy(grav,gravedad);
}

void Infraccion::SetGravedad(const char* gravedad) {
    if(this->gravedad != nullptr)delete this->gravedad ;
    this->gravedad = new char[strlen(gravedad)+1];
    strcpy(this->gravedad,gravedad);
}


void Infraccion::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Infraccion::GetCodigo() const {
    return codigo;
}

void Infraccion::leeDatos(ifstream&arch) {
    char motiv[200],tipo[20];
    arch.getline(motiv,200,',');
    arch.getline(tipo,20,',');
    arch >>multa;
    arch.get();
    SetGravedad(motiv);
}

void Infraccion::imprimir(ofstream&arch) {
    char grav[200];
    GetGravedad(grav);
    arch<<setw(15)<<"Gravedad: "<<grav<<endl;
    arch<<setw(15)<<"Multa: "<<GetMulta()<<endl;
}

void Infraccion::acumula(int& puntosP, int& mesesS, double& total) {
    total += GetMulta();
}



