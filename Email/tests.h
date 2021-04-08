#include "util.h"
#include "Date.h"
#include "Email.h"
#include "EmailBox.h"
#include "Filter.h"
#include "FilterByYear.h"
#include "FilterBySender.h"
#include "Formatter.h"
#include "GmailFormatter.h"
#include "YahooFormatter.h"
#include "SpamEmail.h"
using namespace std; 

//tests

void TestDate(){
  cout<<"TestDate"<<endl;
Date * date = new Date(1,1,2019);
assertTrue(date->getYear()==2019);
}

 void TestEmail(){
    cout<<"TestEmail"<<endl;
Date * date = new Date(1, 1, 2019);
Email* email = new Email("Ricardo", "test tomorrow",
"do not miss it!!!!", date);
assertTrue(email->getSender() == "Ricardo");
assertTrue(email->getDate()->getYear() == 2019);
assertTrue(email->toString() == "Ricardo: test tomorrow");
} 

void TestEmailBox(){
  cout<<"TestEmailBox"<<endl;
EmailBox* box = new EmailBox();
Email* email1 = new Email("Ricardo", "test tomorrow",
"do not miss it!!!!", new Date(1,2,2019));
 Email* email2 = new Email("alex", "visiting San Francisco",
"lets meet at the airport", new Date(2, 2, 2019)); 
Email* email3 = new Email("carito", "homework",
"Ricardo you need to do your homework!", new Date(1, 2, 2018));
box->add(email1); 
box->add(email2);
box->add(email3);
int result = box->count(new FilterByYear(2019)); 
assertTrue(result == 2);
result = box->count(new FilterByYear(2018));
 assertTrue(result == 1);
} 

void TestEmailBox2(){
  cout<<"TestEmailBox2"<<endl;
EmailBox* box = new EmailBox();
Email* email1 = new Email("Ricardo", "test towmorrow",
"do not miss it!!!!", new Date(1, 2, 2019)); 
Email* email2 = new Email("alex", "visiting San Francisco",
"lets meet at the airport", new Date(2, 2, 2019)); 
Email* email3 = new Email("carito", "homework",
"Ricardo you need to do your homework!", new Date(1, 2, 2018));
box->add(email1); 
box->add(email2); 
box->add(email3);
int result = box->count(new FilterBySender("alex"));
assertTrue(result == 1);
}
void TestFormatter(){
  cout<<"TestFormatter"<<endl;
Email* email = new Email("Ricardo", "test tomorrow",
"do not miss it!!!!", new Date(1, 2, 2019));
Formatter* formatter = new GmailFormatter();
string result = formatter->format(email); 
assertTrue(result == "GMAIL( Ricardo: test tomorrow )");
} 

void TestFormatter2(){
  cout<<"TestFormatter2"<<endl;
Email* email = new Email("Ricardo", "test tomorrow",
"do not miss it!!!!", new Date(1, 2, 2019));
Formatter* formatter = new YahooFormatter();
string result = formatter->format(email); 
assertTrue(result == "YAHOO( Ricardo: test tomorrow )");
} 

void TestFormatter3(){
  cout<<"TestFormatter3"<<endl;
Email* email = new SpamEmail("Ricardo", "test tomorrow",
"do not miss it!!!!", new Date(1, 2, 2019));
Formatter* formatter = new YahooFormatter();
string result = formatter->format(email);
assertTrue(result == "YAHOO( SPAM: Ricardo: test tomorrow )");
}


