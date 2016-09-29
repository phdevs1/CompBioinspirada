#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;
float shannon_function(vector<float> &v);
float hartley_function(vector<float> &v);

int main(int argc, char const *argv[])
{
	vector<float> vec;
	int size,val;
	float sum = 0.0,d = 0.0,H1,H2;
	cout<<"enter size of array: ";
	cin>>size;
	srand(time(NULL));
	//fill the vector with random values
	for (int i = 0; i < size; ++i)
	{
		val = rand()%100+1;
		vec.push_back(val);
		sum+=vec[i];
	}
	//vector that the sum is equal to 1 (normalization)
	cout<<"vector: ";
	for (int i = 0; i < size; ++i)
	{
		vec[i] = vec[i]/sum;
		cout<< vec[i]<<" ";
		d= d+vec[i];
	}
	cout<<"\nsum total p(i): "<<d <<endl;
	H1= shannon_function(vec);
	cout<<"shanon entropy: "<<H1<<endl;
	H2 = hartley_function(vec);
	cout<<"hartley entropy: "<<H2<<endl;
	return 0;
}
float shannon_function(vector<float> &v)
{
	float H,s=0.0;
	for (vector<float>::iterator it = v.begin(); it!=v.end(); ++it)
	{
		s+=(*it)*log2(1/(*it));
	}
	return s;
}
float hartley_function(vector<float> &v)
{
	int n;
	float r;
	n = v.size();
	r=log2(n);
	return r;
}