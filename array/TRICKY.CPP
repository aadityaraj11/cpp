#include <iostream>
#include <string>
#include <cctype> // Include this header for isalpha() and isdigit()
using namespace std;

string btao(string str) 
{
    int count = 0;
    string ans;
    char ch;

    for (int i = 0; i < str.length(); i++) 
    {
        if (isalpha(str[i])) 
        {
            ch = str[i];
            ans=ans+ch;
        } 
        else if (isdigit(str[i])) 
        {
            count = (count * 10) + (str[i] - '0'); // Convert char to int
            if (isdigit(str[i + 1])) 
            {
                count = (count * 10) + (str[i + 1] - '0');
                i++; // Skip the next digit
            }
            // here to avoid loop inside loop we use append function


            // while (count > 0) 
            // {
            //     ans += ch;
            //     count--;
            // }

            
            ans.append(count,str[i+1]);
        }
    }

    return ans;
}

int main() {
    string str = "a1b3c15";
    string ans = btao(str);
    cout << ans << endl;
    return 0;
}
