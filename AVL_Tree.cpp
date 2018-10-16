#include<bits/stdc++.h>
#define MOD 1000000007
#define loop(i,a,b) for(long long int i=a;i<b;i++)
#define loopm(i,a,b) for(long long int i=a;i>=b;i--)
#define sloop(i,a,b,step) for(long long int i=a;i<b;i+=step)
#define sloopm(i,a,b,step) for(long long int i=a;i>=b;i-=step)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;

using namespace std;


struct node
{
	int value;
	struct node *right,*left;
	int height;
};

int getHeight(struct node *N)
{
	if(N == NULL)
		return 0;
	return N->height;
}

struct node * newNode(int val)
{
	struct node * N = (struct node *)malloc(sizeof(struct node));
	N->value = val;
	N->right = NULL;
	N->left = NULL;
	N->height = 1;
	return N;
}

int getBalance(struct node *N)
{
	if(N==NULL)
	return 0;
	return getHeight(N->left)-getHeight(N->right);
}

struct node * leftRotate(struct node *x)
{
	struct node *y = x->right;
	struct node *temp = y->left;
	
	y->left = x;
	x->right = temp;
	
	x->height = max(getHeight(x->left),getHeight(x->right))+1;
	y->height = max(getHeight(y->left),getHeight(y->right))+1;
	
	return y;
	
}

struct node *rightRotate(struct node *x)
{
	struct node *y = x->left;
	struct node *temp = y->right;
	
	y->right = x;
	x->left = temp;
	
	x->height = max(getHeight(x->left),getHeight(x->right))+1;
	y->height = max(getHeight(y->left),getHeight(y->right))+1;
	
	return y;
}

struct node * insert(struct node *N,int val)
{
	if(N == NULL)
	return newNode(val);
	else if(val>N->value)
	N->right = insert(N->right,val);
	else if(val<N->value)
	N->left = insert(N->left,val);
	else
	return N;
	
	N->height = 1 + max(getHeight(N->left),getHeight(N->right));
	
	int balance = getBalance(N);
	
	if(balance > 1 && val < N->left->value)
	return rightRotate(N);
	
	if(balance < -1 && val > N->right->value)
	return leftRotate(N);
	
	if(balance > 1 && val > N->left->value) 
	{
		N->left = leftRotate(N->left);
		return rightRotate(N);
	}
	
	if(balance < -1 && val < N->right->value)
	{
		N->right = rightRotate(N->right);
		return leftRotate(N);
	}
	
	return N;
}

void inorder(struct node *N)
{
	if(N != NULL)
	{
		inorder(N->left);
		cout<<N->value<<" ";
		inorder(N->right);
	}
}






int main()
{
/*
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
*/
int n;
cout<<"Enter the number of elements in the Tree : ";
cin>>n;

int val;
struct node * root = NULL;
while(n--)
{
	cout<<"Enter the element : ";
	cin>>val;
	root = insert(root , val);
}

inorder(root);

return 0;
}

