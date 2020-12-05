#include <iostream>
#include <string>
#include "CaesarCipher.h"
#include "CharStack.h"
#include <stdlib.h>
#include <stdio.h>
using namespace std;

const string CaesarCipher::ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

CaesarCipher::CaesarCipher(const string& key){
  int arr[key.size()];
  size_ = key.size();
  key_ = arr;
  for(int loop = 0; loop < size_; loop++){
    char lett = key[loop];
    key_[loop] = (int)lett - 48;
  }
}

string CaesarCipher::cipher(const string& s){
  cout << "test 1" << endl;
  string encrypted = "";
  int keyLoop = 0;
  for(int loop = 0; loop < s.size(); loop++){
    cout << "test 2" << endl;
    if(s[loop] == ' '){
      encrypted = encrypted + ' ';
      cout << "test 7" << endl;
    }
    else{
      cout << "test 3" << endl;
      int index = ALPHABET.find(s[loop]);
      cout << "test 4" << endl;
      index += this->key_[keyLoop];
      cout << index << endl;
      cout << "test 5" << endl;
      keyLoop++;
      if(keyLoop > size_){
        keyLoop = 0;
      }
      if(index > 25){
        index = index - 25;
      }
      cout << "test 6" << endl;
      encrypted = encrypted + ALPHABET[index];
      cout << encrypted << endl;
    }
  }
  return encrypted;
}