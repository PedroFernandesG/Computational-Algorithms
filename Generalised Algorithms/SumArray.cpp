#include <iostream>
#define Size 5

using namespace std;
typedef int DataType;

DataType SumArray(DataType *array, int size){
    
    int sum = 0;
    for(int i = 0;i < size;i++){
        sum += array[i];
    }
    return sum;
}

int main(void){

    DataType array[Size] = {1,5,7,89,34};
    DataType sum = SumArray(array,Size);
    
    cout << "Sum --> " << sum << endl;
}
