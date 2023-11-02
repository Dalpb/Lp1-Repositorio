/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.cpp
 * Author: alulab14
 * 
 * Created on 2 de noviembre de 2023, 10:48 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Procesa.h"

Procesa::Procesa() {
    cantidad = 0;
}

Procesa::Procesa(const Procesa& orig) {
}

Procesa::~Procesa() {
}

void Procesa::leer() {
    ifstream arch("RegistroDeFaltas.csv",ios::in);
    if(!arch){
        cout<<"No abre RegistroDeFaltas.csv";
        exit(1);
    }
    int licen,codF,tipo,aa,mm,dd,fecha;
    char placa[20],c;
    while(true){
        arch >> licen;
        if(arch.eof())break;
        leeConductor(licen);
        arch.get();
        arch >>codF>>c>>dd>>c>>mm>>c>>aa>>c;
        fecha = aa*10000+mm*100+dd;
        arch.getline(placa,20,'\n');
        tipo = codF/100;
       
        switch(tipo){
            case 1:
                lregistro[cantidad].asignaGrave();
                break;
            case 2:
                lregistro[cantidad].asignaLeve();
                break;
            case 3:
                lregistro[cantidad].asignaMGrave();
                break;
        }
        lregistro[cantidad].SetFecha(fecha);
        lregistro[cantidad].SetPlaca(placa);
        lregistro[cantidad].lee(codF);
        cantidad++;
    }
}

void Procesa::leeConductor(int licen) {
    ifstream arch("Conductores.csv",ios::in);
    if(!arch){
        cout<<"No abre Conductores.csv";
        exit(1);
    }
    int leeLicencia;
    char nombre[100];
    while(true){
        arch >> leeLicencia;
        if(arch.eof())break;
        arch.get();
        if(leeLicencia == licen){
            arch.getline(nombre,100,'\n');
            lregistro[cantidad].SetNombre(nombre);
            lregistro[cantidad].SetLicencia(licen);
            return;
        }
        else while(arch.get() != '\n' );
    }
}

void Procesa::imprimir() {
    ofstream arch("Reporte.txt",ios::out);
    if(!arch){
        cout<<"No abre Reporte.txt";
    }
    
    for(int i=0 ; i<cantidad;i++){
        lregistro[i].imprime(arch);
    }
}

void Procesa::consolidar() {
    ifstream arch("sancionados.csv",ios::in);
    if(!arch){
        cout<<"No abre sancionados.csv";
        exit(1);
    }
    ofstream report("ReporteConsolidados.txt",ios::out);
    if(!report){
        cout<<"No abre ReproteConsolidados.txt";
        exit(1);
    }
    
    int lice,posC,numLicAux;
    int puntP = 0,meseS = 0;
    double montoMul = 0;
    char nom[100];
    while(true){
        arch>>lice;
        if(arch.eof())break;
        puntP = 0;
        meseS = 0;
        montoMul = 0;
        for(int i=0;lregistro[i].GetLicencia();i++){
            if(lregistro[i].GetLicencia() == lice){
                numLicAux = lregistro[i].GetLicencia();
                lregistro[i].GetNombre(nom);
                lregistro[i].acumulaDatos(puntP,meseS,montoMul);
            }
        }
        report<<left;
        report<<setw(20)<<"Conductor: "<<nom<<endl;
        report<<setw(20)<<"Licencia No."<<numLicAux<<endl;
        report<<setw(20)<<"Monto de Multas: "<<montoMul<<endl;
        report<<setw(20)<<"Puntos perdidos: "<<puntP<<endl;
        report<<setw(20)<<"Meses sancionados: "<<meseS<<endl;
        report<<endl<<endl;
    }
}



void Procesa::aplicar() {
    
    for(int i=0; i<cantidad;i++){
        lregistro[i].aplica();
    }
}

