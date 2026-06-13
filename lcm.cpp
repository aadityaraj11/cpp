//  first approch iterative 
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    // Calculate greatest common divisor (GCD)
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    // Calculate LCM using GCD
    return (a * b) / gcd(a, b);
}

int main() {
    int num1 = 15, num2 = 20;
    cout << "LCM of " << num1 << " and " << num2 << " is " << lcm(num1, num2) << endl;
    return 0;
}




// second approach library
#include <iostream>
#include <numeric>
using namespace std;

int main() {
    cout << "LCM(10, 20) = " << lcm(10, 20) << endl;
    return 0;
}





// third approach efficient approach
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int num1 = 15, num2 = 20;
    cout << "LCM of " << num1 << " and " << num2 << " is " << lcm(num1, num2) << endl;
    return 0;
}

