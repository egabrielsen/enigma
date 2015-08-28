//
//  Enigma.cpp
//  Basic Enigma
//
//  Created by Erik Gabrielsen on 1/2/15.
//  Copyright (c) 2015 Erik Gabrielsen. All rights reserved.
//

#include "Enigma.h"

Enigma::Enigma() {
    rotarI = 1;
    rotarII = 1;
    rotarIII = 1;
    keyList[0] = 'E';
    keyList[1] = 'K';
    keyList[2] = 'M';
    keyList[3] = 'F';
    keyList[4] = 'L';
    keyList[5] = 'G';
    keyList[6] = 'D';
    keyList[7] = 'Q';
    keyList[8] = 'V';
    keyList[9] = 'Z';
    keyList[10] = 'N';
    keyList[11] = 'T';
    keyList[12] = 'O';
    keyList[13] = 'W';
    keyList[14] = 'Y';
    keyList[15] = 'H';
    keyList[16] = 'X';
    keyList[17] = 'U';
    keyList[18] = 'S';
    keyList[19] = 'P';
    keyList[20] = 'A';
    keyList[21] = 'I';
    keyList[22] = 'B';
    keyList[23] = 'R';
    keyList[24] = 'C';
    keyList[25] = 'J';
    keyList[26] = '\0';
}

Enigma::Enigma(string key) {
    rotarI = (int)key[0] - 65;
    rotarII = (int)key[1] - 65;
    rotarIII = (int)key[2] - 65;
    keyList[0] = 'E';
    keyList[1] = 'K';
    keyList[2] = 'M';
    keyList[3] = 'F';
    keyList[4] = 'L';
    keyList[5] = 'G';
    keyList[6] = 'D';
    keyList[7] = 'Q';
    keyList[8] = 'V';
    keyList[9] = 'Z';
    keyList[10] = 'N';
    keyList[11] = 'T';
    keyList[12] = 'O';
    keyList[13] = 'W';
    keyList[14] = 'Y';
    keyList[15] = 'H';
    keyList[16] = 'X';
    keyList[17] = 'U';
    keyList[18] = 'S';
    keyList[19] = 'P';
    keyList[20] = 'A';
    keyList[21] = 'I';
    keyList[22] = 'B';
    keyList[23] = 'R';
    keyList[24] = 'C';
    keyList[25] = 'J';
    keyList[26] = '\0';

}

void Enigma::displayKey() {
    cout << "The Enigma Key: " << (char)(rotarI+65) << (char)(rotarII+65) << (char)(rotarIII+65) << endl;
}

char Enigma::encrypt(char token) {
    char temp = encrypt(token, rotarI);
    char final = encrypt(temp, rotarII);
    return encrypt(final, rotarIII);
}

char Enigma::encrypt(char token, int rotar) {
    int index = (int) token;
    if (index >= 65 && index <= 90) {
        index = index - 65 + rotar;
        if (index >= 26) {
            index = index - 26;
        }
        return keyList[index];
    } else if (index > 96 && index <= 122) {
        index = index - 32;
        return encrypt((char) index, rotar);
    } else {
        return token;
    }
}

char Enigma::cipher(char token) {
    char temp = cipher(token, rotarIII);
    char final = cipher(temp, rotarII);
    return cipher(final, rotarI);
}

char Enigma::cipher(char token, int rotar) {
    int ascii = 0;
    bool isAscii = false;
    for (int i = 0; i < 26; i++) {
        if (token == keyList[i]) {
            ascii = i + 65;
            isAscii = true;
            i = 26;
        }
    }
    if (!isAscii) {
        return token;
    } else {
        ascii = ascii - rotar;
        if (ascii < 65) {
            ascii = ascii + 26;
        }
        return (char) (ascii);
    }
}






