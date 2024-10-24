/******************************************************************************

In Asymptotic Computational Complexity we are interested in describing by means of a function 
the number of steps a given algorithm takes for a given input namespace

We can simply do this combinatorially, i.e. by counting the steps
  
Let's take the Sum Function as an example 

def sumFunction(vector):
    
    sum = 0 (1) //Executed once
    for item in vector: (n+1) //Executed for each element of the vector plus one from the Stop check
        sum += item (n) //Sum each element of the vector
    return sum (1) //Return at the end
    
summing everything our function f(n) is --> f(n) = 2n + 3

*For an input of size 8 we have f(8) = 19
*If the algorithm below is executed, we see that the method applied using counters is confirmed.

*******************************************************************************/

#include <iostream>
using namespace std;

int count = 0;

typedef int DataType;

DataType sum(DataType *array){
 
    DataType sum = 0; count ++;
    for(int i = 0;i < sizeof(array);i++,count++){
        sum += array[i]; count ++;
    }count ++;
    
    count++; return sum; 
}
int main(void)
{
    DataType array[] = {1,4,6,8,5,6,3,4};
    cout << "Sum --> " << sum(array) << endl;
    cout << "Counter instructions --> " << count << endl;
}
