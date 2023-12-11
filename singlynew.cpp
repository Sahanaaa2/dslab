#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
struct Node *head=NULL;

void insertatbegin(int n)
{
    Node *new_node = new Node;
    new_node->data = n;
    new_node->next = head;
    head = new_node;
}


void insertatend(int n)
{
    Node *temp = head;                                                                  // Initialize temp with head to start traversal

    Node *new_node = new Node;
    new_node->data = n;
    new_node->next = NULL;                                                             // Set next of new node to NULL as it will be the last node

    if (head == NULL) {
        head = new_node;                                                               // If the list is empty, the new node becomes the head
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;                                                            // Move temp to the last node
    }

    temp->next = new_node;
} //
void insertatpos()
{
	
	int pos, value;
    cout << "Enter the position after which you want to insert: ";
    cin >> pos;

    Node *temp = head;

    if (temp == NULL) {
        cout << "List is empty. Cannot insert at specified position." << endl;
        return;
    }

    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position is out of range." << endl;
        return;
    }

    cout << "Enter the value to insert: ";
    cin >> value;

    Node *new_node = new Node;
    new_node->data = value;
    new_node->next = temp->next;
    temp->next = new_node;
    
    
}
void displaytree()
{
	
	cout<<"The elements are\n";
	Node *temp = head;                                                                // Initialize temp with head to start traversal

	    if (temp == NULL) {
	        cout << "The list is empty." << endl;
	        return;
    }

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;                                                           // Move temp to the next node
    }
    cout << endl;
}


void deleteatbegin()
{
	if(head!=NULL)
	{
		Node *temp=head;
		head=head->next;
		delete(temp);
	}
	else
	cout<<"The list is empty.";
}
void deleteatend()
{
 if (head == NULL) {
        cout << "List is empty. No nodes to delete." << endl;
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    Node *t1 = NULL;

    while (temp->next != NULL) {
        t1 = temp;
        temp = temp->next;
    }

    delete temp;
    t1->next = NULL;
}
void deleteatpos()
{
	int pos, value;
    cout << "Enter the position after which you want to delete: ";
    cin >> pos;
	
 if (head == NULL) {
        cout << "List is empty. No nodes to delete." << endl;
        return;
    }

    if (pos == 1) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *temp = head;
    Node *prev = NULL;
    int count = 1;

    while (temp != NULL && count < pos) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position is out of range." << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
}
void display1()
{
	int n,data;
	Node *temp;
	Node *head;
	Node *tem=head;
	cout<<"Enter the element to be deleted: "<<endl;
	cin>>n;
	if(head==NULL)
 {
 	cout<<"The list is empty"<<endl;
 }
     else
      cout<<temp->data<<"-->";
}
int main()
{
	int choice,n;
	do
    {
	cout<<"Operations on Singly Linked List: "<<endl;
	cout<<"1. Inserting a node at the beginning of the list."<<endl;
	cout<<"2. Inserting a node at the ending of the list."<<endl;
	cout<<"3. Inserting a node after the specified element."<<endl;
	cout<<"4. Displaying after insertion."<<endl;
	cout<<"5. Deleting a node at the beginning of the list."<<endl;
	cout<<"6. Deleting a node at the ending of the list."<<endl;
	cout<<"7. Deleting a node at after the specified element."<<endl;
	cout<<"8. Displaying after deletion."<<endl;
	cout<<"9. Exit"<<endl;
	cout<<"Enter your choice: "<<endl;
	cin>>choice;
      switch(choice)
       {
         case 1:

          cout<<"Insert the data of the new node: "<<endl;
          cin>>n;
          insertatbegin(n);
          displaytree();
          break;
         case 2:

          cout<<"Insert the data of the new node: "<<endl;
          cin>>n;
          insertatend(n);
          displaytree();
          break;
         case 3:
   	      insertatpos();
          displaytree();
          break;
         case 4:
         	displaytree();
         	break;
         case 5:
         	deleteatbegin();
         	displaytree();
         	break;
         case 6:
         	deleteatend();
         	displaytree();
         	break;
	     case 7:
         	deleteatpos();
         	displaytree();
         	break;
         case 8:
         	displaytree();
         	break;
         case 9:
   	      exit;
	    return(0);
        }
    }
 while(choice!=9);
}

