#include <iostream>

using namespace std;
typedef int DataType;

void insertionSort(DataType *list, int size){

    int j = 0;
    for(int i = 1;i < size;i++){
        int key = list[i];

        j = i - 1;
        while(j >= 0 && list[j] > key){
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = key;
    }
}
int main(void){

    int size = 10;
    DataType list[size];

    for(int i = 0;i < size;i++){
        cout << "Enter the index element " << i + 1 << ":";
        cin >> list[i];
    }
    insertionSort(list, size);

    for(int i = 0;i < size;i++) cout << list[i] << " ";
}
