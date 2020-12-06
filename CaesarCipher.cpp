#include <iostream>
#include <string>
#include "CaesarCipher.h"
#include "CharStack.h"
#include <stdlib.h>
#include <stdio.h>
using namespace std;

const string CaesarCipher::ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

CaesarCipher::CaesarCipher(const string& key){
  this->size_ = key.size();
  key_ = new int[size_];
  for(int loop = 0; loop < size_; loop++){
    char lett = key[loop];
    key_[loop] = (int)lett - 48;
  }
}

string CaesarCipher::cipher(const string& s){
  string encrypted = "";
  
  int keyLoop = 0;
  for(int loop = 0; loop < s.size(); loop++){
    int index = ALPHABET.find(s[loop]);
    if(s[loop] == ' '){
      encrypted = encrypted + ' ';
    }
    else if(s[loop] == '!'){
      encrypted = encrypted + '!';
    }
    else{
      index += *(key_ + keyLoop);
      keyLoop++;
      if(keyLoop >= size_){
        keyLoop = 0;
      }
      if(index >= ALPHABET.size()){
        index = index - ALPHABET.size();
      }
      encrypted = encrypted + ALPHABET[index];
    }
  }

  return encrypted;
}

string CaesarCipher::decipher(const string& s){
  string decrypted = "";
  
  int keyLoop = 0;
  for(int loop = 0; loop < s.size(); loop++){
    int index = ALPHABET.find(s[loop]);
    if(s[loop] == ' '){
      decrypted = decrypted + ' ';
    }
    else if(s[loop] == '!'){
      decrypted = decrypted + '!';
    }
    else{
      index -= *(key_ + keyLoop);
      keyLoop++;
      if(keyLoop >= size_){
        keyLoop = 0;
      }
      if(index >= ALPHABET.size()){
        index = index + ALPHABET.size();
      }
      decrypted = decrypted + ALPHABET[index];
    }
  }

  return decrypted;
}