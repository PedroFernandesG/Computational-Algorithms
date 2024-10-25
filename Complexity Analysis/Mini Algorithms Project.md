### Let's now use the scientific method to mathematically model our cost function our algorithm receives two vectors and compares how many equal elements there are between the positions of the vectors in the algorithm below using the scientific combinatorial method we add a count variable to count the instructions carried out in the programme

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
