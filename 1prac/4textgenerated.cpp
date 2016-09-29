#include <iostream>
#include <wchar.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

double sz = 4000;
const wstring text = L"abcdefghijklmnopqrstuvwxyzáéíóúñ ";


void generate_random_text();
void normalization(vector<float>&v,double &sum);
float shannon_function(vector<float> &v);
float hartley_function(vector<float> &v);
vector <float> get_frecuency(FILE *file);
float sum_array(vector<float>&v);

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "en_US.UTF-8");
	vector<float> numpi;
	float H1,H2,s;
	FILE *file;

	generate_random_text();
	file = fopen("randtext.txt","r");
	numpi = get_frecuency(file);
	
	fclose(file);
	normalization(numpi,sz);
    H1=shannon_function(numpi);
    H2=hartley_function(numpi);
    cout<<"shannon entropy: "<<H1<<endl;
    cout<<"hartley entropy: "<<H2<<endl;
	return 0;
}
void generate_random_text()
{	
	int n;
	wstring str;
	FILE *file;
	file = fopen("randtext.txt","w");
	n = text.size();
	srand(time(NULL));
	for (int i = 0; i <sz ; ++i)
	{
		str.push_back(text[rand()%n]);
	}
	fputws(str.c_str(),file);
	fclose(file);
}
vector <float> get_frecuency(FILE *file)
{
    map<wint_t,int>frec;
    map<wint_t,int>::iterator it;
    vector<float> numpi;
    double sum;
    wint_t wc;
    int f;
    
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
    
    return numpi;
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
