#include<iostream>
#include<cmath>
#include<complex> // std::complex, std::real


#define TYPE double

using namespace std;

int main(int argc, char *argv[]){

int NMAX = 1e6; //max number of terms to include
int a = 1;
int m = 0;
complex<double> b (0.0,1);
complex<double> c (0.0,-1);

TYPE s;
TYPE q;
TYPE sum =1.0;
TYPE negsum =1.0;
TYPE oldsum = 0.0;
TYPE negoldsum = 0.0;
TYPE tol = 1e-15;

cout<<"Give me the value of s (greater than 1)";
cin>>s;
cout<<"Give me the value of q (greater than 0)";
cin>>q; //NOTE: since we do the negative summation here too if q is an integer it'll go to infinity, but converges for numbers such as 4.2

  while( (abs(sum - oldsum)>tol) &&  (a<NMAX) &&  (std::abs(b)<NMAX) && (m>(-NMAX)) && (std::abs(c)>(-NMAX)) ){
  sum = sum + pow((a + std::imag(b) + (q - 1)),-s); //(q-1) done in these lines because it's reading the input q as +1 of the intended input
  negsum = negsum + pow((m + std::imag(c) + (q - 1)),-s);
  a++;
  m--;
  std::imag(b)++;
  std::imag(c)--;
}

cout<<"Number of terms used = "<<NMAX<<endl;
cout<<"GenZeta("<<s<<","<<q<<") = "<<(sum - 1) + (negsum - 1)<<endl;
cout<<"PosGenZeta("<<s<<","<<q<<") = "<<(sum - 1)<<endl;
cout<<"NegGenZeta("<<s<<","<<q<<") = "<<(negsum - 1)<<endl;

  return 0;
  
}
