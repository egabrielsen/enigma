//
//  main.cpp
//  Basic Enigma
//
//  Created by Erik Gabrielsen on 1/2/15.
//  Copyright (c) 2015 Erik Gabrielsen. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <ostream>
#include <cctype>
#include "Enigma.h"

using namespace std;

bool validKey(string);

int main(int argc, const char * argv[]) {
  if (argv[1] != NULL) {
    cout << "Welcome to Enigma" << endl << endl;
    cout << "Please Select an Option:" << endl;
    cout << "   (1)  Encrypt File" << endl;
    cout << "   (2)  Cipher File" << endl;
    string choice;
    cin >> choice;

    if (choice == "1") {

        cout << "Please Enter the Enigma Key: ";
        string enigmaKey;
        cin >> enigmaKey;

        ifstream input(argv[1], fstream::in);
        ofstream out("encryptedFile");

        if (validKey(enigmaKey)) {
            Enigma* enigmaCipher = new Enigma(enigmaKey);
            cout << "Settings Succesfully Configured for ";
            enigmaCipher->displayKey();
            cout << "text is being incrypted..." << endl;
            int position = 0;
            char* contents = new char[1024];
            while (!input.eof()) {
                input.get(contents[position]);
                // cout << contents[position] << " | " << enigmaCipher->encrypt(contents[position]) << endl;
                out << enigmaCipher->encrypt(contents[position]);
                position++;
            }
            delete [] contents;
            delete [] enigmaCipher;
            out.close();
            input.close();
            cout << "Successful incryption!" << endl;

        } else {
            cout << "**Incryption Failed**" << endl;
        }
    } else if (choice == "2") {
        cout << "Please Enter the Enigma Key: ";
        string enigmaKey;
        cin >> enigmaKey;

        ifstream input2("encryptedFile");
        ofstream output("cipheredFile");

        if (validKey(enigmaKey)) {
            Enigma* enigmaCipher = new Enigma(enigmaKey);
            cout << "Settings Succesfully Configured for ";
            enigmaCipher->displayKey();
            int pos = 0;
            char* contents2 = new char[1024];
            while (!input2.eof()) {
                input2.get(contents2[pos]);
                //cout << contents2[pos];
                output << enigmaCipher->cipher(contents2[pos]);
                pos++;
            }
            delete [] contents2;
            delete [] enigmaCipher;
            output.close();
            input2.close();
            cout << "Text Successfuly Ciphered" << endl;
        } else {
            cout << "**Enigma Failed to Cipher Code**" << endl;
        }
    } else {
        cout << "**Invalid Selection**" << endl;
    }
    return 0;
  } else {
    bool shell = true;
    while(shell) {
        cout << "Cypher or Encript? (c/e) >> ";
        string select;
        cin >> select;
        if (select == "c") {
          cout << "Please Enter the Enigma Key >> ";
          string enigmaKey;
          cin >> enigmaKey;
          if (validKey(enigmaKey)) {
            Enigma* enigmaCipher = new Enigma(enigmaKey);
            cout << "Enter Content:" << endl;
            string content;
            getline(cin, content);
            cin.ignore();
            cout << content << " ---> ";
            for (int i = 0; i < content.length(); i++) {
                char temp = toupper(content[i]);
                cout << enigmaCipher->cipher(temp);
            }
            cout << endl;
          }
        } else if (select == "e") {
          cout << "Please Enter the Enigma Key >> ";
          string enigmaKey;
          cin >> enigmaKey;
          if (validKey(enigmaKey)) {
            Enigma* enigmaCipher = new Enigma(enigmaKey);
            cout << "Enter Content >> ";
            string content;
            cin >> content;
            cout << content[0];
          }
        } else if (select == "exit") {
            shell = false;
        } else {
            cout << "*Please select correct option: Try Again*" << endl;
        }
    } 
  }
}

bool validKey(string key) {
    const char* charKey = key.c_str();
    if (strlen(charKey) != 3) {
        return false;
    } else {
        for (int i = 0; i < 3; i++) {
            if (isalpha(key[i]))
                cout << key[i] << " has been verified\n";
            else {
                cout << key[i] << " is INVALID" << endl;
                return false;
            }
        }
        return true;
    }
}
