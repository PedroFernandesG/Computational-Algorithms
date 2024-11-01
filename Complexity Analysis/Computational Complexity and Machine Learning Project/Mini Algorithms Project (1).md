## Let's now use the scientific method to mathematically model our cost function our algorithm receives two vectors and compares how many equal elements there are between the positions of the vectors in the algorithm below using the scientific combinatorial method we add a count variable to count the instructions carried out in the programme

```
def function():
    qtd = []
    numberItem = [10,20,30,40,50,60]
    
    for n in numberItem:
        count = 0
        list1 = range(n)
        list2 = range(n)
        find = False
        
        count +=1
        for i in range(n):
            count+=1
            for j in range(n):
                count+=1
                count+=1
                if(list1[i] == list2[j]):
                    find=True
            count+=1
        count+=1
        qtd.append(count)
    return qtd
```
### We see that the output when comparing two equal vectors (we want the worst case) of sizes 10, 20,...60 is as follows


|Size  | Instructions |
|------|--------------|
| 10   |     222      |
| 20   |     842      |
| 30   |     1862     |
| 40   |     3282     |
| 50   |     5102     |
| 60   |     7322     |

### Here's some C++ code to check the results

``` cpp
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
```
## From this experiment can we predict the value for n =80? yes we can, because we will use the log-log graph from a certain table, as can be seen below we have a line in the Cartesian plane, we can also see that the slope of the line is approximately 2, so we can infer that our cost function can be approximated by a quadratic function.

