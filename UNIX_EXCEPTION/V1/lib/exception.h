#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <exception>
#include <string>


//CException are derived from exception
class CException:public std::exception
{
public:
    CException(std::string info):expInfo(info){}
    CException();
    virtual ~CException() throw();
    const char* what() const throw();
private:
    std::string expInfo;

};


#endif
