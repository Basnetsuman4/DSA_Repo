#include <iostream>
#include <conio.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node nd;
nd *head = nullptr;

nd *getNewNode()
{
    nd *newNode = new nd;
    return newNode;
}

void insertatB(int data)
{
    nd *newNode=getNewNode();
    newNode->data=data;
    newNode->next=head;
    head=newNode;
}

void insertatend(int newdata)
{
    nd *newNode=getNewNode();
    newNode->data=newdata;
    nd *temp = head;
     
    newNode->next = nullptr;

    if(head == nullptr)
    {
        head = newNode; 
         
    }

    else
    {
        while(temp->next !=nullptr){
        temp = temp->next;
        }
         temp->next = newNode;
    }
}

void deleteatB(){
  if(head==nullptr)
    cout<<"EMPTY  LIST!!!!!"<<endl;
  else{
    nd *temp=head;
    cout<<"The deleted item is "<<head->data<<endl;
    head=head->next;
    delete temp;
  }
}

void deleteatend()
{
    if(head == nullptr)
    {
        cout<<"List is empty"<<endl;
    }
    else if(head->next == nullptr)
    {
        cout<<"The deleted item is : "<<head->data<<endl;
        delete head;
        head = nullptr;
    }
    else
    {
        nd *temp = head;
        while(temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        cout<<"The deleted item is : "<<temp->next->data<<endl;
        delete temp ->next;
        temp->next = nullptr;
    }
}

void display(){
  if(head==nullptr)
    cout<<"List is empty"<<endl;
  else{
    nd *temp=head;
    cout<<"The items are:"<<endl;
    while(temp!=nullptr){
      cout<<temp->data<<"\t";
      temp=temp->next;
    }
    cout<<endl;
  }
}

int main()
{
     int choice;
  do{
    cout<<"1.Insert at beginning \n2.Delete at beginning      \n3. Insert at end  \n4.Delete at end  \n5.Display \n6.Exit"<<endl;
    cin>>choice;

    switch(choice)
    {
         int data;
      case 1:
        cout<<"Enter data"<<endl;
        cin>>data;
        insertatB(data);
        break;

        case 2:
        deleteatB();
        break;

        case 3:
         cout<<"Enter data"<<endl;
        cin>>data;
        insertatend(data);
        break;

        case 4:
        deleteatend();
        break;

        case 5:
        display();
        break;

        case 6:
        exit(0);
        break;
      default:
        cout<<"Invalid choice"<<endl;
    }
    }while(true);
}
