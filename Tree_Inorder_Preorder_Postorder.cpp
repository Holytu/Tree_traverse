#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int value;
    struct Node* left;
    struct Node* right;
};
void Preorder(struct Node* n)
{
    if(n != NULL)
    {
        cout<<n->value<<" ";
        Preorder(n->left);
        Preorder(n->right);
    }
    else 
    {
        return;
    }
}
void Postorder(struct Node* n)
{
    if(n != NULL)
    {
        Postorder(n->left);
        Postorder(n->right);
        cout<<n->value<<" ";
    }
    else
    {
        return;
    }
}
void Inorder(struct Node* n)
{
    if(n != NULL)
    {
        Inorder(n->left);
        cout<<n->value<<" ";
        Inorder(n->right);
    }
    else
    {
        return;
    }
}
int main(void)
{
    Node* root =new Node();
    Node* n1 = new Node();
    Node* n2 = new Node();
    Node* n3 = new Node();
    Node* n4 = new Node();
    Node* n5 = new Node();
    Node* n6 = new Node();
    root->value = 0;
    n1->value = 1;
    n2->value = 2;
    n3->value = 3;
    n4->value = 4;
    n5->value = 5;
    n6->value = 6;

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    n5->left = NULL;
    n5->right = NULL;
    n6->left = NULL;
    n6->right = NULL;

    //cout<<"ds"<<endl;
    Preorder(root);
    printf("\n");

    Postorder(root);
    printf("\n");

    Inorder(root);
    printf("\n");
}