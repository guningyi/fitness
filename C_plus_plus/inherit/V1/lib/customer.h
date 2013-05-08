#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_
#include <string>
using namespace std;

/*
 * define the basic customer 
 * */
class CCustomer
{
  friend class CManage;
  friend class CStaff;
  friend class CAdmin;
  private:
    std::string name; //customer name
    int gender;   //customer gender
    struct tm bookTime;  //customer want the room time.
  public:
    CCustomer(std::string pName, int pGender);
    virtual ~CCustomer();
  public:
    //virtual void showCustomerInfo() = 0;
    std::string getCustomerName();
    int getCustomerGender();
    struct tm getCustomerBookTime();
    virtual void showCustomerInfo();
};



#endif
