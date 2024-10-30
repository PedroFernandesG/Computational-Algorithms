#include "Complex.h"

using namespace std;

int main(){
    Complex n1 {10,20};
    Complex n2 {5,15};

    Complex n3 = n1 + n2;
    Complex n4 = n1 - n2;

    if(!(!n3 && !n4)){
        cout << "n3 and n4 are not empty" << endl;
    }

    n3.print();
    n4.print();

    Complex n5 = ++n4;
    Complex n6 = n3++;

    n5.print();
    n6.print();

    return 0;
}
