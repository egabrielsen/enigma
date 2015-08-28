# Enigma
A c++ program that encrypts text files by using 3 "rotors" modeled after Alan Turing's Enigma machine used in WWII

#How to use
Compile with g++ or gcc 
  <p>g++ *.cpp</p>
  
Open a shell:
  Just run ./a.out to open an interactive shell
  Type exit to exit
  
Encripting a file: 
  ./a.out \<file name to encript\>
  -> then follow the steps that follow to encript. You must specify a key to encript the file. This will be the enigma key that is used to cipher the encription
  
decipher a file: 
  -> You must know the 3 capital letter enigma code in order to decipher text. 
  ./a.out \<file to decipher\>
  -> then follow the steps to decipher
