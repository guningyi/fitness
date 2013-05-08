#include <iostream>
#include <string>
#include <string.h>
#include <time.h>
#include "customer.h"

using namespace std;


CCustomer::CCustomer(std::string pName, int pGender)
{
    name = pName;
    gender = pGender;
    time_t timeTemp;
    struct tm *pBookTime;
    time(&timeTemp);
    pBookTime = localtime(&timeTemp);
    memcpy(&bookTime, pBookTime, sizeof(bookTime));
    cout<<"Customer Constructor!"<<endl;
}



CCustomer::~CCustomer()
{
    cout<<"Customer Destructor!"<<endl;
}

std::string CCustomer::getCustomerName()
{
    return name;
}


int CCustomer::getCustomerGender()
{
    return gender;
} 

struct tm CCustomer::getCustomerBookTime()
{
    return bookTime;
}


void CCustomer::showCustomerInfo()
{
   cout<<"---------------------------------------\n"<<endl;
   cout<<"-Name:"<<name<<"\n"<<endl;
   if (gender == 1 )
   { 
       cout<<"-Gender: male\n"<<endl;
   }
   else if(gender == 0)
   {
       cout<<"-Gender: female\n"<<endl;
   }
   cout<<"-BookTime: "<<asctime(&bookTime)<<"\n"<<endl;
   cout<<"---------------------------------------"<<endl;
}



int main(int argc, char** argv)
{
    CCustomer customer1("NingYi", 1);
    struct tm checkIn = customer1.getCustomerBookTime();
    cout<<"customer1 name: "<<customer1.getCustomerName()<<endl;
    cout<<"customer1 gender: "<<customer1.getCustomerGender()<<endl;
    cout<<"check in time is:\n"<<"year: "<<(checkIn.tm_year + 1900)<<"\nmonth:"<<checkIn.tm_mon<<"\nday:"<<checkIn.tm_mday<<"\nhour:"<<checkIn.tm_hour<<endl;
    //time_t booktime = customer1.getCustomerBookTime(); 
    //cout<<"customer1 BookTime: "<<booktime.<<endl;
    customer1.showCustomerInfo();
    return 1;
}
