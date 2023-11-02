/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.cpp
 * Author: alulab14
 * 
 * Created on 2 de noviembre de 2023, 10:33 AM
 */
#include <iostream>
#include <cstring>
using namespace std;
#include "Conductor.h"

Conductor::Conductor() {
    licencia = 0;
    nombre = nullptr;
}

Conductor::Conductor(const Conductor& orig) {
}

Conductor::~Conductor() {
    if(nombre != nullptr)delete nombre;
}

void Conductor::GetNombre(char* nom) const {
    if(nombre == nullptr)nom[0] = 0;
    else strcpy(nom,nombre);
}

void Conductor::SetNombre(const char* nombre) {
    if(this->nombre != nullptr)delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}


void Conductor::SetLicencia(int licencia) {
    this->licencia = licencia;
}

int Conductor::GetLicencia() const {
    return licencia;
}

