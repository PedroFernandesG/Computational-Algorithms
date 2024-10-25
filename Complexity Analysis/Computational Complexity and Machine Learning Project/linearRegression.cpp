#include <iostream>
#include <cmath>

using namespace std;
typedef double DataType;

pair<DataType, DataType> linearRegression(DataType *x,DataType *y, int size){
    
    DataType logX = 0;
    DataType logY = 0;
    DataType logYlogX = 0;
    DataType logXLogX = 0;
    
    for(int i = 0;i < size;i++){
        
        logX += log(x[i]);
        logY += log(y[i]);
        logYlogX += log(x[i]) * log(y[i]);
        logXLogX += log(x[i]) * log(x[i]);
    }
    DataType b = (size *logYlogX - (logX * logY)) / (size * logXLogX - logX * logX);
    DataType intercept = (logY - b* logX) / size;
    DataType a = exp(intercept);
    
    return make_pair(a,b);
}
int main(void){
    
    DataType x[] = {10, 20, 30, 40, 50 ,60};
    DataType y[] = {222,842,1862,3282,5102,7322};
    
    pair<DataType, DataType> result = linearRegression(x,y,6);
    
    cout << "f(n) : y = " << result.first << " * x^" << result.second << endl;
    
    return 0;
}
