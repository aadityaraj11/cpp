// #include<iostream>
// using namespace std;
// int main()
// {
//     int n;
//     bool flag=false;
//     while(!flag)
//     {
//         cout<<"enter number between 2 and 7:";
//         cin>>n;
//         if(n<=2||n>=7)
//         {
//             cout<<"not a valid number";
//         }
//         else{
//             cout<<"you have entered"<<n;
//             flag=true;
//         }
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int t;
//     cin>>t;
//     for(int i=0;i<t;i++)
//     {
//         int x,y,r;
//         cin>>x>>y>>r;
//         if(r==0)
//         {
//             cout<<x/y+1<<endl;
//         }
//         else
//         {
//             r=r/30;
//             x=x+r;
//             if(y==1)
//             {
//                 cout<<x<<endl;
//             }
//             else
//             {
//                 cout<<x/y+1<<endl;
//             }
//         }
//     }
//     return 0;
// }



// #include<iostream>
// #include<vector>
// using namespace std;
// int main() {
//     vector<string> input;
//     string temp;
//     int t;
//     cin>>t;
//     for(int i=0;i<t;i++)
//     {
//     // Read input strings into the vector
//         cin >> temp;
//         input.push_back(temp);
//         string count=to_string(input.size()-2);
//         cout<<input[0]<<count<<input[input.size()-1];
//         return 0;
//     }
// }



// #include <stdio.h>

// #define MAX 100

// struct SparseMatrix {
//     int row;
//     int col;
//     int value;
// };

// int main() {
//     int matrix[4][4] = {
//         {0, 0, 3, 0},
//         {22, 0, 0, 0},
//         {0, 0, 0, 0},
//         {0, 7, 0, 5}
//     };

//     struct SparseMatrix sparse[MAX];
//     int k = 0;

//     // Convert to sparse matrix representation
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < 4; j++) {
//             if (matrix[i][j] != 0) {
//                 sparse[k].row = i;
//                 sparse[k].col = j;
//                 sparse[k].value = matrix[i][j];
//                 k++;
//             }
//         }
//     }

//     // Print sparse matrix representation
//     printf("Sparse Matrix Representation:\n");
//     printf("Row Column Value\n");
//     for (int i = 0; i < k; i++) {
//         printf("%d    %d    %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
//     }

//     return 0;
// }




#include <stdio.h>

#define MAX 11 // Maximum degree + 1

void addPolynomials(int A[], int B[], int result[], int maxDegree) {
    for (int i = 0; i < maxDegree; i++) {
        result[i] = A[i] + B[i];
    }
}

int main() {
    int A[MAX] = {0}; // Initialize all coefficients to 0
    int B[MAX] = {0}; // Initialize all coefficients to 0
    int result[MAX] = {0}; // Initialize all coefficients to 0

    // Polynomial A(x) = 2x^10 + 1
    A[10] = 2;
    A[0] = 1;

    // Polynomial B(x) = x^4 + 10x^3 + 3x^2 + 1
    B[4] = 1;
    B[3] = 10;
    B[2] = 3;
    B[0] = 1;

    // Add the polynomials
    addPolynomials(A, B, result, MAX);

    // Print the result
    printf("Resultant Polynomial: ");
    for (int i = MAX - 1; i >= 0; i--) {
        if (result[i] != 0) {
            printf("%dx^%d ", result[i], i);
            if (i > 0) {
                printf("+ ");
            }
        }
    }
    printf("\n");

    return 0;
}
