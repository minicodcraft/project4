#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include "CaesarCipher.h"
#include "CharStack.h"
using namespace std;
/*
  Code segment for encrypting and decrypting a message has been provided for you in the main() function. You will need to implement related methods.
  
  You will need to add related statements to process the "message.txt" file one character at a time and use an undo and a redo stack to figure out what message is to be encrypted.

*/

int main() {
  string message = ""; //This is to eventually store the message to be encrypted

  string key; //This is to collect the multi-digit key from the user
  cout << "What is your key (digits only)? ";
  cin >> key;
  cin.ignore();
  CaesarCipher multiple_bits(key);

  //This code block is to help test your cipher and decipher methods
  string testing_message = "FREE PIZZA IN THE CAFETERIA";
  cout << "Testing cipher: " << endl;
  cout << testing_message << endl;
  cout << "====>" << endl;
  string encrypted_message = multiple_bits.cipher(testing_message);
  cout << encrypted_message << endl;
  cout << "Testing decipher: " << endl;
  cout << multiple_bits.decipher(encrypted_message) << endl << endl;


  string str;
  ifstream myfile;
  myfile.open ("message.txt");
  while(!myfile.eof()){
    getline(myfile,str);
    message += str;
  }
  cout << message << endl;
  CharStack undo;
  CharStack redo;
  for(int loop = 0; loop < message.size(); loop++){
    if(message[loop] == '<' && undo.isEmpty()){
    }
    else if(message[loop] == '>' && redo.isEmpty()){
    }
    else if(message[loop] == '<' && !undo.isEmpty()){
      redo.push(undo.top());
      undo.pop();
      undo.display();
    }
    else if(message[loop] == '>' && !redo.isEmpty()){
      undo.push(redo.top());
      redo.pop();
      redo.display();
    }
    else{
      undo.push(message[loop]);
    }
  }
  message = "";
  undo.display();
  redo.~CharStack();
  cout << undo.getSize() << endl;
  int undoSize = undo.getSize();
  for(int loop = 0; loop < undoSize; loop++){
    redo.push(undo.top());
    undo.pop();
  }
  for(int loop = 0; loop < undoSize; loop++){
    message += redo.top();
    redo.pop();
  }

  //Now, you are ready to apply the cipher and decipher to the message
  cout << "Applying cipher to the message from the undo stack:" << endl;
  cout << message << endl;
  cout << "Encrpted to:" << endl;
  encrypted_message = multiple_bits.cipher(message);
  cout << encrypted_message << endl;
  cout << "Decrypted back to:" << endl;
  cout << multiple_bits.decipher(encrypted_message) << endl;

  return 0;

}