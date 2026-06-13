#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


// APPROACH 1

// int main()
// {
//     vector<int> a = {7, 8, 1, 6, 9};
//     vector<int> b = {7, 2, 8, 9, 6};
//     unordered_map<int, int> count;
//     queue<int> q;
//     vector<int> c(a.size() + b.size());
//     vector<int> d;
//     merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());

//     cout<<"printing c"<<endl;
//     for(int i = 0; i < c.size(); i++)
//     {
//         cout << c[i] << " ";
//     }

//     for(int i = 0; i < c.size(); i++)
//     {
//         int num=c[i];
//        if(count[num] == 0)
//         {
//             d.push_back(num);
//         }
//         count[num]++;
//     }
//     cout<<endl<<"Printing d"<<endl;
//     for(int i = 0; i < d.size(); i++)
//     {
//         cout << d[i] << " ";
//     }

//     return 0;
// }


// APPROACH 2

int main()
{
    vector<int> b = {1, 3, 5, 7, 9};
    vector<int> a = {2, 4, 6, 8, 10};
    vector<int> c;
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < a.size() && j < b.size())
    {
        if(a[i] < b[j])
        {
            c.push_back(a[i]);
            i++;
        }
        else
        {
            c.push_back(b[j]);
            j++;
        }
    }
    while(i < a.size())
    {
        c.push_back(a[i]);
        i++;
    }
    while(j < b.size())
    {
        c.push_back(b[j]);
        j++;
    }
    for(k = 0; k < c.size(); k++)
    {
        cout << c[k] << " ";
    }
}




//APPROACH 3



// int main()
// {
//     vector<int> a = {7, 8, 1, 6, 9};
//     vector<int> b = {7, 2, 8, 9, 6
};
//     vector<int> c; 
//     int i = 0;
//     bool flag;
//     for(i = 0; i < a.size(); i++)
//     {
//         c.push_back(a[i]);
//     }
//     for(int j = 0; j < b.size(); j++)
//     {
//         flag = false;
//         for(int k = 0; k < a.size(); k++)
//         {
//             if(b[j] == a[k])
//             {
//                 flag = true;
//                 break;
//             }
//         }
//         if(!flag)
//         {
//             c.push_back(b[j]);
//         }
//     }
//     for(int k = 0; k < c.size(); k++)
//     {
//         cout << c[k] << " ";
//     }
// }
