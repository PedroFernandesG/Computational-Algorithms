#include <iostream>
#define Size 10

using namespace std;
typedef int DataType;

int binarySearch(DataType *array, int n, DataType x){
    
    int left = 0;
    int right = n - 1;
    
    while(left <= right){
        int mid = (left + right)/2;
        
        if(array[mid] == x)
            return mid;
        else if(array[mid] > x)
            right = mid + 1;
        else if(array[mid] < x)
            left = mid + 1;
    }
    return -1;
}

int main(void){
    
    DataType array[Size] = {1,7,8,15,23,28,39,51,67,89};
    DataType key = 67;
    return binarySearch(array, Size,key);
}
