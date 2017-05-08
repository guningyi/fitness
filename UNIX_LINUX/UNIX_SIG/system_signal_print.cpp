#include <iostream>
#include <signal.h>

using namespace std;

class CSignal{
public:
  CSignal();
  virtual ~CSignal();
  void show_signal();
private:
  int num;
};

CSignal::CSignal()
{
  this->num = 0;
  cout<<"CSignal constructor!"<<endl;
}

CSignal::~CSignal()
{
  cout<<"CSignal destructor!"<<endl;
}

void CSignal::show_signal()
{
  cout<<"SIGCHLD="<<SIGCHLD<<endl;
  cout<<"SIGCONT="<<SIGCONT<<endl;
  cout<<"SIGSTOP="<<SIGSTOP<<endl;
  cout<<"SIGTSTP="<<SIGTSTP<<endl;
  cout<<"SIGTTIN="<<SIGTTIN<<endl;
}



int main(int argc, char **argv)
{
  CSignal sig;
  sig.show_signal();
  return 1;
}


