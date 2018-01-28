#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

int max(int num1, int num2) {
   
    int result;
    result = (num1 > num2 ? num1 : num2);
    
    return result;
}

int main () {
    
    srand (time(NULL));
    
    int x, y;
    x = rand() % 100;
    y = rand() % 100;
    cout << "Value of x is: " << x << endl;
    cout << "Value of y is: " << y << endl;
    cout << "Max value is: " << max(x,y) << endl;
    return 0;
}
