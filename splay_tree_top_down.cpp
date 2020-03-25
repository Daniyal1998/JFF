#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define MOD 1000000007
#define MAX 1000005
#define loop(i,a,b) for(long long int i=a;i<b;i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
typedef long long int ll;

using namespace std;
//using namespace boost::multiprecision;

class Node
{
	public:
		ll data;
		Node *left,*right;
};

Node *newNode(ll data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

Node *right_rotate(Node *root)
{
	Node *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	return temp;
}

Node *left_rotate(Node *root)
{
	Node *temp = root->right;
	root->right = temp->left;
	temp->left = root;
	return temp;
}

Node *splay(Node *root,ll data)
{
	if(root==NULL || root->data==data)
		return root;
	
	if(root->data > data)
	{
		if(root->left == NULL)
			return root;
		
		if(root->left->data > data)
		{
			root->left->left = splay(root->left->left,data);
			
			root = right_rotate(root);
		}
		else if(root->left->data < data)
		{
			root->left->right = splay(root->left->right,data);
			
			if(root->left->right != NULL)
				root->left = left_rotate(root->left);
		}
		
		return (root->left == NULL)? root:right_rotate(root);
	}
	else
	{
		if(root->right == NULL)
			return root;
			
		if(root->right->data < data)
		{
			root->right->right = splay(root->right->right,data);
			
			root = left_rotate(root);
		}
		else if(root->right->data > data)
		{
			root->right->left = splay(root->right->left,data);
			
			if(root->right->left != NULL)
				root->right = right_rotate(root->right);
		}
		
		return (root->right == NULL)? root:left_rotate(root);
	}
}

Node *insert(Node *root,ll data)
{
	if(root == NULL)
		return newNode(data);
	
	root = splay(root,data);
	
	if(root->data == data)
		return root;
	
	Node *temp = newNode(data);
	if(root->data < data)
	{
		temp->left = root;
		temp->right = root->right;
		root->right = NULL;
	}
	else
	{
		temp->right = root;
		temp->left = root->left;
		root->left = NULL;
	}
	
	return temp;
}

Node *erase(Node *root,ll data)
{
	if(root == NULL)
		return root;
	
	root = splay(root,data);
	if(root->data != data)
		return root;
	
	Node *temp;	
	if(root->left == NULL)
	{
		temp = root;
		root = root->right;
	}
	else
	{
		temp = root;
		
		root = splay(root->left,data);
		root->right = temp->right;
	}
	
	free(temp);
	return root;
	
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);





return 0;
}

