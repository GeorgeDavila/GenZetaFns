#include<iostream>
#include<stdlib.h> // atof is in this library...
#include<fstream>
#include<cmath>
#include<ctime>
//#include<tgmath.h>

using namespace std;
double pi = 3.141592653589793;
double s;
double q;

double myfunc(double *x);

double myfunc2(double x);
double newfunc(double x);

double mean(double *x,int len);
double stdev(double *x,double xm, int len);

double mean(double *x,int len){
  double sum = 0.0;
  
  for(int i=0;i<len;i++){
    sum += x[i];
  }
  sum /= (double)len;
  return sum;
}

double stdev(double *x, double xm, int len){
  double sum = 0.0;
  
  for(int i=0;i<len;i++){
    sum += pow(x[i]-xm,2);
  }
  sum /= (double)len;
  return sqrt(sum);
}

double myfunc2(double x){
  return exp(-q*x)/(1 - exp(-x));
}
double newfunc(double x){
  return pow(x,(s - 1));
}

int main(int argc, char *argv[]){
  
  int seed;
  double r;
  double *x, *y;
  double xmag = 0.0;
  int N, d;
  int M = 1000;
  int h = 0;
  double a,b;
  double *areas;
  double ave, err;
  clock_t start, stop;
  
  //int s;
  //int q;

  cout<<"Give me the value of s ";
  cin>>s;

  cout<<"Give me the value of q ";
  cin>>q;
  
  
  a = 0.;
  b = 1e6;
  
  if(argc<2){
    N = 100000;
    cout<<"N = "<<N<<endl;
  }
  else{
    N = atoi(argv[1]);
  }

  double area;

  seed = 100;//time(NULL);
  srand(seed);// "Seed the random number generator"
  
  x = new double [1]; 
  y = new double [1]; 
  areas = new double [M];
  
  start = clock();
  
  for(int k=0;k<M;k++){
    areas[k] = 0.0;
    for(int i=0;i<N;i++){
      xmag = 0.0;
      for(int j=0;j<1;j++){
        r = ((double) rand())/((double)RAND_MAX);
        x[j] = r*(b - a) + a; // 0 < x[j] < 1
        y[j] = -log(1-x[j]/b); // 0 < x[j] < 1
      }
      areas[k] += newfunc(y[0]);
    }// end of for i loop
    areas[k] /= ((double) N);

  } // end of for k loop
  delete y;
  delete x;
  
  stop = clock();
  
  double totaltime = (stop - start)/((double)CLOCKS_PER_SEC);
  
  ave = mean(areas,M);
  err = stdev(areas,ave,M)/sqrt((double)M - 1.);
  delete areas;
  
  cout<<"The integral is "<<ave<<"+/-"<<err<<endl;

//  cout<<"It should be "<<pi<<endl;
  
  return 0;
}
