#include "ComplexFriend.h"

using namespace std;

int main(){
    Complex n1 {10,20};
    Complex n2 {5,15};

    Complex n3 = n1 + n2;
    Complex n4 = n1 - n2;

    cout << n3 << endl;
    cout << n4 << endl;

    Complex n5;
    cout << "Write a complex number --> :";
    cin >> n5;

    cout << n5 << endl;

    cout << "Norm --> " << (int)n5;

    return 0;
}