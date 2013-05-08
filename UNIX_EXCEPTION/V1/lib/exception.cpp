#include "exception.h"
#include <string>
#include <vector>
#include <map>


using namespace std;
#if 0
CException::CException(std::string info):expInfo(info)
{

}
#endif

CException::CException()
{
    expInfo="";
}
CException::~CException() throw()
{

}

const char* CException::what() const throw()
{
    return expInfo.c_str();
}

