#include<iostream>
#include<cmath>


#define TYPE double

using namespace std;

int main(int argc, char *argv[]){

int NMAX = 1e6; //max number of terms to include
int a = 1;

TYPE s;
TYPE q;
TYPE sum =1.0;
TYPE negsum =1.0;
TYPE oldsum = 0.0;
TYPE negoldsum = 0.0;
TYPE tol = 1e-16;


cout<<"Give me the value of s (greater than 1)";
cin>>s;
cout<<"Give me the value of q (greater than 0)";
cin>>q; //NOTE: since we do the negative summation here too if q is an integer it'll go to infinity, but converges for numbers such as 4.2

  while( (abs(sum - oldsum)>tol) &&  (a<NMAX) ){
  sum = sum + pow((a + (q - 1)),-s); //(q-1) done in these lines because it's reading the input q as +1 of the intended input
  a++;
}

cout<<"Number of terms used = "<<NMAX<<endl;
cout<<"HurwitzZeta("<<s<<","<<q<<") = "<<(sum - 1)<<endl;

  return 0;
  
}
