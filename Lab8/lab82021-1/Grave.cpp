/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grave.cpp
 * Author: alulab14
 * 
 * Created on 2 de noviembre de 2023, 10:42 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Grave.h"

Grave::Grave() {
}

Grave::Grave(const Grave& orig) {
}

Grave::~Grave() {
}

void Grave::SetPuntos(int puntos) {
    this->puntos = puntos;
}

int Grave::GetPuntos() const {
    return puntos;
}

void Grave::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Grave::GetDescuento() const {
    return descuento;
}

void Grave::leeDatos(ifstream& arch) {
    Infraccion::leeDatos(arch);
    arch >>descuento;
    arch.get();
    arch >> puntos;
}

void Grave::imprimir(ofstream& arch) {
    Infraccion::imprimir(arch);
    arch<<setw(20)<<"Puntos perdidos: "<<GetPuntos()<<endl;
    arch<<setw(20)<<"Descuento: "<<GetDescuento()<<endl;
    arch<<endl;
}

void Grave::aplicar() {
    double monto = GetMulta();
    double montoDesc = monto*descuento/100;
    monto -= montoDesc;
    SetMulta(monto);
}

void Grave::acumula(int& puntosP, int& mesesS, double& total) {
    Infraccion::acumula(puntosP,mesesS,total);
    puntosP += puntos;
}

