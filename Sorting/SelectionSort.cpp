#include <iostream>
#define Size 5

using namespace std;
typedef int DataType;

void selectionSort(DataType *array, int size){
    
    int min = 0;
    for(int i = 0;i < size - 1;i++){
        min = i;
        for(int j = i + 1;j < size;j++){
            if(array[j] < array[min])
                min = j;
        }
        
        if(min != i){
            DataType temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}

int main(void){
    
    DataType array[Size] = {1,7,4,6,2};
    selectionSort(array, Size);
    
    for(int i = 0;i < Size;i++){
        cout << array[i] << " ";
    }
    return 0;
}
