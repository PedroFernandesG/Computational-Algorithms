#include <iostream>
using namespace std;

int main(void){
    
    string line;
    int count = 1,big = 1;
    getline(cin, line);
    char letter = line[0];
    
    for(int i = 1;i < line.length();i++){
        
        if(line[i] == letter)
            count++;
        else{
            letter = line[i];
            if(count > big) big = count;
            count = 1;
        }
    }
    if(count > big) big = count;   
    
    cout << big << endl;
    return 0;
}