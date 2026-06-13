#include<iostream>
#include<vector>
using namespace std;

// INTERSECTION IN SORTED ARRAY 


// int main()
// {
//     int arr1[5]={1,2,3,4,5};
//     int arr2[3]={2,2,3};
//     int i=0;
//     int j=0;
//     while(i<5&&j<3)
//     {
//         if(arr1[i]<arr2[j])
//         {
//             i++;
//         }
//         else if(arr1[i]==arr2[j])
//         {
//             cout<<arr1[i]<<" ";
//             i++;
//             j++;
//         }
//         else
//         {
//             j++;
//         }
//     }
//     return 0;
// }

// INTERSECTION IN  UNSORTED ARRAY

int main()
{
    vector<int> a = {3,5,10,4,6};
    vector<int> b = {12,4,7,2,5};
    vector<int> c; 
    int i = 0;
    bool flag;
    for(int j = 0; j < b.size(); j++)
    {
        flag = false;
        for(int k = 0; k < a.size(); k++)
        {
            if(b[j] == a[k])
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            c.push_back(b[j]);
        }
    }
    for(int k = 0; k < c.size(); k++)
    {
        cout << c[k] << " ";
    }
}