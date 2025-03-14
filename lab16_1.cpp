#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *d, int N, int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N * M; i++){
        cout << *(d + i);
        if((i + 1) % M == 0) cout << endl;
        else cout << " ";
    }
}

void randData(double *d, int N, int M){
    for(int i = 0; i < N * M; i++){
        *(d + i) = (rand() % 101) / 100.0;
    }
}

void findRowSum(const double *d, double *sum1, int N, int M){
    for(int i = 0; i < N; i++){
        sum1[i] = 0;
        for(int j = 0; j < M; j++){
            sum1[i] += *(d + i * M + j);
        }
    }
}

void findColSum(const double *d, double *sum2, int N, int M){
    for(int j = 0; j < M; j++){
        sum2[j] = 0;
        for(int i = 0; i < N; i++){
            sum2[j] += *(d + i * M + j);
        }
    }
}


int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}