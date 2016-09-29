#include <iostream>
#include <map>
using namespace std;
int main ()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  mymap['a']=1;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;
    it=mymap.find('a');
    for (int i = 0; i < 4; ++i)
    {
        if(it->second)
        {
            it->second++;
        }
    }
  cout<<it->second<<endl;

  
  /*if (it != mymap.end())
    mymap.erase (it);

  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('a')->second << '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';
  std::cout << "d => " << mymap.find('d')->second << '\n';*/

  return 0;
}