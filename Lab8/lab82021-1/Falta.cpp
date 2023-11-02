/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Falta.cpp
 * Author: alulab14
 * 
 * Created on 2 de noviembre de 2023, 10:38 AM
 */
#include <iostream>
#include <cstring>
using namespace std;
#include "Falta.h"

Falta::Falta() {
    fecha = 0;
    placa = nullptr;
}

Falta::Falta(const Falta& orig) {
}

Falta::~Falta() {
    if(placa !=nullptr)delete placa;
}

void Falta::GetPlaca(char* plac) const {
    if(placa == nullptr)plac[0]=0;
    else strcpy(plac,placa);
}

void Falta::SetPlaca(const char* placa) {
    if(this->placa != nullptr)delete this->placa;
    this->placa = new char[strlen(placa)+1];
    strcpy(this->placa,placa);
}

void Falta::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Falta::GetFecha() const {
    return fecha;
}

