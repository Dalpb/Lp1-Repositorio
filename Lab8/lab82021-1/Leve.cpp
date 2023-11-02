/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Leve.cpp
 * Author: alulab14
 * 
 * Created on 2 de noviembre de 2023, 10:41 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Leve.h"

Leve::Leve() {
}

Leve::Leve(const Leve& orig) {
}

Leve::~Leve() {
}

void Leve::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Leve::GetDescuento() const {
    return descuento;
}

void Leve::leeDatos(ifstream&arch) {
   Infraccion::leeDatos(arch);
   arch >>descuento;
   arch.get();
}

void Leve::imprimir(ofstream& arch) {
    Infraccion::imprimir(arch);
    arch<<setw(20)<<"Descuento"<<GetDescuento()<<endl;
    arch<<endl;
}

void Leve::aplicar() {
    double monto = GetMulta();
    double montoDesc = monto*descuento/100;
    monto -= montoDesc;
    SetMulta(monto);
}

void Leve::acumula(int& puntosP, int& mesesS, double& total) {
    Infraccion::acumula(puntosP,mesesS,total);
}

