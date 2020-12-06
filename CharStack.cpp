#include "CharStack.h"
#include <iostream>
#include <stack>
using namespace std;

CharStack::CharStack(){
  this->top_ = nullptr;
  this->size_= 0;
}

CharStack::~CharStack(){
  Node* temp;
  while(this-> top_ != nullptr){
    temp = this-> top_->next;
    delete this-> top_;
    this-> top_ = temp;
    size_--;
  }
}

int CharStack::getSize(){
  return size_;
}

bool CharStack::isEmpty() const{
  return (this->top_ == nullptr);
}

char& CharStack::top() const{
  return this->top_->letter;
}

void CharStack::push(char newLetter){
  Node* temp;
  temp = new Node();

  temp-> letter = newLetter;
  temp-> next = this->top_;
  this->top_ = temp;
  size_++;
}

void CharStack::pop(){
  Node* temp;
  if(this->top_ == nullptr){
    return;
  }
  else{
    temp = this->top_;
    this->top_ = this->top_-> next;
    temp-> next = nullptr;
    free(temp);
  }
  size_--;
}

void CharStack::display() const{
  Node* temp;
  if(this->top_ == nullptr){
    return;
  }
  else{
    temp = this->top_;
    while(temp != nullptr){
      cout << temp-> letter;
      temp = temp-> next;
    }
  }
  cout << endl;
}