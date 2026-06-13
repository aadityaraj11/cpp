// this code  uses push operation to implement queue as a stack
// #include <iostream>
// #include <queue>

// class Stack {
// private:
//     std::queue<int> q1, q2;

// public:
//     void push(int x) {
//         q2.push(x);
//         while (!q1.empty()) {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         q1.swap(q2);
//     }

//     int pop() {
//         int result = q1.front();
//         q1.pop();
//         return result;
//     }
//     int top() {
//         return q1.front();
//     }

//     int size() {
//         return q1.size();
//     }
// };

// int main() {
//     Stack s;
//     s.push(1);
//     s.push(3);
//     std::cout << "Current size: " << s.size() << std::endl;
//     std::cout << "Top element: " << s.top() << std::endl;
//     return 0;
// }



//  this code uses pop opertaion to implement queue as a stack 
#include <iostream>
#include <queue>
class Stack {
private:
    std::queue<int> q1, q2;
public:
    void push(int x) {
        q1.push(x);
    }

    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int result = q1.front();
        q1.pop();
        q1.swap(q2);
        return result;
    }

    int top() {
       while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int result = q1.front();
        return result;
    }

    int size() {
        return q1.size();
    }
};
int main() {
    Stack s;
    s.push(1);
    s.push(3);
    std::cout << "Current size: " << s.size() << std::endl;
    std::cout << "Top element: " << s.top() << std::endl;
    return 0;
}