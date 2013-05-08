#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef map< string,int >::value_type valType;

int main(int argc, char **argv)
{
   int i = 1;
   map<string, int> wordCount;
   wordCount.insert(valType(string("Ivan") ,1));
   cout<<"wordCount.Ivan="<<wordCount["Ivan"]<<endl; 

   
   wordCount.insert(valType(string("pmcounter") ,2));
   wordCount.insert(valType(string("alarm") ,3));
   wordCount.insert(valType(string("event") ,4));

   typedef map<string,int> tmap;
   tmap::iterator iter = wordCount.begin();
   tmap::iterator iter_end = wordCount.end();

   while(iter != iter_end)
   {
     cout<<"wordCount["<<(*iter).first<<"]="<<(*iter).second<<endl;
     iter++;
   }
   
   return 1;

}
