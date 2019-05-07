#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
struct node
{
	int key;
	struct node *left, *right;
};
struct node *newNode(int item)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node* insert(struct node* node, int value)
{
	if(node == NULL)
	{
		return newNode(value);
	}
	else 
	{
		if(node->key > value)
		{
			node->left = insert(node->left, value);
		}
		else 
		{
			node->right = insert(node->right, value);
		}
		return node;
	}
	
}
struct node* minValueNode(struct node* node)
{
	struct node *temp = node;
	while(temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp;
}
struct node* deleteNode(struct node* root, int key)
{
	// Leaf
	// One degree
	// Two degree
	if (root == NULL)
		return root;
	if (root->key < key)
	{
		root = deleteNode(root->right, key);
	}
	else if (root->key > key)
	{
		root = deleteNode(root->left, key);
	}
	else
	{
		if(root->left == NULL)
		{
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			struct node* temp = root->left;
			free(root);
			return temp;
		}

		struct node* tmp = minValueNode(root->right);
		int val = root->key;

		root->key = tmp->key;
		root->right = deleteNode(root->right, tmp->key);
		//free(tmp);
	}
	return root;
}
void Inorder(struct node* node)
{
	if(node != NULL)
	{
		Inorder(node->left);
		cout<<node->key<<" ";
		Inorder(node->right);
	}
}
int main(void)
{
	struct node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	Inorder(root);
	return 0;
}