``` py
import matplotlib.pyplot as plt
import math

# Data
x = [10, 20, 30, 40, 50 ,60]
y = [222,842,1862,3282,5102,7322]

#Plot log-log
plt.loglog(x, y, marker='o', linestyle='--', color='b')

plt.title("Plot Log-Log")
plt.xlabel("X (Scale Log)")
plt.ylabel("Y (Scale Log)")

#Show 
plt.grid(True, which="both", linestyle="--")
plt.show()

deltaX = math.log10(x[2]) - math.log10(x[1])
deltaY = math.log10(y[2]) - math.log10(y[1])
print("Inclination --> ")
print(deltaY/deltaX)
# We see that the slope of the line is approximately 2, which means that the cost function can be considered a quadratic function

```
![image](https://github.com/user-attachments/assets/39d4c6c8-70e6-4675-84ee-b2390d3cb727)

## Let's say that now the interesting part begins, let's think that we can approximate the cost function to a quadratic function, but what if we want to determine the coefficients a and b of the cost function f(n) = a*x^b, how can we do that? the answer can be obtained using machine learning algorithms, let's use a linear regression to solve this problem, let's unite our knowledge of algorithms and learning to arrive at an answer, first let's infer and mathematically demonstrate the linear regression equations for this problem

## Firstly, our cost function is of the form: $\gamma = \alpha * x^{b}$

## Let's transform it into a linear function using logarithms 

### $$\gamma =\log(\alpha* x^{b})$$
### $$\gamma =\log(\alpha) + \log(x^{b})$$
### $$\gamma =\log(\alpha) + \log(x^{b})$$
### $$\gamma =\log(\alpha)+ b*\log(x)$$

### This gives us a linear equation, da forma: $$Y = b*x + c$$

## Our idea here is to use the Gauss least squares method to calculate the quadratic error between the transformed points, let's minimise the error function

### $$E_{i} = Y_{i} - (b *X_{i} + c)$$
### $$S = \sum_{i = 1}^{n} (Y_{i} - (b *X_{i} + c))^{2}$$

## We see that the function depends on the coefficients b and c, from multivariable calculus we know that to minimise the function we need to take its partial derivatives and equal them to zero.


### $`\frac{\partial S}{\partial b} = \sum_{i = 1}^{n}2*(Y_{i} - (b *X_{i} + c))*\frac{\partial }{\partial b}(Y_{i} - (b *X_{i} + c))`$

### $$\frac{\partial S}{\partial b} = -2\sum_{i = 1}^{n}X_{i}*(Y_{i} - (b *X_{i} + c))$$

### $$-2\sum_{i = 1}^{n}X_{i}*(Y_{i} - (b *X_{i} + c)) = 0$$

### $`\sum_{i = 1}^{n}X_{i} *Y_{i} = b*\sum_{i =1}^{n}X_{i}^{2} + c\sum_{i=1}^{n}X_{i}`$

## Now for another variable

### $`\frac{\partial S}{\partial c} = \sum_{i = 1}^{n}2*(Y_{i} - (b *X_{i} + c))*\frac{\partial }{\partial c}(Y_{i} - (b *X_{i} + c))`$

### $$\frac{\partial S}{\partial c} = -2\sum_{i = 1}^{n}(Y_{i} - (b *X_{i} + c))$$

### $$-2\sum_{i = 1}^{n}(Y_{i} - (b *X_{i} + c)) = 0$$

### $$\sum_{n =1}^{n}Y_{i} = b*\sum_{i=1}^{n}X_{i} + n*c$$

## We need to isolate b and c, we have a system of two equations

### 1. $`\sum_{i = 1}^{n}X_{i} *Y_{i} = b*\sum_{i =1}^{n}X_{i}^{2} + c\sum_{i=1}^{n}X_{i}`$
### 2. $$\sum_{n =1}^{n}Y_{i} = b*\sum_{i=1}^{n}X_{i} + n*c$$

## From (2)

### $$\sum_{n =1}^{n}Y_{i} = b*\sum_{i=1}^{n}X_{i} + n*c$$

### $$\sum_{n =1}^{n}Y_{i} - b*\sum_{i=1}^{n}X_{i} =  n*c$$

### 3. $$c =\frac{ \sum_{n =1}^{n}Y_{i} - b*\sum_{i=1}^{n}X_{i}}{n}$$

## (3) in (2)

### $`\sum_{i = 1}^{n}X_{i} *Y_{i} = b*\sum_{i =1}^{n}X_{i}^{2} + (\frac{ \sum_{n =1}^{n}Y_{i} - b*\sum_{i=1}^{n}X_{i}}{n})*\sum_{i=1}^{n}X_{i}`$

### $`\sum_{i = 1}^{n}X_{i} *Y_{i} = b*\sum_{i =1}^{n}X_{i}^{2} + \frac{1}{n}(\sum_{i = 1}^{n}Y_{i}*\sum_{i = 1}^{n}X_{i} - b*(\sum_{i = 1}^{n}X_{i})^{2})`$

### $`b*\sum_{i=1}^{n} - \frac{b}{n}*(\sum_{i=1}^{n}X_{i})^{2} = \sum_{i=1}^{n}(X_{i}*Y_{i}) - \frac{1}{n}\sum_{i=1}^{n}Y_{i}*\sum_{i=1}^{n}X_{i}`$

### $`b = \frac{n*\sum_{i=1}^{n}(X_{i}*Y_{i}) - \sum_{i=1}^{n}Y_{i}*\sum_{i=1}^{n}X_{i}}{n*\sum_{i=1}^{n}X_{i}^{2} -(\sum_{i=1}^{n}X_{i})^{2}}`$

## We have developed an algorithm in c++ to find the function

``` cpp

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

```
### The intercept C that we find with linear regression is ln(a), i.e. the natural logarithm of the model's original a coefficient. As our aim is to return to the original (non-logarithmic) space, we need to ‘undo’ the logarithm by applying the exponential: a = exp(C)

### $$b = \frac{n\sum_{}^{}(log(x)*log(y)) - \sum_{}^{}log(x) *\sum_{}^{}log(y)}{n\sum_{}^{} log(x)^{2} - (\sum_{}^{}log(x))^{2}}$$

### $$intercept = \frac{\sum_{}^{}log(y) - b\sum_{}^{}log(x)}{n}$$

### $$a = exp(intercept)$$

## So running the algorithm we get our cost function: $$f(n) = 2.46  * n^{1.95}$$

### we can use it to get good approximations of the number of instructions the programme will carry out knowing the size of the input (in the worst case).







