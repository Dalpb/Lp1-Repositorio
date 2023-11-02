/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Registro.cpp
 * Author: alulab14
 * 
 * Created on 2 de noviembre de 2023, 10:44 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Registro.h"
#include "Leve.h"
#include "Grave.h"
#include "MuyGrave.h"

Registro::Registro() {
    pfalta = nullptr;
}

Registro::Registro(const Registro& orig) {
}

Registro::~Registro() {
    if(pfalta != nullptr)delete pfalta;
}

void Registro::asignaLeve() {
    pfalta = new class Leve;
}

void Registro::asignaGrave() {
    pfalta = new class Grave;
}

void Registro::asignaMGrave() {
    pfalta = new class MuyGrave;
}

void Registro::lee(int falta) {
    ifstream arch("Infracciones.csv",ios::in);
    if(!arch){
        cout<<"No abre Infracciones.csv";
        exit(1);
    }
    int leeFalta;
    while(true){
        arch >> leeFalta;
        if(arch.eof())break;
        arch.get();
        if(leeFalta == falta){
            pfalta->SetCodigo(falta);
            pfalta->leeDatos(arch);
            break;
        }
        else while(arch.get() != '\n');
    }
}

void Registro::imprime(ofstream& arch) {
    char nom[100],plac[20];
    GetNombre(nom);
    GetPlaca(plac);
    arch<<left;
    arch<<setw(15)<<"Coductor: "<<nom<<endl;
    arch<<setw(15)<<"Licencia No: "<<GetLicencia()<<endl;
    arch<<setw(15)<<"Placa: "<<plac<<endl;

    pfalta->imprimir(arch);
}

void Registro::aplica() {
    pfalta->aplicar();
}

void Registro::acumulaDatos(int& puntosP, int& mesesS, double& total) {
    pfalta->acumula(puntosP,mesesS,total);
}


