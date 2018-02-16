#include<iostream>
#include<cmath>
#include<complex> // std::complex, std::real

#define TYPE double

using namespace std;


int main(int argc, char *argv[]){

int NMAX = 1e6; //max number of terms to include
int a = 1;
int A = 1;
int m = 0;
int M = 0;
complex<double> b (0.0,1);
complex<double> c (0.0,-1);

TYPE k;
TYPE r;
TYPE sum =1.0;
TYPE Gsum =1.0;
TYPE negsum =1.0;
TYPE Gnegsum =1.0;
TYPE oldsum = 0.0;
TYPE Goldsum = 0.0;
TYPE negoldsum = 0.0;
TYPE Gnegoldsum = 0.0;
TYPE tol = 1e-15;

cout<<"Give me the value of k (k>0, negative already incorporated into program)";
cin>>k;
cout<<"Give me the value of r (greater than 0)";
cin>>r; //NOTE: since we do the negative summation here too if (r+1) is an integer it'll go to infinity, but converges for numbers such as 4.2

  while( (abs(Gsum - Goldsum)>tol) &&  (A<NMAX) &&  (std::abs(b)<NMAX) && (M>(-NMAX)) && (std::abs(c)>(-NMAX)) ){ //Gen
  Gsum = Gsum + pow((A),k); //((r+1)-1) done in these lines because it'k reading the input (r+1) as +1 of the intended input
  Gnegsum = Gnegsum + pow((M),k);
  A++;
  M--;
  std::imag(b)++;
  std::imag(c)--;
}

  while( (abs(sum - oldsum)>tol) &&  (a<NMAX) && (m>(-NMAX)) ){ //Real
  sum = sum + pow((a + ((r+1) - 1)),k); //((r+1)-1) done in these lines because it'k reading the input (r+1) as +1 of the intended input
  negsum = negsum + pow((m + ((r+1) - 1)),k); 
  a++;
  m--;
}

cout<<"Number of terms used = "<<NMAX<<endl;
cout<<"k-Sum of Zeta("<<k<<") - HurwitzZeta("<<k<<","<<r + 1<<") = "<<(Gsum - 1) - (sum - 1)<<endl;

  return 0;
  
}