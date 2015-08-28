//
//  Enigma.h
//  Basic Enigma
//
//  Created by Erik Gabrielsen on 1/2/15.
//  Copyright (c) 2015 Erik Gabrielsen. All rights reserved.
//

#ifndef __Basic_Enigma__Enigma__
#define __Basic_Enigma__Enigma__

#include <iostream>
#include <stdio.h>

using namespace std;

class Enigma {
private:
    int rotarI;
    int rotarII;
    int rotarIII;
    char keyList[27];
public:
    Enigma();
    Enigma(string key);
    void displayKey();
    char encrypt(char token);
    char encrypt(char token, int rotar);
    char cipher(char token);
    char cipher(char token, int rotar);
};

#endif /* defined(__Basic_Enigma__Enigma__) */
