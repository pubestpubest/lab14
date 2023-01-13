#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N, double B[]){
    //mean
    int i=0;
    double sum;
    while(i<N) sum+=A[i++];
    double mean=sum/(double)N;
    B[0]=mean;
    //S.D.
    i=0;
    double sum2=0;
    while(i<N) sum2+=pow(A[i++],2);
    B[1]=sqrt((sum2-(double)N*pow(mean,2))/(double)N);
    //G.M.
    i=0;
    double sum3=1;
    while(i<N) sum3*=A[i++];
    B[2]=pow(sum3,1/(double)N);
    //H.M.
    i=0;
    double sum4=0;
    while(i<N) sum4+=1/A[i++];
    B[3]=(double)N/sum4;
    //MinMax
    i=0;
    double min=999999,max=0;
    while(i<N){
        if(min>A[i]) min=A[i];
        if(max<A[i]) max=A[i];
        i++;
    }
    B[4]=max;
    B[5]=min;
}