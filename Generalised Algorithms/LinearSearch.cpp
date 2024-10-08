#include <iostream>
#define Size 5

using namespace std;
typedef char DataType;

int linearSearch(DataType *array, int size, DataType x){
    
    for(int i = 0;i < size;i++){
        if(array[i] == x)
            return i;
    }
    return -1;
}

int main(void){

    DataType x;
    DataType array[Size] = {'A', 'G', 'H', 'J', 'C'};
    
    cout << "type in which element you want to find: " << endl;
    cin >> x;
    
    return linearSearch(array,Size,x);
}
