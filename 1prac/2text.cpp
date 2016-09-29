#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <locale.h>
#include <wchar.h>
#include <map>

using namespace std;
void normalization(vector<float>&v,double &sum);
float shannon_function(vector<float> &v);
float hartley_function(vector<float> &v);

int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");
    map<wint_t,int>frec;
    map<wint_t,int>::iterator it;
    vector<float> numpi;
    double H1,H2,sum;
    wint_t wc;
    int f;

    FILE * file;
    file=fopen ("doc.txt","r");
    
    //read file and count the occurrence of the characters (á,é,í,ó,ú and space)
    while((wc=getwc(file))!=EOF)
    {
        if(iswalpha(wc)) 
        {
            wc = towlower(wc);
            it = frec.find(wc);
            if(it->second)
            {
                it->second++;
            }
            else
            {
                f=0;
                frec.insert(make_pair(wc,++f));
            }
        }
        else if(wc == 32)
        {
            it = frec.find(wc);
            if(it->second)
            {
                it->second++;
            }
            else
            {
                f=0;
                frec.insert(make_pair(wc,++f));
            }
        }
        
    }
    for (map<wint_t,int>::iterator it=frec.begin(); it!=frec.end(); ++it)
    {
        numpi.push_back(it->second);
        sum+=it->second;
        printf("%lc %i\n",it->first,it->second); //print the character and their frecuency
    }
    
    normalization(numpi,sum);
    H1=shannon_function(numpi);
    H2=hartley_function(numpi);
    cout<<"shannon entropy: "<<H1<<endl;
    cout<<"hartley entropy: "<<H2<<endl;
   
    return 0;
}
void normalization(vector<float>&v,double &sum)
{
    for(vector<float>::iterator it=v.begin();it!=v.end();it++)
        *it = *it/sum;
}
float shannon_function(vector<float> &v)
{
    float H,s=0.0;
    for (vector<float>::iterator it = v.begin(); it!=v.end(); ++it)
        s+=(*it)*log2(1/(*it));
    return s;
}
float hartley_function(vector<float> &v)
{
    int n;
    float r=0.0;
    n = v.size();
    r=log2(n);
    return r;
}
