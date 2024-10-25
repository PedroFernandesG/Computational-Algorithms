#include <iostream>
using namespace std;

int main(void){
    
    int size = 6;
    int vector[size];
    int numbers[size] = {10,20,30,40,50,60};
    int count;
    
    for(int i = 0;i < size;i++){
        count = 0;
        int list1[numbers[i]];
        int list2[numbers[i]];
        
        for(int j = 0;j < numbers[i];j++){
            list1[j] = j;
            list1[j] = j;
        }
        bool find = false;
        count++;
        for(int k = 0;k < numbers[i];k++){
            count++;
            for(int p = 0;p < numbers[i];p++){
                count++;
                count++;
                if(list1[k] == list2[p])
                    find=true;
            }
            count++;
        }
        count++;
        numbers[i] = count;
    }
    for(int i = 0;i < size;i++)
        cout << numbers[i] << endl;
        
    return 0;
}
