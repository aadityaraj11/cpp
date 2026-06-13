#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTrees(node * root) // Corrected function name
{
    cout<<"Enter the data:"<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1)
    {
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data<<endl; // Corrected syntax
    root->left=buildTrees(root->left); // Corrected function name
    cout<<"Enter the data inserting in right of "<<data<<endl;
    root->right=buildTrees(root->right); // Corrected function name
    return root;
}


void levelorderTraversal(node* root)
{
    if (root == NULL) return; // Check if the tree is empty

    queue<node*> q;
    q.push(root); // Start with the root node

    while(!q.empty())
    {
        int size = q.size(); // Number of nodes at the current level
        while(size > 0) // Process all nodes at the current level
        {
            node* temp=q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
            size--;
        }
        cout<<endl; // End of the current level
    }
}


void reverseLevelOrderTraversal(node* root) {
    if (root == NULL) return; // Check if the tree is empty

    deque<node*> q;
    stack<int> s; // Stack to store int data

    q.push_front(root); // Start with the root node

    while(!q.empty()) {
        node* temp = q.front();
        q.pop_front();
        s.push(temp->data); // Push the node's data to the stack

        // It's important to push the right child first
        if(temp->right) {
            q.push_front(temp->right);

        }
        if(temp->left) {
            q.push_front(temp->left);
        }
    }
    cout<<"revroredr trav"<<endl;
    while(!s.empty()) {
        cout << s.top() << " "; // Print the data of the node
        s.pop();
    }
    cout << endl;
}



void inorder(node* root)
{
    // base case
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root)
{
    // base case
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root)
{
    // base case
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void buildfromlevelorder(node* &root)
{
    queue<node*> q;
    int data;
    cin>>data;

    root=new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();

        cout<<"Enter left node for"<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata!=-1)
        {
            temp->left=new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<<temp->data<<endl;
        int rightdata;
        cin>> rightdata;

        if(rightdata!=-1)
        {
            temp->right=new node(rightdata);
            q.push(temp->right);
        }
    }
}
node* find(node* curr)
{
    node * pred=curr->left;
    while(pred->right!=NULL && pred->right!=curr)
    {
        pred=pred->right;
    }
    return pred;
}

int leaf(node* root, int& count) {
    if (root == NULL) {
        return 0; // Base case: empty subtree has 0 leaves
    }
    if (root->left == NULL && root->right == NULL) {
        count++;
        return 1; // Leaf node found
    }
    // Recurse on left and right subtrees
    int leftLeaves = leaf(root->left, count);
    int rightLeaves = leaf(root->right, count);
    return leftLeaves + rightLeaves; // Total leaves in the subtree
}
int height(node * root,int &ans)
{
    if (root==NULL)
    {
        return 0;
    }
    int left=height(root->left,ans);
    int right=height(root->right,ans);
    ans=max(left,right)+1;
    return ans;
}

void morris(node* &root)
{
    node * curr=root;
    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->right;
        }
        else{
            node * pred=find(curr);
            if(pred->right==NULL)
            {
                pred->right=curr;
                curr=curr->left;
            }
            else
            {
                pred->right=NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }
    }
}

node* flatten(node* root) {
    node* curr = root;
    node* prev = NULL;
    while (curr != NULL) {
        if (curr->left != NULL) {
            prev = curr->left;
            while (prev->right != NULL) {
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;   // Set the left child to NULL
        }
        curr = curr->right;     // Move to the next node
    }
    cout<<"flat kr diya";
    return root;
}


/*
    struct Node {
    int data;
    Node* left;
    Node* right;
};

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    if (!root) return;
    if (root->data == key) {
        if (root->left) {
            pre = root->left;
            while (pre->right) pre = pre->right;
        }
        if (root->right) {
            suc = root->right;
            while (suc->left) suc = suc->left;
        }
    } else if (root->data > key) {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    } else {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

*/
int main()
{
    node* root=NULL;
    //  creating a tree
    // root=buildTrees(root);
    buildfromlevelorder(root);
    reverseLevelOrderTraversal(root);

    cout<<"Inorder traversal"<<endl;
    inorder(root);

    cout<<endl<<"preorder traversal"<<endl;
    preorder(root);

    cout<<endl<<"postorder traversal"<<endl;
    postorder(root);
    int count=0;
    int res=leaf(root,count);
    cout<<endl<<"res"<<res<<endl;

    cout<<endl;
    int ans=0;
    height(root,ans);
    cout<<"ans"<<ans<<endl;

    cout<<endl<<"Morris traversal"<<endl;
    morris(root);
    flatten(root);
    
    cout<<endl<<"postorder traversal"<<endl;
    postorder(root);
    
    cout<<"Inorder traversal"<<endl;
    inorder(root);

    cout<<endl<<"preorder traversal"<<endl;
    preorder(root);


    return 0;
}
