/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 2 de noviembre de 2023, 10:31 AM
 */

#include <iostream>

using namespace std;
#include "Procesa.h"
/*
 * 
 */
int main(int argc, char** argv) {
    class Procesa pro;
    
    pro.leer();
    pro.imprimir();
    pro.aplicar();
    pro.consolidar();
    return 0;
}

