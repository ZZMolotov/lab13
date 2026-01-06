#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double x[], int y, double z[]){
    double sum = 0.;
    double GM = 1;
    double HMsum = 0;
    double max = x[0];
    double min = x[0];
    double SD = 0;
    for(int i = 0; i< y;i++ ){
        sum+= x[i];
    }
    z[0] = sum/y;

    for(int i = 0; i<y; i++){
        SD += pow(x[i]-z[0],2);
    }
    z[1] = sqrt(SD/y);

    for(int j = 0; j < y; j++){
        GM *= x[j];
    }
    z[2] = pow(GM,1.0/y);

    for(int k = 0; k < y; k++){
        HMsum += 1/(x[k]);
    }
    z[3] = y/HMsum;

    for(int h = 1; h< y;h++){
        if(x[h] > max){
            max = x[h];
        }
    }
    z[4] = max;

    for(int h = 1; h< y;h++){
        if(x[h] < min){
            min = x[h];
        }
    }
    z[5] = min;
}