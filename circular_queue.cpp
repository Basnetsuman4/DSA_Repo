//DSA lab 4
//Program to illustrate Circular Queue Implementation

#include <iostream>
using namespace std;

 
int cqueue[10];
int front = -1, rear = -1, Maxsize=5;

void insertitem(int item) {
   if ( (front == rear+1) % Maxsize) {
      cout<<"Queue Overflow \n";
      return;
   }
   if (front == -1) {
      front = 0;
      rear = 0;
   } else {
      if (rear == Maxsize - 1)
      rear = 0;
      else
      rear = rear + 1;
   }
   cqueue[rear] = item ;
}
void deleteitem() {
   if (front == -1) {
      cout<<"Queue Underflow\n";
      return ;
   }
   cout<<"Element deleted from queue is : "<<cqueue[front]<<endl;

   if (front == rear) {
      front = -1;
      rear = -1;
   } else {
      if (front == Maxsize - 1)
      front = 0;
      else
      front = front + 1;
   }
}
void traverseitem() {
   int a = front, b = rear;
   if (front == -1) {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements are :\n";
   if (a <= b) {
      while (a <= b){
         cout<<cqueue[a]<<" ";
         a++;
      }
   } else {
      while (a <= Maxsize - 1) {
         cout<<cqueue[a]<<" ";
         a++;
      }
      a = 0;
      while (a <= b) {
         cout<<cqueue[a]<<" ";
         a++;
      }
   }
   cout<<endl;
}
int main() {

   int ch, item;
   cout<<"1)Insert\n";
   cout<<"2)Delete\n";
   cout<<"3)Display\n";
   cout<<"4)Exit\n";
   do {
      cout<<"Enter choice : "<<endl;
      cin>>ch;
      switch(ch) {
         case 1:
         cout<<"Input for insertion: "<<endl;
         cin>>item;
         insertitem(item);
         break;

         case 2:
         deleteitem();
         break;

         case 3:
         traverseitem();
         break;

         case 4:
         cout<<"Exit\n";
         break;
         default: cout<<"Incorrect!\n";
      }
   } while(ch != 4);
   return 0;
} 