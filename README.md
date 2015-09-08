# Enigma
A c++ program that encrypts text files by using 3 "rotors" modeled after Alan Turing's Enigma machine used in WWII. Need to update to use with lower case letters, numbers, and punctuation for better encryption.

#How to use
Compile using Makefile
<li> Run <code>make</code> </li>
To clean up output files and executable
<li> Run <code>make clean</code></li>

<h3> Open a shell: </h3>
  <li> Run <code> ./enigma.exe </code> to open an interactive shell </li>
  <li> Type <code> exit </code> to exit </li>

<h3> Encripting a file: </h3>
  <li> Run <code> ./enigma.exe \<file to encript\> </code> </li>
  <li> Follow the steps that follow to encript. You must specify a key to encript the file. This will be the enigma key that is used to cipher the encription </li>

<h3> Decipher a file: </h3>
  <li> You must know the 3 capital letter enigma code in order to decipher text.</li>
  <li> Run <code> ./enigma.exe \<file to decipher\> </code> </li>
  <li> Follow the steps to decipher </li>
