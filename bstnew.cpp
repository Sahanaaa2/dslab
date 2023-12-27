#include <iostream>
using namespace std;

struct node {
	int key;
	struct node *left, *right;
};

struct node* newNode(int item)
{
	struct node* temp;
	temp	= new struct node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct node* insert(struct node* node, int key)
{
	if (node == NULL)
		return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}

struct node* search(struct node* root, int key)
{
	if (root == NULL || root->key == key)
		return root;

	if (root->key < key)
		return search(root->right, key);

	return search(root->left, key);
}

struct node *delet(struct node *root, int key) 
{
  if (root == NULL) return root;

  if (key < root->key)
    root->left = delet(root->left, key);
  else if (key > root->key)
    root->right = delet(root->right, key);
  else {
    if (root->left == NULL) 
	{
      struct node *temp = root->right;
      delete(root);
      return temp;
    } 
	else if (root->right == NULL) 
	{
      struct node *temp = root->left;
      delete(root);
      return temp;
    }
  }
}
struct node* display(struct node* root, int key)
{
	struct node *temp=root;
	if (root==NULL)
	{
		cout<<"Tree is empty";
	
	}
	else
	{
		cout<<temp->key<<" ";
		cout<<temp->left->key;
		cout<<temp->right->key;
	}
}

int main()
{
	struct node* root = NULL;
	int ch,n,key;
	 while(1)
    {
        cout  <<"\n1.INSERT\n2.SEARCH\n3.DELETE\n4.DISPLAYS\n5.EXIT\nEnter your Choice: \n";
        cin >> ch;
        switch(ch)
        {
        case 1:
            cout <<"Enter the element to Insert: \n";
            cin >> n;
            insert(root,n);
            display(root,key);
            break;
        case 2:
            cout <<"Enter the Element to Search:";
            cin >> n;
              if (search(root, key) == NULL)
		          cout << key << " not found" << endl;
	    		else
					cout << key << " found" << endl;

			  if (search(root, key) == NULL)
					cout << key << " not found" << endl;
			    else
					cout << key << " found" << endl;
					display(root,key);
					break;
        case 3:
        	cout<<"Enter the element to be deleted";
        	cin>>n;
        	delet(root,key);
            display(root,key);
            break;
        case 4:
        	display(root,key);
            break;
        case 5:
            	exit(0);
        default:
        		cout<<"Invalid choice!!! Try again.\n";
        }
    }  				
	       return 0;
}
