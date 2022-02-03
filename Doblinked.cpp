#include<iostream>
using namespace std;

struct node{
  int data;
  struct node *next;
  struct node *prev;
};

typedef struct node nd;
nd *head=nullptr;
nd *temp;
nd *hold;

nd * getNewNode(){
  nd *newNode=new nd;
  return newNode;
}

int totalNode(){
  int count=0;
  if(head==nullptr)
    return count;
  else{
    nd *temp=head;
    while(temp!=nullptr){
      count++;
      temp=temp->next;
    }
    return count;
  }
}

void insertatB(int data){
  nd *newNode=getNewNode();
  newNode->data=data;

if(head==NULL){

          head=newNode;
          newNode->next=NULL;
          newNode->prev=NULL;
          return;
    }
  newNode->next=head; 
  head->prev=newNode;
  newNode->prev=NULL;
  head=newNode;
}

void insertatE(int data){
 
  if(head==nullptr){
  insertatB(data);
  return;
  }
  nd *newNode=getNewNode();
  newNode->data=data;
  nd *temp=head;
  while(temp->next!=nullptr)
    temp=temp->next;
  newNode->next=nullptr;
  newNode->prev=temp;
  temp->next=newNode; 

 }

void insertatP(int data){
   int pos,total_node;
  cout<<"Enter the position you want to insert"<<endl;
  cin>>pos;
  total_node=totalNode();
  if(pos>total_node+1){
    cout<<"invalid insertion"<<endl;
    return;
  }
  if(pos==1){
    insertatB(data);
  }
  else if(pos==total_node+1){
    insertatE(data);
  }
  else{
    nd *newNode=getNewNode();
    newNode->data=data;
    nd *temp=head;
    for(int i=1;i<pos-1;i++){
      temp=temp->next;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next->prev=newNode;
    temp->next=newNode;
  }
}

void deleteatB(){ 
    nd *temp=head;
  if(head==nullptr)
    cout<<"List is empty!"<<endl;
  else if(head->next==nullptr){
    cout<<"The deleted item is "<<head->data<<endl;
    head=nullptr;
    delete temp;
  }
  else{
    cout<<"The deleted item is "<<head->data<<endl;
    head=head->next;
    head->prev=nullptr;
    delete temp;
  }
}


void deleteatE(){
  if(head==nullptr)
    deleteatB();
  else if(head->next==nullptr){
    deleteatB();
  }
  else{
    nd *temp=head;
    while (temp->next->next!=nullptr)
    {
      temp=temp->next;
    }
    cout<<"The deleted item is "<<temp->next->data<<endl;
    delete temp->next;
    temp->next=nullptr;
  }
}
 

void deleteatP(){
  int pos;
  cout<<"Enter the position you want to delete"<<endl;
  cin>>pos;
  if(pos>totalNode()){
    cout<<"invalid deletion"<<endl;
    return;
  }
  if(pos==1){
    deleteatB();
    return;
  }
  if(pos==totalNode()){
    deleteatE();
    return;
  }
  nd *temp=head;
  for(int i=1;i<pos-1;i++){
    temp=temp->next;
  }
  nd * hold;
  hold=temp->next;
  temp->next=temp->next->next;
  hold->next->prev=temp;
  cout<<"Deleted item is :"<<hold->data<<endl;
  delete hold;
}

void display(){
  if(head==nullptr)
    cout<<"The list is empty"<<endl;
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

int main(){
  int choice;
  do{
    cout<<"1.Insert at beginning\n2.Insert at end\n3.Insert at specific position\n4.Delete from beginning\n5.Delete from end\n6.Delete from specific position\n7.Traverse\n8.Exit"<<endl;
    cin>>choice;
    switch(choice){
      int data;
      case 1:
        cout<<"Enter data"<<endl;
        cin>>data;
        insertatB(data);
        break;
      case 2:
        cout<<"Enter data"<<endl;
        cin>>data;
        insertatE(data);
        break;
      case 3:
        cout<<"Enter data"<<endl;
        cin>>data;
        insertatP(data);
        break;
      case 4:
        deleteatB();
        break;
      case 5:
        deleteatE();
        break;
      case 6:
        deleteatP();
        break;
      case 7:
        display();
        break;
      case 8:
        exit(0);
        break;
      default:
        cout<<"Invalid choice"<<endl;
    }
    
  }while(true);

}