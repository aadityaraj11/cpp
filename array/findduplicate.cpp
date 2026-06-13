#include <iostream>

using namespace std;

int main() {
    int arr[7];
    for (int i = 0; i < 7; i++) {
        cin >> arr[i];
    }
    int res = arr[0];
    cout<<"in first loop";
    for (int i = 1; i < 7; i++) {
        res = res ^ arr[i];
        cout<<endl<<res<<endl;
    }
    cout<<"in second loop";
    for(int i=1;i<=7;i++)
    {
        res=res^i;
        cout<<endl<<res<<endl;
    }
    cout << "The duplicate element in the array is: " << res << endl;
    return 0;
}

// #include <iostream>
// using namespace std;

// int main() {
//     int arr[7];
//     for (int i = 0; i < 7; i++) {
//         cin >> arr[i];
//     }
//     int res = 0; // Initialize 'res' to 0 for the XOR operation.
    
//     // XOR all elements in the array.
//     for (int i = 0; i < 7; i++) {
//         res ^= arr[i];
//     }
    
//     // XOR the result with numbers from 1 to 'n'.

//     for(int i = 1; i <= 7; i++) {
//         res ^= i;
//     }

    
//     cout << "The duplicate element in the array is: " << res << endl;
//     return 0;
// }

