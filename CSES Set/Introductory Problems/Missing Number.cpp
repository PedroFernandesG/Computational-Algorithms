#include <iostream>
using namespace std;

int main(){

    int n; string line; int last = 0;int count = 0;
    cin >> n;
    cin.ignore();

    int vetor[n] = {0};
    getline(cin, line);
    
    if(n > 2){

        for(int i = 0;i < line.length();i++){
            if(line[i] == ' '){
              string sub1 = line.substr(last,i - last); last = i+1;
              vetor[stoi(sub1) - 1] = 1;
              count++;
            }

            if(count == n - 2){
               string sub1 = line.substr(i+1);
               vetor[stoi(sub1) - 1] = 1;
               break;
            }

        }
    
        for(int i =0;i < n;i++){
            if(vetor[i] == 0){
                cout << i + 1 << endl;
                return 0;
            }
        }
        
    }else{
        if(line[0] == '1')
            cout << 2 << endl;
        else
            cout << 1 << endl;
    }
}