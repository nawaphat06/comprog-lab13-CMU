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

void stat(const double A[], int N, double B[]){
    double sum_art_mean, sum_std, sum_geo = 1, sum_harmo, min = A[0] , max = 0;
    int n = 0;
    for(int i = 0; i < N; i++){
        if(A[i] < min) min = A[i];
        else if(A[i] > max) max = A[i];
        sum_art_mean += A[i];
        n++;
    }
    B[0] = sum_art_mean/n;

    for(int i = 0; i < N; i++){
        sum_std += pow(A[i] - B[0], 2);
    }
    B[1] = sqrt( 1.0/n * sum_std);

    for(int i = 0; i < N; i++){
        sum_geo *= A[i];
    }
    B[2] = pow( sum_geo , 1.0/n);

    for(int i = 0; i < N; i++){
        sum_harmo += 1.0/A[i];
    }
    B[3] = n/sum_harmo;

    B[4] = max;

    B[5] = min;


}
