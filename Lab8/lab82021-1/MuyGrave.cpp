/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MuyGrave.cpp
 * Author: alulab14
 * 
 * Created on 2 de noviembre de 2023, 10:43 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "MuyGrave.h"

MuyGrave::MuyGrave() {
}

MuyGrave::MuyGrave(const MuyGrave& orig) {
}

MuyGrave::~MuyGrave() {
}

void MuyGrave::SetMeses(int meses) {
    this->meses = meses;
}

int MuyGrave::GetMeses() const {
    return meses;
}

void MuyGrave::SetPuntos(int puntos) {
    this->puntos = puntos;
}

int MuyGrave::GetPuntos() const {
    return puntos;
}

void MuyGrave::leeDatos(ifstream& arch) {
    Infraccion::leeDatos(arch);
    arch >>puntos;
    arch.get();
    arch >>meses;
}

void MuyGrave::imprimir(ofstream& arch) {
    Infraccion::imprimir(arch);
    arch<<setw(20)<<"Puntos Perdidos: "<<GetPuntos()<<endl;
    arch<<setw(20)<<"Meses sancionados: "<<GetMeses()<<endl;
    arch<<endl;
}

void MuyGrave::aplicar() {
    //no realiza nada
}

void MuyGrave::acumula(int& puntosP, int& mesesS, double& total) {
    Infraccion::acumula(puntosP,mesesS,total);
    mesesS += meses;
    puntosP += puntos;
}


