#include <iostream>

using namespace std;

int main() {
    int arr[7];
    for (int i = 0; i < 7; i++) {
        cin >> arr[i];
    }
    int res = arr[0];
    for (int i = 1; i < 7; i++) {
        res = res ^ arr[i];
        cout<<res<<endl;
    }
    cout << "The unique element in the array is: " << res << endl;
    return 0;
}
