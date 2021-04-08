#pragma once
#include <iostream>
#include <string>
#include "Date.h"
#include "Email.h"
using namespace std; 

class SpamEmail: public Email{
private:
public:
SpamEmail(string sender, string subject, string message, Date* date): Email(sender,subject,message,date){
}
virtual bool isSpam(){
  return true; 
}
  

};