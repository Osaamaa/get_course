#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,x,n,*vec;
    printf("Enter the number of number: ");
    scanf("%d",&n);
    vec = (int*)malloc(n*4);
    for(i=0; i<n; ++i)
        scanf("%d",&vec[i]);
    do{
        printf("Add new number: ");
        scanf("%d",&x);
        vec = (int*) realloc (vec,(n+1)*4);
        vec[n] = x;
        n++;
    }while(x);
    for(i=0; i<n; ++i)
        printf("%d ",vec[i]);
}
/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;
class node{
public:
  int data;
  node* next;
  node(){
    data=0;
    next=NULL;
  }
};
class linkedList{
public:
 node* head;
 linkedList(){
   head=NULL;
 }
 	bool isempty()
	{
		return (head == NULL);
	}
 void insert(int NewValue){
   node* newNode=new node();
   newNode->data=NewValue;
 if (isempty())
 {
   newNode->next=NULL;
   head=newNode;
 }else
 {
   newNode->next=head;
   head=newNode;
 }
 }
 void desplay(){
    node* temp = head;
     while (temp != NULL)
     {
       cout<<temp->data<<endl;
       temp=temp->next;
     }
 }
 int count(){
   int count=0;
     node* temp=head;
     while (temp!=NULL)
     {
       count++;
       temp=temp->next;
   }   
 }
 bool isfound(int key){
     node* temp=head;
     bool found=false;
     while (temp!=NULL)
     {
       if (temp->data==key)
       {
         found=true;
         break;
       }
     }  
     return found;
 }
void insertbefore(int item, int newvalue)
	{
		if (isempty())
			insert(newvalue);

		if (isfound(item))
		{
			node* newnode = new node();
			newnode->data = newvalue;
			node* temp = head;
			while (temp != NULL && temp->next->data != item)
			{
				temp = temp->next;
			}
			newnode->next = temp->next;
			temp->next = newnode;
		}
		else
		{
			cout << "Sorry , Item Not Found \n";
		}
	}
    void append(int item){
    node* temp=head;
    node* newNode=new node();
    newNode->data=item;
    while (temp->next!=NULL)
    {
      temp = temp->next;
    }
    temp -> next = newNode;
    newNode->next=NULL;
  }
  void Delete(int item){
    if (isempty())
    {
      cout<<"list is empty \n";
      return;
    }else if (head->data==item)
    {
        node* del=head;
        head=head->next;
        delete del;
    }else
    {
      node* del=head;
      node* prev=NULL;
      while (del->data!=item)
      {
        prev=del;
        del=del->next;
      }
      prev->next=del->next;
      delete del;
    }
  }
};
int main(){
 linkedList x;
 int num;
 cout<<"enter the number : ";
 cin>>num;
 x.insert(num);
 cout<<"enter the number : ";
 cin>>num;
 x.insert(num);
 cout<<"enter the number : ";
 cin>>num;
 x.insert(num);
 x.desplay();
 int one,two;
 cout<<"enter the two numbers : ";
 cin>>one;
 x.append(one);
 x.desplay();
 cout<<"enter the number u want to delete : ";
 cin>>one;
 x.Delete(one);
 x.desplay();
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;
class node{
  public:
int data;
node* next;
node(){
  data=0;
  next=NULL;
}
};
class stack{
node* top;
public:
stack(){
  top=NULL;
}
bool isEmpty(){
  if (top==NULL)
  {
    return true;
  }else
  {
    return false;
  }
}
void push(int item){
  node* newnode=new node();
  newnode->data=item;
  if (isEmpty())
  {
    newnode->next=NULL;
    top=newnode;

  }else
  {
    newnode->next=top;
    top=newnode;
  }
}
int pop(){
  int value;
  node* del=top;
  value=top->data;
  top=top->next;
  delete del;
  return value;
}
void display(){
  node* temp=top;

    while (temp!=NULL)
    {
      cout<<temp->data<<" ";
      temp=temp->next;
    }
    cout<<endl;
}
};
int main(){
stack s;
int num;

  cout<<"enter number ";
  cin>>num;
  s.push(num);
  cout<<"enter number ";
  cin>>num;
  s.push(num);
  cout<<"enter number ";
  cin>>num;
  s.push(num);
  cout<<"enter number ";
  cin>>num;
  s.push(num);

s.display();
s.pop();
s.display();
s.pop();
s.display();
}