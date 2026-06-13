#include<iostream>
using namespace std;
class shop
{
    int itemid[100];
    int itemprice[100];
    int noofitem;
    public:
        void intitcounter(void);
        // void getprice(void);
        void setprice(void);
        void displayprice(void);
};
void shop :: intitcounter(void)
{
     cout<<"Enter no of items"<<"\n";
     cin>>noofitem;
}
void shop :: setprice(void)
{
    for(int i=0;i<noofitem;i++)
    {
    cout<<"Enter Id of your item no"<<i+1<<endl;
    cin>>itemid[i+1];
    cout<<"Enter price of your item"<<endl;
    cin>>itemprice[i+1];
    }
}
 
void shop :: displayprice(void)
{
    for(int i=0;i<noofitem ;i++)
    {
        cout<<"The price of item of ID.>"<<itemid[i+1]<<"is"<<itemprice[i+1]<<endl;

    }
}

int main()
{
    shop dukan;
    dukan.intitcounter();
    dukan.setprice();
    dukan.displayprice();
return 0;
}