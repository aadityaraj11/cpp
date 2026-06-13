#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> k(int arr[],int n,int k)
{
    deque<int> de;
    vector<int> ans;
    // for first k element
    for(int i=0;i<k;i++)
    {
        if(arr[i]<0)  
        {
            de.push_back(i); 
        }
    } 
    // store answer of first k sized window
    if(de.size()>0)
    {
        ans.push_back(arr[de.front()]);
        cout<<"yeha dala"<<arr[de.front()]<<endl;      // this line is to check code
    }
    else
    {
        ans.push_back(0);
        cout<<"yeha dala 0"<<endl;       // this line is to check code 
    }
    // rest left element
    for(int i=k;i<n;i++)
    {   
        //removal
        if((!de.empty()) && (i-de.front()>=k)) // the second condition check whether previos element from previous window has been removed or not in our case  (2-1>=2) so 8 i.e arr[0] will be removed from arr
        {
            de.pop_front();
        }   
        //  addition
        if(arr[i]<0)
        {
            de.push_back(i);
        }
        if(de.size()>0)
        {
            ans.push_back(arr[de.front()]);
            cout<<"yeha dala"<<arr[de.front()]<<endl;    // this line is to check code
        }
        else
        {
            ans.push_back(0);
            cout<<"yeha dala 0"<<endl;  // this line is to check code
        }
    }
    return ans;
}
int main()
{
    int arr[5]={-8,2,3,-6,10};
    vector<int> v = k(arr,5,2);
    for(int i=0;i<v.size();i++)
    {
         cout<<v[i]<<endl;
    }
   

}